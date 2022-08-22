#include "Stage.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Player.h"
#include"ObjectFactory.h"
#include "SceneManager.h"
#include"ObjectManager.h"
#include "CursorManager.h"

Stage::Stage():Time(0)
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	//Time = GetTickCount64();
	ObjectManager::GetInstance()->Start();
	//ObjectManager::GetInstance()->SetPlayer(ObjectFactory<Player>::CreateObject(150.f / 2, 40.f / 2));
}

void Stage::Update()
{
	/*
	if (GetAsyncKeyState(VK_TAB))
	{
		if (Time + 250 < GetTickCount64())
		{
			Object* pBullet = ObjectFactory<Bullet>::CreateObject();
			((Bullet*)pBullet)->SetIndex(0);
			ObjectManager::GetInstance()->AddObject(pBullet);
			Time = GetTickCount64();
		}
	}
	*/
	if (GetAsyncKeyState(VK_TAB))
	{
		if (Time + 250 < GetTickCount64())
		{
			Object* pEnemy = ObjectFactory<Enemy>::CreateObject();
			((Bullet*)pEnemy)->SetIndex(0);
			ObjectManager::GetInstance()->AddObject(pEnemy);
			Time = GetTickCount64();
		}
	}
	ObjectManager::GetInstance()->Update();
}

void Stage::Render()
{

	ObjectManager::GetInstance()->Render();
}

void Stage::Release()
{
}
