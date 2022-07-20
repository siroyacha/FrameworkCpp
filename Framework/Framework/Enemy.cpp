#include "Enemy.h"
#include"ObjectManager.h"
#include"CursorManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	Info.Position = Vector3(20.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	
	Target = nullptr;
	Count = 0;
	Time = GetTickCount64();

	SpownPoint = rand() % 4;

	switch (SpownPoint)
	{
	case 0:
		Info.Position = Vector3(20.0f, 10.0f);
		break;
	case 1:
		Info.Position = Vector3(130.0f, 10.0f);
		break;
	case 2:
		Info.Position = Vector3(20.0f, 30.0f);
		break;
	case 3:
		Info.Position = Vector3(130.0f, 30.0f);
		break;
	}
}

int Enemy::Update()
{
	if (Time + 1500 < GetTickCount64())
	{
		Count++;

		if (Count >= 10)
		{
			Count = 0;
			ObjectManager::GetInstance()->CreateObject(1);
		}
		else
			ObjectManager::GetInstance()->CreateObject(0);

		Time = GetTickCount64();

		Info.Direction = Target->GetPosition() - Info.Position;
	}
		Info.Position += Info.Direction * 0.025f;
	srand(Time);
	SpownPoint = rand() % 4;

	return 0;
}


void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"£À");
}

void Enemy::Release()
{

}