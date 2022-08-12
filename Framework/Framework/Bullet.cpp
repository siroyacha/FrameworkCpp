#include "Bullet.h"
#include"CursorManager.h"
#include"MathManager.h"
#include"Type1.h"

Bullet::Bullet():Index(0)
{
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Time = GetTickCount64();
	Target = nullptr;
	for (int i = 0; i < 5; i++)
	{
		Type[i].Type = i;
		Type[i].Att = 10;
		Type[i].LV = 1;
		Type[i].Speed = 1.0f;
	}
}

int Bullet::Update()
{
	
	for (int i = 0; i < 5; i++)
	{
		Type[i].Att = 10 + (5 * Type[i].LV);
	}
	switch (Index)
	{
	case 0:
		Info.Position += Info.Direction * Type[Index].Speed;
		Value.Att = Type[Index].Att;
		Value.Lv = Type[Index].LV;
		if (Time + 5000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			return 1;
		}
		break;
	case 1:
		Info.Position += Info.Direction * Type[Index].Speed;
		Value.Att = Type[Index].Att;
		if (Value.Lv == 0)
			Value.Lv = Type[Index].LV;

		if (Time + 5000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			return 1;
		}
		break;	
	case 2:
		Value.Att = Type[Index].Att;
		Value.Lv = Type[Index].LV;
		Info.Position += Info.Direction * Type[Index].Speed;
		if (Time + 5000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			return 1;
		}
		break;
	case 3:
		Value.Lv = Type[Index].LV;
		Value.Att = Type[Index].Att;
		Info.Position += Info.Direction * Type[Index].Speed;
		if (Time + 5000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			return 1;
		}
		break;
	case 4:
		Value.Lv = Type[Index].LV;
		Value.Att = Type[Index].Att;
		Info.Position += Info.Direction * Type[Index].Speed;
		if (Time + 5000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			return 1;
		}
		break;
	}

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40)
	{
		return 1;
	}
	return 0;
}

void Bullet::Render()
{
	switch (Index)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*");
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 12);
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 10);
		break;
	case 3:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*",6);
		break;
	case 4:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 7);
		break;
	}
}

void Bullet::Release()
{
}

int Bullet::DamegeControl(int _Index)
{
	return 0;
}


void Bullet::BulletSeting(int _Att)
{
	Value.Att += _Att;
}

int Bullet::GetBulletDamage()
{
	return Value.Att;
}

void Bullet::BulletLVUP(int _LV, int _Index)
{
	Type[_Index].LV = _LV;

}
