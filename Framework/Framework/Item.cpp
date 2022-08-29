#include "Item.h"
#include"CursorManager.h"
#include"MathManager.h"

Item::Item():Index(0)
{
}

Item::~Item()
{
}
/*
void Item::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Time = GetTickCount64();
	srand(Time);
	Index = rand() % 3;
}
*/

Object* Item::Start(string _Key)
{
	return nullptr;
}

int Item::Update()
{
	if (Time + 10000 <= GetTickCount64())
	{
		Time = GetTickCount64();
		return 0;
	}
	switch (Index)
	{
	case 0:
		return 1;
		break;
	case 1:
		//Value.Exp = 30;
		return 2;
		break;
	case 2:
		//Value.Money = 1000;
		return 3;
		break;
	}
}

void Item::Render()
{
	switch (Index)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"бс",11);
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"б┌", 11);
		break;
	case 2:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"$$", 11);
		break;
	}
}

void Item::Release()
{
}
