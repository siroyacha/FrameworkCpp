#include "Open.h"

#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"

Open::Open():Counter(1)
{
}

Open::~Open()
{
}

void Open::Start()
{
	Time = GetTickCount64();
}

void Open::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_Y_Shift)
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
}

void Open::Render()
{
	for (int i = 0; i < 39; i++)
	{
		CursorManager::GetInstance()->WriteBuffer(45.0f, 6.0f + i, (char*)"│", 15);
		CursorManager::GetInstance()->WriteBuffer(105.0f, 6.0f + i, (char*)"│", 15);
		for (int j = 0; j < 30; j++)
		{
			CursorManager::GetInstance()->WriteBuffer(45.0f + (2 * j), 5.0f, (char*)"─", 15);
			CursorManager::GetInstance()->WriteBuffer(45.0f + (2 * j), 45.0f, (char*)"─", 15);
		}
	}
	CursorManager::GetInstance()->WriteBuffer(45.0f, 5.0f, (char*)"┌", 15);
	CursorManager::GetInstance()->WriteBuffer(105.0f, 5.0f, (char*)"┐", 15);
	CursorManager::GetInstance()->WriteBuffer(45.0f, 45.0f, (char*)"└", 15);
	CursorManager::GetInstance()->WriteBuffer(105.0f, 45.0f, (char*)"┘", 15);
	if (Time + 250 < GetTickCount64())
	{
		Time = GetTickCount64();
		if (Counter < 20)
		{
			int k = 0;
			k = 10 / Counter;
			if (k / 2 == 1)
			{
				for (int i = 0; i < 10; i++)
				{
					CursorManager::GetInstance()->WriteBuffer(65.0f - 2, (26.0f + i), (char*)"│", 15);
					CursorManager::GetInstance()->WriteBuffer(85.0f - 2, (26.0f + i), (char*)"│", 15);
					for (int j = 0; j < 10; j++)
					{
						CursorManager::GetInstance()->WriteBuffer(65.0f + (2 * j) - 2, 25.0f, (char*)"─", 15);
						CursorManager::GetInstance()->WriteBuffer(65.0f + (2 * j) - 2, 35.0f, (char*)"─", 15);
					}
				}
				CursorManager::GetInstance()->WriteBuffer(65.0f - 2, 25.0f, (char*)"┌", 15);
				CursorManager::GetInstance()->WriteBuffer(85.0f - 2, 25.0f, (char*)"┐", 15);
				CursorManager::GetInstance()->WriteBuffer(65.0f - 2, 35.0f, (char*)"└", 15);
				CursorManager::GetInstance()->WriteBuffer(85.0f - 2, 35.0f, (char*)"┘", 15);
			}
			if (k / 2 != 1)
			{
				for (int i = 0; i < 10; i++)
				{
					CursorManager::GetInstance()->WriteBuffer(65.0f + 2, (26.0f + i), (char*)"│", 15);
					CursorManager::GetInstance()->WriteBuffer(85.0f + 2, (26.0f + i), (char*)"│", 15);
					for (int j = 0; j < 10; j++)
					{
						CursorManager::GetInstance()->WriteBuffer(65.0f + (2 * j) + 2, 25.0f, (char*)"─", 15);
						CursorManager::GetInstance()->WriteBuffer(65.0f + (2 * j) + 2, 35.0f, (char*)"─", 15);
					}
				}
				CursorManager::GetInstance()->WriteBuffer(65.0f + 2, 25.0f, (char*)"┌", 15);
				CursorManager::GetInstance()->WriteBuffer(85.0f + 2, 25.0f, (char*)"┐", 15);
				CursorManager::GetInstance()->WriteBuffer(65.0f + 2, 35.0f, (char*)"└", 15);
				CursorManager::GetInstance()->WriteBuffer(85.0f + 2, 35.0f, (char*)"┘", 15);
			}
		}
		++Counter;
	}
	if (Counter > 20)
	{
		for (int i = 0; i < 10; i++)
		{
			CursorManager::GetInstance()->WriteBuffer(65.0f, (26.0f + i), (char*)"│", 15);
			CursorManager::GetInstance()->WriteBuffer(85.0f, (26.0f + i), (char*)"│", 15);
			for (int j = 0; j < 10; j++)
			{
				CursorManager::GetInstance()->WriteBuffer(65.0f + (2 * j), 25.0f, (char*)"─", 15);
				CursorManager::GetInstance()->WriteBuffer(65.0f + (2 * j), 35.0f, (char*)"─", 15);
			}
		}
		CursorManager::GetInstance()->WriteBuffer(65.0f, 25.0f, (char*)"┌", 15);
		CursorManager::GetInstance()->WriteBuffer(85.0f, 25.0f, (char*)"┐", 15);
		CursorManager::GetInstance()->WriteBuffer(65.0f, 35.0f, (char*)"└", 15);
		CursorManager::GetInstance()->WriteBuffer(85.0f, 35.0f, (char*)"┘", 15);

		CursorManager::GetInstance()->WriteBuffer(75.0f, 30.0f, (char*)"test", 15);
		CursorManager::GetInstance()->WriteBuffer(65.0f, 50.0f, (char*)"Q를 눌러 돌아가기", 15);
	}
}

void Open::Release()
{
}
