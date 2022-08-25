#include "Mutant.h"
#include"CursorManager.h"
#include"Enemy.h"
#include"ObjectFactory.h"
#include"ObjectManager.h"
#include"MathManager.h"
#include"Bullet.h"

Mutant::Mutant()
{
}

Mutant::~Mutant()
{
}

Bridge* Mutant::Start(string _Key)
{
	return nullptr;
}

int Mutant::Update(Transform& _Transfom)
{
	/*
	Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
	if (_Transfom.Position.x > PlayerPosition.x)
	{
		Object* pBullet = ObjectFactory<Bullet>::CreateObject(_Transfom.Position);

		pBullet->SetTarget(ObjectManager::GetInstance()->GetPlayer());
		pBullet->SetDirection(
			MathManager::GetDirection(_Transfom.Position, PlayerPosition));

		ObjectManager::GetInstance()->AddObject(pBullet);
	}
	*/
	return 0;
}

void Mutant::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"Mutant",12);
}

void Mutant::Release()
{
}

Bridge* Mutant::Clone()
{
	return nullptr;
}
