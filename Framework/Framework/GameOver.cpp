#include "GameOver.h"
#include"Player.h"
#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"StartManager.h"
#include"ObjectManager.h"


GameOver::GameOver():CountDown(0)
{
}

GameOver::~GameOver()
{
}

void GameOver::Start()
{
	Buffer[0] = (char*)"   .::::                                            .::::                                          ";
	Buffer[1] = (char*)" .:    .::                                        .::    .::                                       ";
	Buffer[2] = (char*)".::           .::    .::: .:: .::    .::        .::        .::.::     .::   .::    .: .:::         ";
	Buffer[3] = (char*)".::         .::  .::  .::  .:  .:: .:   .::     .::        .:: .::   .::  .:   .::  .::             ";
	Buffer[4] = (char*)".::   .::::.::   .::  .::  .:  .::.::::: .::    .::        .::  .:: .::  .::::: .:: .::            ";
	Buffer[5] = (char*)" .::    .: .::   .::  .::  .:  .::.:              .::     .::    .:.::   .:         .::             ";
	Buffer[6] = (char*)"  .:::::     .:: .:::.:::  .:  .::  .::::           .::::         .::      .::::   .:::   .::.::.::";

	Length = strlen("  .:::::     .:: .:::.:::  .:  .::  .::::           .::::         .::      .::::   .:::   .::.::.::");

	MaxSize = 7;

	CountDown = 10;
	Time = GetTickCount64();

	pPlayer = ObjectManager::GetInstance()->GetPlayer();
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
	/*
	*/
	for (int i = 0; i < MaxSize; ++i)
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length / 2), 15.0f + i, Buffer[i], 10);

	CursorManager::GetInstance()->WriteBuffer(74.0f, 29.0f, ((Player*)pPlayer)->GetScore());
	CursorManager::GetInstance()->WriteBuffer(64.0f, 31.0f, (char*)" ���� ȹ���ϼ̽��ϴ�");

	CursorManager::GetInstance()->WriteBuffer(62.0f, 40.0f, CountDown);
	CursorManager::GetInstance()->WriteBuffer(64.0f, 40.0f, (char*)" ���� ������ ����˴ϴ�");
}

void GameOver::Release()
{
}
