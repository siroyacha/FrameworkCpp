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
	for (int i = 0; i < MaxSize/4; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(10.0f + i, 2.0f, (char*)"/",4);
	}
		CursorManager::GetInstance()->WriteBuffer(12.0f + MaxSize/4, 2.0f, MaxSize,4);
}

void UIManager::Release()
{
}
