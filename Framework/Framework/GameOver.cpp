#include "GameOver.h"

#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"ObjectManager.h"

GameOver::GameOver():CountDown(0)
{
}

GameOver::~GameOver()
{
}

void GameOver::Start()
{
	CountDown = 10;
	Time = GetTickCount64();
}

void GameOver::Update()
{
	if (Time + 1000 < GetTickCount64())
	{
		Time = GetTickCount64();
		--CountDown;
		if (CountDown == 0)
			SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
	}
}

void GameOver::Render()
{
	CursorManager::GetInstance()->WriteBuffer(70.0f, 15.0f, (char*)" 게임 오버");

	CursorManager::GetInstance()->WriteBuffer(62.0f, 20.0f, CountDown);
	CursorManager::GetInstance()->WriteBuffer(64.0f, 20.0f, (char*)" 초후 게임이 종료됩니다");
}

void GameOver::Release()
{
}
