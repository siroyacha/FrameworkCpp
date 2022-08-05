#include "shop.h"
#include"ShopManager.h"

Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::Start()
{
	ShopManager::GetInstance()->Start();
}

void Shop::Update()
{
	ShopManager::GetInstance()->Update();
}

void Shop::Render()
{
	ShopManager::GetInstance()->Render();
}

void Shop::Release()
{
}