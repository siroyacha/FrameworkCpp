#include "ObjectManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "CollisionManager.h"
#include "CursorManager.h"
#include "MathManager.h"
#include "ObjectFactory.h"
#include"ObjectpoolManager.h"
#include"CollisionManager.h"
#include"SceneManager.h"

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
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);
	ObjectpoolManager::GetInstance()->SwitchingObject(_Key);
}

void ObjectManager::AddObject(Vector3 _Position, string _Key)
{
	if (!ObjectpoolManager::GetInstance()->FindObject(_Key))
		ObjectpoolManager::GetInstance()->AddObject(_Key);
	ObjectpoolManager::GetInstance()->SwitchingObject(_Key, _Position);
}

void ObjectManager::Update()
{
	if (pPlayer->Update())
	{
		SceneManager::GetInstance()->SetScene(SCENEID::GAMEOVER);
	}
	else
	{
		if (((Player*)pPlayer)->GetScore() > 10)
		{
			SceneManager::GetInstance()->SetScene(SCENEID::STAGECLEAR);
		}
	}
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