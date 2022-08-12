#include "UIManager.h"
#include"Player.h"
#include"Bullet.h"

#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"ObjectManager.h"
#include"StartManager.h"

UIManager* UIManager::Instance = nullptr;

UIManager::UIManager() :pPlayer(nullptr),MaxSize(0),NowSize(0)
{
}

UIManager::~UIManager()
{
}

void UIManager::Start()
{
	pPlayer = StartManager::GetInstance()->LoadPlayer();
	pBullet = StartManager::GetInstance()->LoadBullet();
}

void UIManager::Update()
{
	MaxSize = pPlayer->GetMaxHP();
	NowSize = pPlayer->GetHP();
	Percent = ((float)NowSize / (float)MaxSize) * 25.0f;
}

void UIManager::Render()
{
	CursorManager::GetInstance()->WriteBuffer(10.0f, 2.0f, (char*)"LV.", 15);
	CursorManager::GetInstance()->WriteBuffer(14.0f, 2.0f, pPlayer->GetLV(), 15);

	CursorManager::GetInstance()->WriteBuffer(16.0f, 2.0f, (char*)"(EXP:", 15);
	CursorManager::GetInstance()->WriteBuffer(22.0f, 2.0f, pPlayer->GetExp(), 15);
	CursorManager::GetInstance()->WriteBuffer(24.0f, 2.0f, (char*)")", 15);

	CursorManager::GetInstance()->WriteBuffer(10.0f, 4.0f, (char*)"HP.", 12);

	for (int i = 0; i < 25; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(14.0f + i, 4.0f, (char*)"/", 10);
	}
	for (int i = 0; i < (int)Percent; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(14.0f + i, 4.0f, (char*)"/", 4);
	}
	CursorManager::GetInstance()->WriteBuffer(23.0f, 4.0f, NowSize, 12);
	CursorManager::GetInstance()->WriteBuffer(26.0f, 4.0f, (char*)"/", 12);
	CursorManager::GetInstance()->WriteBuffer(27.0f , 4.0f, MaxSize,12);

	CursorManager::GetInstance()->WriteBuffer(72.0f, 2.0f, (char*)"Score:", 15);
	CursorManager::GetInstance()->WriteBuffer(78.0f, 2.0f, pPlayer->GetScore(), 15);
}

void UIManager::Release()
{
}
