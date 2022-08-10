#include "ShopManager.h"
#include"Player.h"

#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"StartManager.h"

ShopManager* ShopManager::Instance = nullptr;

ShopManager::ShopManager():pPlayer(nullptr)
{
}

ShopManager::~ShopManager()
{
}

void ShopManager::Start()
{
	pPlayer = StartManager::GetInstance()->LoadPlayer();
	Buffer[0] = (char*)"아이템 1";
	Buffer[1] = (char*)"아이템 2";
	Buffer[2] = (char*)"아이템 3";
	Buffer[3] = (char*)"아이템 4";
	Buffer[4] = (char*)"아이템 5";
	Buffer[5] = (char*)"아이템 6";
	Buffer[6] = (char*)"아이템 7";
	Buffer[7] = (char*)"아이템 8";
	Buffer[8] = (char*)"아이템 9";

	Buffer2[0] = (char*)"아이템 텍스쳐1";
	Buffer2[1] = (char*)"아이템 텍스쳐2";
	Buffer2[2] = (char*)"아이템 텍스쳐3";
	Buffer2[3] = (char*)"아이템 텍스쳐4";
	Buffer2[4] = (char*)"아이템 텍스쳐5";
	Buffer2[5] = (char*)"아이템 텍스쳐6";
	Buffer2[6] = (char*)"아이템 텍스쳐7";
	Buffer2[7] = (char*)"아이템 텍스쳐8";
	Buffer2[8] = (char*)"아이템 텍스쳐9";

	Buffer3[0] = (char*)"아이템설명1";
	Buffer3[1] = (char*)"아이템설명2";
	Buffer3[2] = (char*)"아이템설명3";
	Buffer3[3] = (char*)"아이템설명4";
	Buffer3[4] = (char*)"아이템설명5";
	Buffer3[5] = (char*)"아이템설명6";
	Buffer3[6] = (char*)"아이템설명7";
	Buffer3[7] = (char*)"아이템설명8";
	Buffer3[8] = (char*)"아이템설명9";

	MaxSize = 9;

	Color = 8;

	Time = GetTickCount64();


	Cursor = 10;
}

void ShopManager::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
	{
		Cursor -= 3;
		if (Cursor <= 10)
			Cursor = 10;
		if (Cursor >= 34)
			Cursor = 34;
	}

	if (dwKey & KEY_DOWN)
	{
		Cursor += 3;
		if (Cursor >= 37)
			Cursor = 52;
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

		case 52:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGECLEAR);
			break;
		}
	}
}

void ShopManager::Render()
{
	for (int i = 0; i < 39; i++)
	{
		CursorManager::GetInstance()->WriteBuffer(20.0f, 6.0f + i, (char*)"│", 15);
		CursorManager::GetInstance()->WriteBuffer(80.0f, 6.0f + i, (char*)"│", 15);
		for (int j = 0; j < 30; j++)
		{
			CursorManager::GetInstance()->WriteBuffer(20.0f + (2 * j), 5.0f, (char*)"─", 15);
			CursorManager::GetInstance()->WriteBuffer(20.0f + (2 * j), 45.0f, (char*)"─", 15);
		}
	}
	CursorManager::GetInstance()->WriteBuffer(20.0f, 5.0f, (char*)"┌", 15);
	CursorManager::GetInstance()->WriteBuffer(80.0f, 5.0f, (char*)"┐", 15);
	CursorManager::GetInstance()->WriteBuffer(20.0f, 45.0f, (char*)"└", 15);
	CursorManager::GetInstance()->WriteBuffer(80.0f, 45.0f, (char*)"┘", 15);

	for (int i = 0; i < 10; i++)
	{
		CursorManager::GetInstance()->WriteBuffer(100.0f, 6.0f + i, (char*)"│", 15);
		CursorManager::GetInstance()->WriteBuffer(120.0f, 6.0f + i, (char*)"│", 15);
		for (int j = 0; j < 10; j++)
		{
			CursorManager::GetInstance()->WriteBuffer(100.0f + (2 * j), 5.0f, (char*)"─", 15);
			CursorManager::GetInstance()->WriteBuffer(100.0f + (2 * j), 15.0f, (char*)"─", 15);
		}
	}
	CursorManager::GetInstance()->WriteBuffer(100.0f, 5.0f, (char*)"┌", 15);
	CursorManager::GetInstance()->WriteBuffer(120.0f, 5.0f, (char*)"┐", 15);
	CursorManager::GetInstance()->WriteBuffer(100.0f, 15.0f, (char*)"└", 15);
	CursorManager::GetInstance()->WriteBuffer(120.0f, 15.0f, (char*)"┘", 15);

	for (int i = 0; i < MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(130.0f, 52.0f, (char*)"상점 나가기", 8);
		if (Cursor == 52)
			CursorManager::GetInstance()->WriteBuffer(130.0f, 52.0f, (char*)"상점 나가기", 11);
		if (Cursor == (10.0f + (i * 3)))
			Color = 11;
		else
			Color = 8;

		CursorManager::GetInstance()->WriteBuffer(30.0f, 10.0f + (i * 3), Buffer[i], Color);

		if (Cursor == (10.0f + (i * 3)))
			CursorManager::GetInstance()->WriteBuffer(105.0f, 10.0f, Buffer2[i], Color);
		if (Cursor == (10.0f + (i * 3)))
			CursorManager::GetInstance()->WriteBuffer(100.0f, 20.0f, Buffer3[i], 15);
	}
	CursorManager::GetInstance()->WriteBuffer(15.0f, 55.0f, (char*)"현재 금액 : ", 15);
	CursorManager::GetInstance()->WriteBuffer(30.0f, 55.0f,pPlayer->GetMoney(), 15);
}

void ShopManager::Release()
{
}