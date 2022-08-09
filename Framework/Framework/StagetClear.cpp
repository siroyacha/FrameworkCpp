#include "StagetClear.h"

#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"

StagetClear::StagetClear()
{
}

StagetClear::~StagetClear()
{
}

void StagetClear::Start()
{
	Buffer[0] = (char*)"S t o r e";
	Buffer[1] = (char*)"N e x t S t a g e";

	Length[0] = strlen(Buffer[0]);
	Length[1] = strlen(Buffer[1]);

	Color = 8;

	Time = GetTickCount64();

	WordBuffer[0] = (char*)"  ____  _                      ____ _                 _ 				";
	WordBuffer[1] = (char*)" / ___|| |_ __ _  __ _  ___   / ___| | ___  __ _ _ __| |	";
	WordBuffer[2] = (char*)" \\___ \\| __/ _` |/ _` |/ _ \\ | |   | |/ _ \\/ _` | '__| |		   ";
	WordBuffer[3] = (char*)"  ___) | || (_| | (_| |  __/ | |___| |  __/ (_| | |  |_|		   ";
	WordBuffer[4] = (char*)" |____/ \\__\\__,_|\\__, |\\___|  \\____|_|\\___|\\__,_|_|  (_)";
	WordBuffer[5] = (char*)"                 |___/                                  					   ";

	WordLength = strlen(" |____/ \\__\\__,_|\\__, |\\___|  \\____|_|\\___|\\__,_|_|  (_)");
	WordMaxSize = 6;
	Cursor = 49;
}

void StagetClear::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_UP)
	{
		Cursor -= 2;
		if (Cursor <= 49)
			Cursor = 49;
	}

	if (dwKey & KEY_DOWN)
	{
		Cursor += 2;
		if (Cursor >= 51)
			Cursor = 51;
	}

	if (dwKey & KEY_RETURN)
	{
		switch (Cursor)
		{
		case 49:
			SceneManager::GetInstance()->SetScene(SCENEID::SHOP);
			break;

		case 51:
			SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
			break;
		}
	}
}

void StagetClear::Render()
{
	for (int i = 0; i < 2; ++i)
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length[1] / 2 + 2), 49.0f + (i * 2), (char*)"[                   ]", 8);

	for (int i = 0; i < 2; ++i)
	{
		if (Cursor == (49.0f + (i * 2)))
			Color = 11;
		else
			Color = 8;

		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length[i] / 2), 49.0f + (i * 2), Buffer[i], Color);
	}

	for (int i = 0; i < WordMaxSize; ++i)
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (WordLength / 2), 15.0f + i, WordBuffer[i], 11);
}

void StagetClear::Release()
{
}


