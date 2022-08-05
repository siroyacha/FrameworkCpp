#include "Type1.h"
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

int Type1::Update()
{
	return 0;
}

void Type1::Render()
{
}

void Type1::Release()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"*");
}

int Type1::DamegeControl(int _Att)
{
	return 0;
}
