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
	Texture[0] = (char*)"x";
	Color = 11;
	Dumy.Att = 20;
	Dumy.Hp = 10;
	Dumy.Lv = 1;
}

int Type1::Update(Transform& _Transfom)
{
	return 0;
}

void Type1::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), Texture[0], Color);
}

void Type1::Release()
{
}
