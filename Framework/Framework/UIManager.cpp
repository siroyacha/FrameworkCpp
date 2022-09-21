#include "UIManager.h"
#include"Player.h"
#include"Bullet.h"

#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"ObjectManager.h"
#include"StartManager.h"
#include"ScrollBox.h"

UIManager* UIManager::Instance = nullptr;

UIManager::UIManager() :pPlayer(nullptr),MaxSize(0),NowSize(0)
{
}

UIManager::~UIManager()
{
}

void UIManager::Start()
{
	pPlayer = StartManager::GetInstance()->LoadPlayer();
	pBullet = StartManager::GetInstance()->LoadBullet();
	/*
	Box = new ScrollBox;
	Box->Start();
	Box->SetPosition(int(Info.Position.x - (Info.Scale.x / 2)), int(Info.Position.y - (Info.Scale.y / 2)));
	Box->SetBoxSize(Info.Scale.x, Info.Scale.y);
	*/

}

void UIManager::Update()
{
	//Box->Update();

	/*
	MaxSize = pPlayer->GetMaxHP();
	NowSize = pPlayer->GetHP();
	Percent = ((float)NowSize / (float)MaxSize) * 25.0f;
	*/
}

void UIManager::Render()
{
	//Box->Render();
	/*
	for (int i = 0; i < 5; i++)
	{
		CursorManager::GetInstance()->WriteBuffer(10.0f, 4.0f + i, (char*)"¦¢", 15);
		CursorManager::GetInstance()->WriteBuffer(20.0f, 4.0f + i, (char*)"¦¢", 15);
		for (int j = 0; j < 5; j++)
		{
			CursorManager::GetInstance()->WriteBuffer(10.0f + (2 * j), 3.0f, (char*)"¦¡", 15);
			CursorManager::GetInstance()->WriteBuffer(10.0f + (2 * j), 8.0f, (char*)"¦¡", 15);
		}
	}
	CursorManager::GetInstance()->WriteBuffer(10.0f, 3.0f, (char*)"¦£", 15);
	CursorManager::GetInstance()->WriteBuffer(20.0f, 3.0f, (char*)"¦¤", 15);
	CursorManager::GetInstance()->WriteBuffer(10.0f, 8.0f, (char*)"¦¦", 15);
	CursorManager::GetInstance()->WriteBuffer(20.0f, 8.0f, (char*)"¦¥", 15);

	((Bullet*)pBullet)->SetIndex(((Player*)pPlayer)->GetW_Type());
	pBullet->SetPosition(15.0f, 5.0f);
	pBullet->Render();
	CursorManager::GetInstance()->WriteBuffer(10.0f, 9.0f, (char*)"Bullet LV.", 15);
	CursorManager::GetInstance()->WriteBuffer(21.0f, 9.0f, ((Bullet*)pBullet)->GetBulletLV(((Player*)pPlayer)->GetW_Type()), 15);
		
	CursorManager::GetInstance()->WriteBuffer(23.0f, 5.0f, (char*)"LV.", 15);
	CursorManager::GetInstance()->WriteBuffer(27.0f, 5.0f, pPlayer->GetLV(), 15);
													 
	CursorManager::GetInstance()->WriteBuffer(29.0f, 5.0f, (char*)"(EXP:", 15);
	CursorManager::GetInstance()->WriteBuffer(35.0f, 5.0f, pPlayer->GetExp(), 15);
	CursorManager::GetInstance()->WriteBuffer(37.0f, 5.0f, (char*)")", 15);

	CursorManager::GetInstance()->WriteBuffer(23.0f, 7.0f, (char*)"HP.", 12);

	for (int i = 0; i < 25; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(27.0f + i, 7.0f, (char*)"/", 10);
	}
	for (int i = 0; i < (int)Percent; ++i)
	{
		CursorManager::GetInstance()->WriteBuffer(27.0f + i, 7.0f, (char*)"/", 4);
	}
	CursorManager::GetInstance()->WriteBuffer(36.0f, 7.0f, NowSize, 12);
	CursorManager::GetInstance()->WriteBuffer(39.0f, 7.0f, (char*)"/", 12);
	CursorManager::GetInstance()->WriteBuffer(40.0f, 7.0f, MaxSize,12);

	CursorManager::GetInstance()->WriteBuffer(72.0f, 2.0f, (char*)"Score:", 15);
	CursorManager::GetInstance()->WriteBuffer(78.0f, 2.0f, pPlayer->GetScore(), 15);
	*/
}

void UIManager::Release()
{ 
	/*
	delete Box;
	Box = nullptr;
	*/
}
