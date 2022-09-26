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
	/*
	Vector3 PlayerPosition = ObjectManager::GetInstance()->GetPlayer()->GetPosition();
	
	float Result = ((PlayerPosition.x * 100) / 100);
	Result = (100 - Result);
	Result = Result / 100;

	if (EnemyTime + (2500 * Result) < GetTickCount64())
	{
		srand(int(GetTickCount64() * EnemyTime));

		Object* pEnemy = ObjectFactory<Enemy>::CreateObject(
			float(rand() % 20 + 120), float(rand() % 39 + 1));

		Object* pEnemy = PrototypeManager::GetInstance()->FindObject("Enemy")->Clone();
		if (pEnemy != nullptr)
		{
			pEnemy->SetPosition(
				float(rand() % 20 + 120), float(rand() % 39 + 1));

			ObjectManager::GetInstance()->AddObject(pEnemy);
		}


		EnemyTime = GetTickCount64();
	}
	*/
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	for (int i = 0; i < 20; ++i)
	{
		if (EnemyTime + 2000 < GetTickCount64())
		{
			ObjectManager::GetInstance()->AddObject(Vector3(rand() % 150, rand() % 40), "Enemy");
			EnemyTime = GetTickCount64();
		}
	}

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