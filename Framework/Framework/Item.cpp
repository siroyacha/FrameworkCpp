#include "Item.h"
#include"CursorManager.h"
#include"MathManager.h"

Item::Item()
{
}

Item::~Item()
{
}

void Item::Start()
{
	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(1.0f, 1.0f);
	Time = GetTickCount64();
}

int Item::Update()
{
	if (Time + 5000 <= GetTickCount64())
	{
		Time = GetTickCount64();
		return 1;
	}
	return 0;
}

void Item::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡Ú", 13);
	/*
	switch (Index)
	{
	case 0:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡Ú",13);
		break;
	case 1:
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡Ù", 11);
		break;
	}
	*/
}

void Item::Release()
{
}
