#include "Type2.h"
#include"Bullet.h"
#include"CursorManager.h"

Type2::Type2()
{
}

Type2::~Type2()
{
}

void Type2::Start()
{
	Dumy.Att = 20;
	Dumy.Hp = 10;
	Dumy.Lv = 1;
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
