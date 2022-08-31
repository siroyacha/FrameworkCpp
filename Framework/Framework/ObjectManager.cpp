#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include"ObjectpoolManager.h"

ObjectManager* ObjectManager::Instance = nullptr;

ObjectManager::ObjectManager() : pPlayer(nullptr)
{

}

ObjectManager::~ObjectManager()
{
	Release();
}


void ObjectManager::AddObject(string _Key)
{
	if (ObjectpoolManager::GetInstance()->FindObject(_Key))
	{
		//����Ī
		//ObjectpoolManager::GetInstance()->SwitchingObject()
	}
	else
		ObjectpoolManager::GetInstance()->AddObject(_Key);
}

void ObjectManager::Update()
{
	pPlayer->Update();
	ObjectpoolManager::GetInstance()->Update();
}

void ObjectManager::Render()
{
	pPlayer->Render();
	ObjectpoolManager::GetInstance()->Render();
}

void ObjectManager::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}