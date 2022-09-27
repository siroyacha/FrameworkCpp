#include "Bullet.h"
#include"Player.h"
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

	Target = nullptr;

	BridgeList[BULLETID::BULLETID_TYPE_1] = new Type1;
	BridgeList[BULLETID::BULLETID_TYPE_2] = new Type2;
	BridgeList[BULLETID::BULLETID_TYPE_3] = new Type3;

	Time = GetTickCount64();

	Stat.Att = 10;
	Stat.Lv = 1;;

	Speed = 1.0f;

	return this;
}

int  Bullet::Update()
{
	Object* pPlayer= ObjectManager::GetInstance()->GetPlayer();
	Info.Direction = MathManager::GetDirection(pPlayer->GetPosition(), Vector3(10.0f, 10.0f));

	Info.Position += Info.Direction * (Speed * 0.5f);

	if (pBridge)
	{
		pBridge->Update(Info);
	}
	else
	{
		Time = GetTickCount64();

		srand(int(Time * GetTickCount64()));
		switch (((Player*)pPlayer)->GetBulletType())
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