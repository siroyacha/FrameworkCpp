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
#include"EType1.h"
#include"PrototypeManager.h"
#include"CollisionManager.h"

Bridge* Enemy::BridgeList[ENEMYID_MAX];
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
	Speed = 0.5f;

	Stat.Hp = 10;
	Stat.Def = 0;
	Stat.MaxHP = 100;
	Stat.Lv = 1;
	Stat.Exp = 0;

	BridgeList[ENEMYID::ENEMYID_GOOLOPS] = new Goolops;
	BridgeList[ENEMYID::ENEMYID_MUTANT] = new Mutant;
	BridgeList[ENEMYID::ENEMYID_DOOMBOO] = new Doomboo;
	BridgeList[ENEMYID::ENEMYID_ETYPE1] = new EType1;
	Time = GetTickCount64() - 7000;
	pBridge = nullptr;
	return this;
}

int Enemy::Update()
{
	Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
	Info.Direction = MathManager::GetDirection(Info.Position, PlayerPosition);

	Info.Position += Info.Direction * Speed;
	if (pBridge)
	{
		pBridge->Update(Info);
	}
	else
	{
		if (Time + 700 < GetTickCount64())
		{
			Time = GetTickCount64();

			srand(int(Time * GetTickCount64()));
			int test = rand() % 4;
			switch (test)
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
			case ENEMYID::ENEMYID_ETYPE1:
				pBridge = BridgeList[ENEMYID::ENEMYID_ETYPE1]->Clone();
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
	if (Stat.Hp <= 0)
		return 1;

	if (Info.Position.x <= 1)
		return 1;

	if (Time + 5000 < GetTickCount64())
		return 2;

	return 0;
}

void Enemy::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Enemy::Release()
{
	if (pBridge)
	{
		delete pBridge;
		pBridge = nullptr;
	}
}