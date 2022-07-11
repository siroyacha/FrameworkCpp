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
}

int Enemy::Update()
{
	if (Time + 250 < GetTickCount64())
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
		Info.Position += Info.Direction * 0.025f;
	}
	 
	return 0;
}


void Enemy::Render()
{
	CursorManager::GetInstance()->SetCursorPosition(Info.Position, (char*)"£À");
}

void Enemy::Release()
{

}