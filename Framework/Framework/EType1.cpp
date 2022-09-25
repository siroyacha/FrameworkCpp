#include "EType1.h"
#include"CursorManager.h"
#include"ObjectManager.h"
#include"PrototypeManager.h"
#include"Enemy.h"

EType1::EType1()
{
}

EType1::~EType1()
{
}


void EType1::Start()
{

}

int EType1::Update(Transform& _Transfom)
{
	return 0;
}

void EType1::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"EType1", 10);
}

void EType1::Release()
{
}
