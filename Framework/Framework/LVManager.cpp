#include "LVManager.h"

#include"Enemy.h"
#include"ObjectManager.h"
LVManager* LVManager::Instance = nullptr;

LVManager::LVManager():pEnemy(nullptr)
{
}

LVManager::~LVManager()
{
	DeleteLvManager();
}

void LVManager::EnemyUp(int Stage_Lv)
{
	pEnemy = new Enemy;
	
}

void LVManager::DeleteLvManager()
{
	delete pEnemy;
	pEnemy = nullptr;
}
