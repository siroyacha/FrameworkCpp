#include "shop.h"
#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"

Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::Start()
{
}

void Shop::Update()
{
}

void Shop::Render()
{
	CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"상점 테스트", 10);
}

void Shop::Release()
{
}