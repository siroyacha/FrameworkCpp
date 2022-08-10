#include "StartManager.h"

#include"Bullet.h"
#include"Player.h"
#include"Enemy.h"
#include"Item.h"
#include"ObjectFactory.h"

StartManager* StartManager::Instance = nullptr;

StartManager::StartManager():pPlayer(nullptr)
{
}

StartManager::~StartManager()
{
	Release();
}

void StartManager::Start()
{
	pPlayer = ObjectFactory::CreatePlayer();

}

int StartManager::GetStageLv()
{
	return pPlayer->GetStageLv();
}

void StartManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}
