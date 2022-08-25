#include "Type3.h"
#include"Bullet.h"
#include"CursorManager.h"

Type3::Type3()
{
}

Type3::~Type3()
{
}

Bridge* Type3::Start(string _Key)
{
	return nullptr;
}

int Type3::Update(Transform& _Transfom)
{
	return 0;
}

void Type3::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"X", 9);
}

void Type3::Release()
{
}

Bridge* Type3::Clone()
{
	return nullptr;
}
