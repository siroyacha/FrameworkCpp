#include "EType1.h"
#include"CursorManager.h"

EType1::EType1()
{
}

EType1::~EType1()
{
}

void EType1::Start()
{
	Value.Att = 10;
}

int EType1::Update()
{
	return 0;
}

void EType1::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"£À",12);
}

void EType1::Release()
{
}

int EType1::DamegeControl(int _Att)
{
	return 0;
}
