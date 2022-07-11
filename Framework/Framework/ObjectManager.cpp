#include "ObjectManager.h"
#include"Bullet.h"
#include"Player.h"
#include"Enemy.h"
#include"CollisionManager.h"
#include"CursorManager.h"
#include"SceneManager.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr), pEnemy(nullptr)
{
	for (int i = 0; i < 128; ++i)
		pBullet[i] = nullptr;
}

ObjectManager::~ObjectManager()
{
	Release();
}

void ObjectManager::CreateObject(int _StateIndex)
{
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i] == nullptr)
		{
			pBullet[i] = new Bullet;
			pBullet[i]->Start();
			pBullet[i]->SetPosition(pEnemy->GetPosition().x,pEnemy->GetPosition().y);

			switch (_StateIndex)
			{
			case 0:
			{
				Vector3 Direction = pPlayer->GetPosition() - pBullet[i]->GetPosition();
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

void ObjectManager::Start()
{
	pPlayer = new Player;
	pPlayer->Start();
	pEnemy = new Enemy;
	pEnemy->Start();
	pEnemy->SetTarget(pPlayer);
}

void ObjectManager::Update()
{
	pPlayer->Update();
	if (pEnemy)
		pEnemy->Update();

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
				CursorManager::GetInstance()->SetCursorPosition(0.0f, 0.0f, (char*)"�浹�Դϴ�");				
				result =1;
			}
		}

		if (result == 1)
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
	
	if (pEnemy)
	{
		if (CollisionManager::RectCollision(
			pPlayer->GetTransform(),
			pEnemy->GetTransform()))
		{
			CursorManager::GetInstance()->SetCursorPosition(0.0f, 3.0f, (char*)"���� �浹�Դϴ�");

			delete pEnemy;
			pEnemy = nullptr;
		}
	}
	if (pEnemy == nullptr)
		SceneManager::GetInstance()->SetScene(SCENEID::EXIT);

}

void ObjectManager::Render()
{
	pPlayer->Render();
	if (pEnemy)
		pEnemy->Render();
	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
			pBullet[i]->Render();
	}
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
	delete pEnemy;
	pEnemy = nullptr;

	for (int i = 0; i < 128; ++i)
	{
		if (pBullet[i])
		{
			delete pBullet[i];
			pBullet[i] = nullptr;
		}
	}
}
