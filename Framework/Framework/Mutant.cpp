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

void Mutant::Start()
{

}

int Mutant::Update(Transform& _Transfom)
{
	Dumy.Att = 20;
	Dumy.Hp = 10;
	Dumy.Def = 0;
	Dumy.Score = 10;
	Dumy.Exp = 10;
	Dumy.Lv = 1;

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