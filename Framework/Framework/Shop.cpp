#include "shop.h"
#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"ObjectManager.h"

Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::Start()
{
	Buffer[0] = (char*)"S t a r t";
	Buffer[1] = (char*)"O p t i o n";
	Buffer[2] = (char*)"S t o r e";
	Buffer[3] = (char*)"E x i t";

	Length[0] = strlen(Buffer[0]);
	Length[1] = strlen(Buffer[1]);
	Length[2] = strlen(Buffer[2]);
	Length[3] = strlen(Buffer[3]);

	MaxSize = 4;

	Color = 8;

	Time = GetTickCount64();


	Cursor = 10;
}

void Shop::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
	{
		Cursor -= 3;
		if (Cursor <= 10)
			Cursor = 10;
	}

	if (dwKey & KEY_DOWN)
	{
		Cursor += 3;
		if (Cursor >= 34)
			Cursor = 34;
	}

	if (dwKey & KEY_RETURN)
	{
		switch (Cursor)
		{
		case 10:
			break;

		case 13:
			break;

		case 15:
			break;

		case 18:
			break;

		case 21:
			break;

		case 24:
			break;

		case 27:
			break;

		case 31:
			break;

		case 34:
			break;
		}
	}
}

void Shop::Render()
{
	for (int i = 0; i < 39; i++)
	{
		CursorManager::GetInstance()->WriteBuffer(20.0f, 6.0f + i, (char*)"│", 10);
		CursorManager::GetInstance()->WriteBuffer(80.0f, 6.0f + i, (char*)"│", 10);
		for (int j = 0; j < 30; j++)
		{
			CursorManager::GetInstance()->WriteBuffer(20.0f + (2 * j), 5.0f, (char*)"─", 10);
			CursorManager::GetInstance()->WriteBuffer(20.0f + (2 * j), 45.0f, (char*)"─", 10);
		}
	}
	CursorManager::GetInstance()->WriteBuffer(20.0f, 5.0f, (char*)"┌", 10);
	CursorManager::GetInstance()->WriteBuffer(80.0f, 5.0f, (char*)"┐", 10);
	CursorManager::GetInstance()->WriteBuffer(20.0f, 45.0f, (char*)"└", 10);
	CursorManager::GetInstance()->WriteBuffer(80.0f, 45.0f, (char*)"┘", 10);

	for (int i = 0; i < 20; i++)
	{
		CursorManager::GetInstance()->WriteBuffer(95.0f, 6.0f + i, (char*)"│", 10);
		CursorManager::GetInstance()->WriteBuffer(125.0f, 6.0f + i, (char*)"│", 10);
		for (int j = 0; j < 15; j++)
		{
			CursorManager::GetInstance()->WriteBuffer(95.0f + (2 * j), 5.0f, (char*)"─", 10);
			CursorManager::GetInstance()->WriteBuffer(95.0f + (2 * j), 25.0f, (char*)"─", 10);
		}
	}
	CursorManager::GetInstance()->WriteBuffer(95.0f, 5.0f, (char*)"┌", 10);
	CursorManager::GetInstance()->WriteBuffer(125.0f, 5.0f, (char*)"┐", 10);
	CursorManager::GetInstance()->WriteBuffer(95.0f, 25.0f, (char*)"└", 10);
	CursorManager::GetInstance()->WriteBuffer(125.0f, 25.0f, (char*)"┘", 10);

	CursorManager::GetInstance()->WriteBuffer(30.0f, 10.0f, (char*)"아이템 1", Color);
	CursorManager::GetInstance()->WriteBuffer(30.0f, 13.0f, (char*)"아이템 1", Color);
	CursorManager::GetInstance()->WriteBuffer(30.0f, 16.0f, (char*)"아이템 1", Color);
	CursorManager::GetInstance()->WriteBuffer(30.0f, 19.0f, (char*)"아이템 1", Color);
	CursorManager::GetInstance()->WriteBuffer(30.0f, 22.0f, (char*)"아이템 1", Color);
	CursorManager::GetInstance()->WriteBuffer(30.0f, 25.0f, (char*)"아이템 1", Color);
	CursorManager::GetInstance()->WriteBuffer(30.0f, 28.0f, (char*)"아이템 1", Color);
	CursorManager::GetInstance()->WriteBuffer(30.0f, 31.0f, (char*)"아이템 1", Color);
	CursorManager::GetInstance()->WriteBuffer(30.0f, 34.0f, (char*)"아이템 1", Color);
	for (int i = 0; i < MaxSize; ++i)
	{
		if (Cursor == (15.0f + (i * 2)))
			Color = 11;
		else
			Color = 8;

		//CursorManager::GetInstance()->WriteBuffer(30.0f, 15.0f + (i * 2), Buffer[i], Color);
	}
}

void Shop::Release()
{
}