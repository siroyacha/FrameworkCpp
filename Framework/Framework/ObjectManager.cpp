#include "ObjectManager.h"
#include"Bullet.h"
#include"Player.h"
#include"Enemy.h"
#include"Item.h"
#include"CollisionManager.h"
#include"CursorManager.h"
#include"SceneManager.h"
#include"MathManager.h"
#include"ObjectFactory.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr)
{
	for (int i = 0; i < 32; ++i)
		pEnemy[i] = nullptr;
	for (int i = 0; i < 128; ++i)
		pEBullet[i] = nullptr;
	for (int i = 0; i < 128; ++i)
		pPBullet[i] = nullptr;
	for (int i = 0; i < 128; ++i)
		pItem[i] = nullptr;
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::CreateObject(int _StateIndex)
{
	for (int j = 0; j < 32; ++j)
	{
		if (pEnemy[j])
		{
			for (int i = 0; i < 128; ++i)
			{
				if (pEBullet[i] == nullptr)
				{
					pEBullet[i] = ObjectFactory::CreateBullet(pEnemy[j]->GetPosition());

					if (pEBullet[i])
					{
						switch (_StateIndex)
						{
						case 0:
						{
							Vector3 Direction = MathManager::GetDirection(pEBullet[i]->GetPosition(), pPlayer->GetPosition());
							pEBullet[i]->SetDirection(Direction);
							((Bullet*)pEBullet[i])->SetIndex(_StateIndex);
						}
						break;
						case 1:
							pEBullet[i]->SetTarget(pPlayer);
							((Bullet*)pEBullet[i])->SetIndex(_StateIndex);
							break;
						}
					}
					break;
				}
			}
		}
	}
}

void ObjectManager::CreatePlayerObject(int _StateIndex, int dwKey, float _X_Shift, float _Y_Shift)
{
	for (int i = 0; i < 128; ++i)
	{
		if (pPBullet[i] == nullptr)
		{
			pPBullet[i] = ObjectFactory::CreateBullet(pPlayer->GetPosition());

			switch (dwKey)
			{
			case 1:
			{
				Vector3 Direction = MathManager::GetDirection(pPBullet[i]->GetPosition(),
					Vector3(pPBullet[i]->GetPosition().x, pPBullet[i]->GetPosition().y + (10.0f * _Y_Shift)));
				pPBullet[i]->SetDirection(Direction);
				((Bullet*)pPBullet[i])->SetIndex(_StateIndex);
			}
			break;
			case 2:
			{
				Vector3 Direction = MathManager::GetDirection(pPBullet[i]->GetPosition(),
					Vector3(pPBullet[i]->GetPosition().x, pPBullet[i]->GetPosition().y - (10.0f * _Y_Shift)));
				pPBullet[i]->SetDirection(Direction);
				((Bullet*)pPBullet[i])->SetIndex(_StateIndex);
			}
			break;
			case 4:
			{
				Vector3 Direction = MathManager::GetDirection(pPBullet[i]->GetPosition(),
					Vector3(pPBullet[i]->GetPosition().x + (10.0f * _X_Shift), pPBullet[i]->GetPosition().y));
				pPBullet[i]->SetDirection(Direction); 
				((Bullet*)pPBullet[i])->SetIndex(_StateIndex);
			}
			break;
			case 8:
			{
				Vector3 Direction = MathManager::GetDirection(pPBullet[i]->GetPosition(),
					Vector3(pPBullet[i]->GetPosition().x - (10.0f * _X_Shift), pPBullet[i]->GetPosition().y));
				pPBullet[i]->SetDirection(Direction);
				((Bullet*)pPBullet[i])->SetIndex(_StateIndex);
			}
			break;
			case 5:
			{
				Vector3 Direction = MathManager::GetDirection(pPBullet[i]->GetPosition(),
					Vector3(pPBullet[i]->GetPosition().x + (10.0f * _X_Shift), pPBullet[i]->GetPosition().y +( 5.0f * _Y_Shift)));
				pPBullet[i]->SetDirection(Direction);
				((Bullet*)pPBullet[i])->SetIndex(_StateIndex);
			}
			break;
			case 6:
			{
				Vector3 Direction = MathManager::GetDirection(pPBullet[i]->GetPosition(),
					Vector3(pPBullet[i]->GetPosition().x + (10.0f * _X_Shift), pPBullet[i]->GetPosition().y - (5.0f * _Y_Shift)));
				pPBullet[i]->SetDirection(Direction);
				((Bullet*)pPBullet[i])->SetIndex(_StateIndex);
			}
			break;
			case 9:
			{
				Vector3 Direction = MathManager::GetDirection(pPBullet[i]->GetPosition(),
					Vector3(pPBullet[i]->GetPosition().x - (10.0f * _X_Shift), pPBullet[i]->GetPosition().y + (5.0f * _Y_Shift)));
				pPBullet[i]->SetDirection(Direction);
				((Bullet*)pPBullet[i])->SetIndex(_StateIndex);
			}
			break;
			case 10:
			{
				Vector3 Direction = MathManager::GetDirection(pPBullet[i]->GetPosition(),
					Vector3(pPBullet[i]->GetPosition().x - (10.0f * _X_Shift), pPBullet[i]->GetPosition().y - (5.0f * _Y_Shift)));
				pPBullet[i]->SetDirection(Direction);
				((Bullet*)pPBullet[i])->SetIndex(_StateIndex);
			}
			break;
			}
			break;
		}
	}	
}

void ObjectManager::Start()
{
	pPlayer = ObjectFactory::CreatePlayer();

	if (pEnemy[0] == nullptr)
	{
		pEnemy[0] = ObjectFactory::CreateEnemy();
		pEnemy[0]->SetTarget(pPlayer);
	}
}

void ObjectManager::Update()
{
	pPlayer->Update();
	for (int i = 1; i < 32; i++)
	{
		if (pEnemy[i] == nullptr)
		{
			if (EnemyTimer + 2000 < GetTickCount64())
			{
				EnemyTimer = GetTickCount64();

				pEnemy[i] = ObjectFactory::CreateEnemy();
				pEnemy[i]->SetTarget(pPlayer);
			}
		}
	}
	int Itemresult = 0;
	int ItemCounter = 0;
	Vector3 ItemPosition;
	for (int i = 0; i < 32; i++)
	{
		if (pEnemy[i])
			pEnemy[i]->Update();
		
		if (pEnemy[i])
		{
			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(),
				pEnemy[i]->GetTransform()))
			{
				CursorManager::GetInstance()->WriteBuffer(60.0f, 20.0f, (char*)"적과 충돌입니다");

				if (pPlayer->DamegeControl(pEnemy[i]->GetDamege()) == 0)
					SceneManager::GetInstance()->SetScene(SCENEID::GAMEOVER);

				delete pEnemy[i];
				pEnemy[i] = nullptr;
			}
		}
		/*
		if (pEnemy[i] == nullptr)
			SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
		*/
	}

	int result = 0;
	for (int i = 0; i < 128; ++i)
	{
		if (pEBullet[i])
		{
			result = pEBullet[i]->Update();
			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(),
				pEBullet[i]->GetTransform()))
			{
				CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"충돌입니다");				
				result =1;
			}
		}

		if (result == 1)
		{
			delete pEBullet[i];
			pEBullet[i] = nullptr;
		}
	}
	int PBresult = 0;
	for (int i = 0; i < 128; ++i)
	{
		if (pPBullet[i])
		{
			PBresult = pPBullet[i]->Update();
					
			for (int j = 0; j < 32; ++j)
			{
				if (pEnemy[j])
				{
					if (CollisionManager::RectCollision(
						pEnemy[j]->GetTransform(),
						pPBullet[i]->GetTransform()))
					{
						PBresult = 1;
						if (pEnemy[j]->DamegeControl(pPBullet[i]->GetDamege()) == 0)
						{
							ItemCounter = 1;
							ItemPosition = pEnemy[j]->GetPosition();
							pPlayer->SetMoney(pEnemy[j]->GetMoney());
							pPlayer->SetExp(pEnemy[j]->GetExp());

							delete pEnemy[j];
							pEnemy[j] = nullptr;
						}
					}
				}
			}
		}

		if (PBresult == 1)
		{
			delete pPBullet[i];
			pPBullet[i] = nullptr;
		}
	}

	for (int j = 0; j < 128; ++j)
	{
		if (ItemCounter == 1)
		{
			if (pItem[j] == nullptr)
			{
				pItem[j] = ObjectFactory::CreateItem(ItemPosition);
				ItemCounter = 0;
			}
		}
		if (pItem[j])
			Itemresult = pItem[j]->Update();
		if (Itemresult == 1)
		{
			delete pItem[j];
			pItem[j] = nullptr;
		}
	}
}

void ObjectManager::Render()
{
	pPlayer->Render();

	for (int i = 0; i < 128; ++i)
	{
		if (pPBullet[i])
			pPBullet[i]->Render();
	}

	for (int i = 0; i < 128; ++i)
	{
		if (pEBullet[i])
			pEBullet[i]->Render();
	}

	for (int i = 0; i < 32; i++)
	{
		if (pEnemy[i])
			pEnemy[i]->Render();
	}

	for (int i = 0; i < 128; ++i)
	{
		if (pItem[i])
			pItem[i]->Render();
	}
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;

	for (int i = 0; i < 32; i++)
	{
		if (pEnemy[i])
		{
			delete pEnemy[i];
			pEnemy[i] = nullptr;
		}
	}
	for (int i = 0; i < 128; ++i)
	{
		if (pPBullet[i])
		{
			delete pPBullet[i];
			pPBullet[i] = nullptr;
		}
	}
	for (int i = 0; i < 128; ++i)
	{
		if (pEBullet[i])
		{
			delete pEBullet[i];
			pEBullet[i] = nullptr;
		}
	}
	for (int i = 0; i < 128; ++i)
	{
		if (pItem[i])
		{
			delete pItem[i];
			pItem[i] = nullptr;
		}
	}
}
