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

Enemy::Enemy() : Time(0), pBridge(nullptr)
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	if (pBridge)
		pBridge->Start();
	Key = "Enemy";
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);
	Info.Direction = Vector3(-1.0f, 0.0f);

	//Speed = 0.2f;
	
	Time = GetTickCount64() - 7000;
}

int Enemy::Update()
{
	if (pBridge)
	{
		if (Time + 500 < GetTickCount64())
		{
			pBridge->Update(Info);
			Time = GetTickCount64();
		}
	}
	else
	{
		if (Time + 7000 < GetTickCount64())
		{
			Time = GetTickCount64();

			srand(int(Time * GetTickCount64()));

			switch (rand()%3)
			{
			case 0:
				pBridge = new Goolops;
					break;
			case 1:
				pBridge = new Mutant;
					break;
			case 2:
				pBridge = new Doomboo;
					break;
			}
			pBridge->Start();
			pBridge->SetObject(this);
		}
	}
	/*
	if (Time + 7000 < GetTickCount64())
	{
		Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
		if (Info.Position.x>PlayerPosition.x)
		{
			Object* pBullet = ObjectFactory<Bullet>::CreateObject(Info.Position);

			pBullet->SetTarget(ObjectManager::GetInstance()->GetPlayer());
			pBullet->SetDirection(
				MathManager::GetDirection(Info.Position, PlayerPosition));

			ObjectManager::GetInstance()->AddObject(pBullet);

			Time = GetTickCount64();
		}
	}

	Info.Position += Info.Direction * Speed;

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40)
		return 1;
	*/

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