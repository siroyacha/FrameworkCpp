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
	Speed = 0.5f;

	Stat.Hp = 10;
	Stat.Att = 10;
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
	pPlayer = ObjectManager::GetInstance()->GetPlayer();
	PlayerPosition = pPlayer->GetPosition();
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

	if (CollisionManager::RectCollision(pPlayer->GetTransform(), Info))
	{
		pPlayer->Hit(this);
		return 1;
	}

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40)
		return 1;
	if (Stat.Hp <= 0)
		return 1;

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