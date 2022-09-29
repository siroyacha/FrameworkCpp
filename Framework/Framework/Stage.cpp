#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include"InputManager.h"
#include"CollisionManager.h"
#include"UIManager.h"

Stage::Stage() : EnemyTime(0)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{	
	UIManager::GetInstance()->Start();

	EnemyTime = GetTickCount64();

}

void Stage::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	/*
	for (int i = 0; i < 20; ++i)
	{
		if (EnemyTime + 200 < GetTickCount64())
		{
			ObjectManager::GetInstance()->AddObject(Vector3(rand() % 150, rand() % 40), "Enemy");
			EnemyTime = GetTickCount64();
		}
	}
	*/

	ObjectManager::GetInstance()->Update();
	UIManager::GetInstance()->Update();
}

void Stage::Render()
{
	ObjectManager::GetInstance()->Render();
	
	UIManager::GetInstance()->Render();
}

void Stage::Release()
{

}