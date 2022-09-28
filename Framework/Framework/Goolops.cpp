#include "Goolops.h"
#include"CursorManager.h"
#include"Enemy.h"

Goolops::Goolops()
{
}

Goolops::~Goolops()
{
}

void Goolops::Start()
{
	Dumy.Att = 20;
	Dumy.Hp = 10;
	Dumy.Def = 0;
	Dumy.Score = 10;
	Dumy.Exp = 10;
	Dumy.Lv = 1;
}

int Goolops::Update(Transform& _Transfom)
{
	return 0;
}

void Goolops::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"Goolops",10);
}

void Goolops::Release()
{
}
