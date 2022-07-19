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
		pBullet[i] = nullptr;
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
				if (pBullet[i] == nullptr)
				{
					pBullet[i] = ObjectFactory::CreateBullet(Vector3(pEnemy[j]->GetPosition().x, pEnemy[j]->GetPosition().y));

					switch (_StateIndex)
					{
					case 0:
					{
						Vector3 Direction = MathManager::GetDirection(pBullet[i]->GetPosition(), pPlayer->GetPosition());
						pBullet[i]->SetDirection(Direction);
						((Bullet*)pBullet[i])->SetIndex(_StateIndex);
					}
					break;
					case 1:
						pBullet[i]->SetTarget(pPlayer);
						((Bullet*)pBullet[i])->SetIndex(_StateIndex);
						break;
					}
					break;
				}
			}
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
				CursorManager::GetInstance()->WriteBuffer(0.0f, 3.0f, (char*)"적과 충돌입니다");

				for (int j = 0; j < 128; ++j)
				{
					if (pItem[j] == nullptr)
					{
						pItem[j] = ObjectFactory::CreateItem(Vector3(pEnemy[i]->GetPosition().x, pEnemy[i]->GetPosition().y));

					}
					Itemresult = pItem[j]->Update();
					if (Itemresult == 1)
					{
						delete pItem[i];
						pItem[i] = nullptr;
					}
				}
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
		if (pBullet[i])
		{
			result = pBullet[i]->Update();
			if (CollisionManager::RectCollision(
				pPlayer->GetTransform(),
				pBullet[i]->GetTransform()))
			{
				CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"충돌입니다");				
				result =1;
			}
		}

		if (result == 1)
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
	

}

void ObjectManager::Render()
{
	pPlayer->Render();

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
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
		if (pBullet[i])
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
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
