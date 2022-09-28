#include "Doomboo.h"
#include"CursorManager.h"
#include"Enemy.h"

Doomboo::Doomboo()
{
}

Doomboo::~Doomboo()
{
}

void Doomboo::Start()
{
	Dumy.Att = 20;
	Dumy.Hp = 10;
	Dumy.Def = 0;
	Dumy.Score = 10;
	Dumy.Exp = 10;
	Dumy.Lv = 1;
}

int Doomboo::Update(Transform& _Transfom)
{
	((Enemy*)pObject)->SetStat(Dumy);
	return 0;
}

void Doomboo::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"D",13);
}

void Doomboo::Release()
{
}
