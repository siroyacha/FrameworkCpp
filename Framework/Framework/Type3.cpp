#include "Type3.h"
#include"Bullet.h"
#include"CursorManager.h"

Type3::Type3()
{
}

Type3::~Type3()
{
}

void Type3::Start()
{
	Dumy.Att = 20;
	Dumy.Hp = 10;
	Dumy.Lv = 1;
}

int Type3::Update(Transform& _Transfom)
{
	Dumy.Att = 20;
	Dumy.Hp = 10;
	Dumy.Lv = 1;
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
