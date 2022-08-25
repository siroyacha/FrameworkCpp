#include "Type2.h"
#include"Bullet.h"
#include"CursorManager.h"

Type2::Type2()
{
}

Type2::~Type2()
{
}

Bridge* Type2::Start(string _Key)
{
	return nullptr;
}

int Type2::Update(Transform& _Transfom)
{
	return 0;
}

void Type2::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"X", 13);
}

void Type2::Release()
{
}

Bridge* Type2::Clone()
{
	return nullptr;
}
