#include "Bullet.h"
#include "CursorManager.h"
#include "MathManager.h"
#include"ObjectManager.h"
#include"Bridge.h"
#include"Type1.h"
#include"Type2.h"
#include"Type3.h"

Bridge* Bullet::BridgeList[4];

Bullet::Bullet() : Speed(0), Time(0),pBridge(nullptr)
{
}

Bullet::~Bullet()
{
	Release();
}


Object* Bullet::Start(string _Key)
{
	Key = _Key;
	/*
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	Speed = 1.0f;
	*/

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

	BridgeList[BULLETID::BULLETID_TYPE_1] = new Type1;
	BridgeList[BULLETID::BULLETID_TYPE_2] = new Type2;
	BridgeList[BULLETID::BULLETID_TYPE_3] = new Type3;

	Time = GetTickCount64();
	
	Speed = 1.0f;

	return this;
}

int  Bullet::Update()
{
	Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
	Info.Direction = MathManager::GetDirection(PlayerPosition, Vector3(10.0f, 10.0f));

	Info.Position += Info.Direction * (Speed * 0.5f);

	if (pBridge)
	{
		pBridge->Update(Info);
	}
	else
	{
		Time = GetTickCount64();

		srand(int(Time * GetTickCount64()));
		switch (rand() % 3)
		{
		case BULLETID::BULLETID_TYPE_1:
			pBridge = BridgeList[BULLETID::BULLETID_TYPE_1]->Clone();
			break;
		case BULLETID::BULLETID_TYPE_2:
			pBridge = BridgeList[BULLETID::BULLETID_TYPE_2]->Clone();
			break;
			case BULLETID::BULLETID_TYPE_3:
			pBridge = BridgeList[BULLETID::BULLETID_TYPE_3]->Clone();
			break;
		}
		pBridge->Start();
		pBridge->SetObject(this);

	}

	if (Time + 5000 < GetTickCount64())
		return 2;

	if (Info.Position.x <= 0 || Info.Position.x >= 150 ||
		Info.Position.y <= 0 || Info.Position.y >= 40)
		return 1;
	
	return 0;
}

void Bullet::Render()
{
	if (pBridge)
		pBridge->Render();
}

void Bullet::Release()
{
	if (pBridge)
	{
		delete pBridge;
		pBridge = nullptr;
	}
}