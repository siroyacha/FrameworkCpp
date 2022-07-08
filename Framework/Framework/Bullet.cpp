#include "Bullet.h"
#include"CursorManager.h"
Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);
	Time = GetTickCount64();
	Target = nullptr;
}

int Bullet::Update()
{
	switch (Index)
	{
	case 0:
		Info.Position += Info.Direction * 0.05f;
		if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
			Info.Position.y <= 0 || Info.Position.y >= 40)
		{
			return 1;
		}
		break;
	case 1:
	{
		Info.Direction = Target->GetPosition() - Info.Position;
		Info.Position += Info.Direction * 0.025f;
		if (Time + 5000 <= GetTickCount64())
		{
			Time = GetTickCount64();
			return 1;
		}
	}	
	break;
	}
		
	return 0;
}

void Bullet::Render()
{
	switch (Index)
	{
	case 0:
		CursorManager::GetInstance()->SetCursorPosition(Info.Position, (char*)"*");
		break;
	case 1:
		CursorManager::GetInstance()->SetCursorPosition(Info.Position, (char*)"*", 12);
		break;
	}
}

void Bullet::Release()
{
}
