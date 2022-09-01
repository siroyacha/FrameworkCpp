#include "Enemy.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "ObjectFactory.h"
#include"MathManager.h"
#include "Bullet.h"
#include"Bridge.h"
#include"Goolops.h"
#include"Mutant.h"
#include"Doomboo.h"
#include"PrototypeManager.h"

Bridge* Enemy::BridgeList[3];
Enemy::Enemy() : Time(0), pBridge(nullptr)
{
	for (int i = 0; i < 3; ++i)
		BridgeList[i] = nullptr;
}

Enemy::~Enemy()
{
}

Object* Enemy::Start(string _Key)
{
	Key = _Key;
	/*
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);
	Info.Direction = Vector3(-1.0f, 0.0f);
	*/

	//Speed = 0.2f;
	
	BridgeList[ENEMYID::ENEMYID_GOOLOPS] = new Goolops;
	BridgeList[ENEMYID::ENEMYID_MUTANT] = new Mutant;
	BridgeList[ENEMYID::ENEMYID_DOOMBOO] = new Doomboo;
	Time = GetTickCount64() - 7000;
	pBridge = nullptr;
	return this;
}

int Enemy::Update()
{
	Info.Position.x -= 1;
	if (pBridge)
		pBridge->Update(Info);
	else
	{
		if (Time + 7000 < GetTickCount64())
		{
			//Time = GetTickCount64();

			srand(int(Time * GetTickCount64()));

			switch (rand()%3)
			{
			case ENEMYID::ENEMYID_GOOLOPS:
				pBridge = BridgeList[ENEMYID::ENEMYID_GOOLOPS]->Clone();
					break;
			case ENEMYID::ENEMYID_MUTANT:
				pBridge = BridgeList[ENEMYID::ENEMYID_MUTANT]->Clone();
					break;
			case ENEMYID::ENEMYID_DOOMBOO:
				pBridge = BridgeList[ENEMYID::ENEMYID_DOOMBOO]->Clone();
					break;
			}
			pBridge->Start();
			pBridge->SetObject(this);
		}
	}

	/*
	if (Time + 200 < GetTickCount64())
	{
		Vector3 PlayerPosition = PrototypeManager::GetInstance()->FindObject("Player")->Clone()->GetPosition();
		if (Info.Position.x>PlayerPosition.x)
		{
			Object* pBullet = PrototypeManager::GetInstance()->FindObject("Bullet")->Clone();

			if (pBullet != nullptr)
			{
				pBullet->SetTarget(PrototypeManager::GetInstance()->FindObject("Player")->Clone());
				pBullet->SetDirection(
					MathManager::GetDirection(Info.Position, PlayerPosition));

				ObjectManager::GetInstance()->AddObject(pBullet);
			}
			Time = GetTickCount64();
		}
	}

	Info.Position += Info.Direction * Speed;

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40)
		return 1;
	*/


	if (Info.Position.x <= 1)
		return 1;

	return 0;
}

void Enemy::Render()
{
	if (pBridge)
		pBridge->Render();
	//CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"@");
}

void Enemy::Release()
{
	if (pBridge)
	{
		delete pBridge;
		pBridge = nullptr;
	}
}