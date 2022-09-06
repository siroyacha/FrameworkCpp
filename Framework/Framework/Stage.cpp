#include "Stage.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "CursorManager.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "ObjectFactory.h"
#include"PrototypeManager.h"
#include"UserInterface.h"
#include"ScrollBox.h"

Stage::Stage() : EnemyTime(0),MaxSize(0)
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	Object* pObj = PrototypeManager::GetInstance()->FindObject("Player")->Clone();
	if (pObj != nullptr)
		ObjectManager::GetInstance()->SetPlayer(pObj);
	EnemyTime = GetTickCount64();
	/*
	aaa[0] = (char*)"      ��";
	aaa[1] = (char*)"����������";
	aaa[2] = (char*)"����������";
	aaa[3] = (char*)"      ��";
	aaa[4] = (char*)" ";
	aaa[5] = (char*)" ";
	aaa[6] = (char*)" ";
	aaa[7] = (char*)" ";
	aaa[8] = (char*)" ";

	MaxSize = 4;
	*/
	for (int i = 0; i < 20; ++i)
	{
		ObjectManager::GetInstance()->AddObject(Vector3(rand() % 150, rand() % 40), "Enemy");
	}

	Box = new ScrollBox;
	Box->Start();
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

	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{
	/*
	for (int i = 0; i < MaxSize; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(10.0f, 10.0f + i, aaa[i]);
	}
	*/

	Box->Render();
	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{

}