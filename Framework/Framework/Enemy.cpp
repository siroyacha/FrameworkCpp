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

	Value.Att = 1;
	Value.Hp = 10;
	Value.Lv = 1;
	Value.Def = 0;
	Value.Money = 100;
	Value.Exp = Value.Lv * 10;
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
		/*
		if (Count >= 10)
		{
			Count = 0;
			ObjectManager::GetInstance()->CreateObject(1);
		}
		else
			ObjectManager::GetInstance()->CreateObject(0);
		*/

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

int Enemy::DamegeControl(int _Att)
{
	Value.Hp = Value.Hp - (_Att - Value.Def);
	if (Value.Def > _Att)
		--Value.Hp;
	if (Value.Hp)
		return 1;
	else
		return 0;
}
