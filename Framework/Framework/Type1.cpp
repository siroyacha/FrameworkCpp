#include "Type1.h"
#include"Bullet.h"
#include"CursorManager.h"

Type1::Type1()
{
}

Type1::~Type1()
{
}

void Type1::Start()
{

}

int Type1::Update(Transform& _Transfom)
{
	return 0;
}

void Type1::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"X", 11);
}

void Type1::Release()
{
}

Bridge* Type1::Clone()
{
	return nullptr;
}
