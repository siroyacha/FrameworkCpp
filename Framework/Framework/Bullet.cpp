#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include"Bridge.h"
#include"Type1.h"
#include"Type2.h"
#include"Type3.h"

Bullet::Bullet() : Speed(0), Time(0),pBBridge(nullptr)
{
}

Bullet::~Bullet()
{
	Release();
}


Object* Bullet::Start(string _Key)
{
	Key = _Key;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Speed = 1.0f;

	Target = nullptr;

	/*
	switch (rand() % 4)
	{
	case 0: // 
		Info.Position = Vector3(float(rand() % 148), 0.0f);
		break;
	case 1: // 
		Info.Position = Vector3(float(rand() % 148), 39.0f);
		break;

	case 2: // 
		Info.Position = Vector3(0.0f, float(rand() % 40));
		break;
	case 3: // 
		Info.Position = Vector3(148.0f, float(rand() % 40));
		break;
	}
	*/

	//Info.Direction = MathManager::GetDirection(Info.Position, Target->GetPosition());

	Time = GetTickCount64();

	return this;
}

int  Bullet::Update()
{
	if (pBBridge)
	{
		pBBridge->Update(Info);
		Time = GetTickCount64();
	}
	else
	{
		Time = GetTickCount64();

		srand(int(Time * GetTickCount64()));
		/*
		switch (rand() % 3)
		{
		case 0:
			pBBridge = new Type1;
			break;
		case 1:
			pBBridge = new Type2;
			break;
		case 2:
			pBBridge = new Type3;
			break;
		}
		*/
		pBBridge->Start();
		pBBridge->SetObject(this);

	}
	Info.Position += Info.Direction * (Speed * 0.5f);

	if (Time + 5000 < GetTickCount64())
		return 2;

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40)
		return 1;
	
	return 0;
}

void Bullet::Render()
{
	if (pBBridge)
		pBBridge->Render();
	//CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*", 12);
}

void Bullet::Release()
{
	if (pBBridge)
	{
		delete pBBridge;
		pBBridge = nullptr;
	}
}