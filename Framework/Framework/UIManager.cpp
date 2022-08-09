#include "UIManager.h"
#include"Player.h"

#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"ObjectManager.h"

UIManager* UIManager::Instance = nullptr;

UIManager::UIManager() :pPlayer(nullptr),MaxSize(0)
{
}

UIManager::~UIManager()
{
}

void UIManager::Start()
{
	pPlayer = ObjectManager::GetInstance()->LoadPlayer();
}

void UIManager::Update()
{
	MaxSize = pPlayer->GetHP();
}

void UIManager::Render()
{
	CursorManager::GetInstance()->WriteBuffer(10.0f, 2.0f, (char*)"LV.", 15);
	CursorManager::GetInstance()->WriteBuffer(14.0f, 2.0f, pPlayer->GetLV(), 15);

	CursorManager::GetInstance()->WriteBuffer(16.0f, 2.0f, (char*)"(EXP:", 15);
	CursorManager::GetInstance()->WriteBuffer(22.0f, 2.0f, pPlayer->GetExp(), 15);
	CursorManager::GetInstance()->WriteBuffer(24.0f, 2.0f, (char*)")", 15);

	CursorManager::GetInstance()->WriteBuffer(10.0f, 4.0f, (char*)"HP.", 12);

	for (int i = 0; i < MaxSize/4; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(14.0f + i, 4.0f, (char*)"/",4);
	}
	CursorManager::GetInstance()->WriteBuffer(23.0f , 4.0f, MaxSize,12);
	CursorManager::GetInstance()->WriteBuffer(26.0f, 4.0f, (char*)"/100", 12);
}

void UIManager::Release()
{
}
