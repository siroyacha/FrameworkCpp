#include "Enemy.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "ObjectFactory.h"
#include"MathManager.h"
#include "Bullet.h"

Enemy::Enemy() : Count(0),Time(0)
{
}

Enemy::~Enemy()
{
}

void Enemy::Start()
{
	Key = "Enemy";

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);
	Info.Direction = Vector3(-1.0f, 0.0f);

	Target = nullptr;
	Speed = 0.2f;
	Count = 0;
	Time = GetTickCount64() - 7000;
}

int Enemy::Update()
{
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

	return 0;
}

void Enemy::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"@");
}

void Enemy::Release()
{

}