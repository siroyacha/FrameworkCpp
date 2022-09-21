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
#include "Skill.h"
#include"InputManager.h"

Stage::Stage() : EnemyTime(0)
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

	for (int i = 0; i < Max; ++i)
	{
		Object* pSkill = new Skill;
		pSkill->SetPosition(
			int(14 * i + (150 - (14 * Max))),
			int(39 - (7 * 0.5f)));
		pSkill->Start("Skill");

		pSkillList.push_back(pSkill);
	}

	UserInterface::Index = 0;
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

	int SkillIndex = UserInterface::Index;

	if (KEY_Q & dwKey)
	{
		if (SkillIndex != 0)
			--SkillIndex;
	}

	if (KEY_E & dwKey)
	{
		if (SkillIndex != (Max - 1))
			++SkillIndex;
	}

	for (int i = 0; i < 20; ++i)
	{
		if (EnemyTime + 200 < GetTickCount64())
		{
			ObjectManager::GetInstance()->AddObject(Vector3(rand() % 150, rand() % 40), "Enemy");
			EnemyTime = GetTickCount64();
		}
	}

	UserInterface::Index = SkillIndex;
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

	ObjectManager::GetInstance()->Render();

	for (vector<Object*>::iterator iter = pSkillList.begin();
		iter != pSkillList.end(); ++iter)
	{
		(*iter)->Render();
	}
}

void Stage::Release()
{

}