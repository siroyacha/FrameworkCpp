#include "Enemy.h"
#include"EType1.h"
#include"ObjectManager.h"
#include"CursorManager.h"
#include"StartManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	Key = "Enemy";

	Info.Position = Vector3(20.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	
	Target = nullptr;
	Count = 0;
	Time = GetTickCount64();

	SpownPoint_X = (rand() % 120) + 20;
	SpownPoint_Y = (rand() % 60);

	Value.Lv = (StartManager::GetInstance()->GetStageLv() / 3) + 1;
	Value.Att = Value.Lv * 15;
	Value.Hp = Value.Lv * 10;
	Value.Def = Value.Lv / 3;
	Value.Money = Value.Lv * 50 + 50;
	Value.Exp = Value.Lv * 10;	
	Info.Position = Vector3(SpownPoint_X, SpownPoint_Y);

	for (int i = 0; i < 5; i++)
	{
		Type[i].Type = i;
		Type[i].Att = 10;
		Type[i].LV = 1;
		Type[i].Speed = 1.0f;
	}

}

int Enemy::Update()
{
	if (Time + 500 < GetTickCount64())
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
	SpownPoint_X = (rand() % 120) + 20;
	SpownPoint_Y = (rand() % 40) + 10;

	return 0;
}


void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"£À");
	/*
	for (int i = 0; i < 5; i++)
	{
		switch (Type[i].Type)
		{
		case 0:
			CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"£À");
			break;															
		case 1:																
			CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"£À", 4);
			break;															
		case 2:																
			CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"£À", 8);
			break;															
		case 3:																
			CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"£À", 13);
			break;															
		case 4:																
			CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"£À", 11);
			break;
		}
	}
	*/
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
