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
	CursorManager::GetInstance()->WriteBuffer(70.0f, 15.0f, (char*)" ���� ����");

	CursorManager::GetInstance()->WriteBuffer(62.0f, 20.0f, CountDown);
	CursorManager::GetInstance()->WriteBuffer(64.0f, 20.0f, (char*)" ���� ������ ����˴ϴ�");
}

void GameOver::Release()
{
}
