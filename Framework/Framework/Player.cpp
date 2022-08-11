#include "Player.h"
#include"Bullet.h"
#include"Shield.h"
#include"SceneManager.h"
#include "InputManager.h"
#include"ObjectManager.h"
#include"CursorManager.h"

Player::Player():X_Shift(1.0f), Y_Shift(1.0f), Lv_Check(0), RenderRoll(0)
{
}

Player::~Player()
{
}

void Player::Start()
{
	Info.Position = Vector3(75.0f, 20.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);
	
	Target = nullptr;

	Value.Lv = 1;
	Value.Money = 1000;
	Value.Exp = 0;
	Value.MaxHP = 100;
	Value.Hp = 100;
	Value.Score = 0;
	Value.Stage_Lv = 1;
	RenderRoll = 1;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	
	if (dwKey & KEY_UP)
	{
		--Info.Position.y;
	}	
	if (dwKey & KEY_DOWN)
	{
		++Info.Position.y;
	}	
	if (dwKey & KEY_LEFT)
	{
		--Info.Position.x;
		RenderRoll = -1;
	}	
	if (dwKey & KEY_RIGHT)
	{
		++Info.Position.x;
		RenderRoll = 1;
	}
	if (dwKey & KEY_SPACE)
	{
		ObjectManager::GetInstance()->CreatePlayerObject(2, dwKey - KEY_SPACE, X_Shift, Y_Shift);
	}
	
	if (dwKey & KEY_Y_Shift)
	{
		Y_Shift *= -1.0f;
	}

	if (dwKey & KEY_X_Shift)
	{
		X_Shift *= -1.0f;
	}

	if (dwKey & KEY_ESCAPE)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
	}

	if (dwKey & KEY_W_Change)
	{
		/*
		���� ��ȯ
		*/
	}

	if (Value.Exp >= 100)
	{
		++Value.Lv;
		Value.Exp -= 100;
		++Lv_Check;
		Value.MaxHP += 10 * Value.Lv;
		Value.Hp = Value.MaxHP;
	}

	return 0;
}

void Player::Render()
{
	if (RenderRoll == 1)
	{
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"�١�");
	}
	if (RenderRoll == -1)
	{
		CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(0.0f, -2.0f), (char*)"�������", 15);
		CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(0.0f, -1.0f), (char*)"��ââá��", 15);
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"��ââáޡޡޡޡޡ�", 15);
		CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(0.0f, 1.0f), (char*)"��ââá��", 15);
		CursorManager::GetInstance()->WriteBuffer(Info.Position + Vector3(0.0f, 2.0f), (char*)"�������", 15);
		CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"���");
	}
	if (Lv_Check)
	{
		Vector3 Lv_Position = Vector3(0.0f, -2.0f);
		CursorManager::GetInstance()->WriteBuffer(Info.Position+Lv_Position, (char*)"���� ��!");
		--Lv_Check;
	}
}

void Player::Release()
{
}

int Player::DamegeControl(int _Att)
{
	Value.Hp = Value.Hp - (_Att - Value.Def);
	if (Value.Def > _Att)
		--Value.Hp;
	if (Value.Hp)
		return 1;
	else
		return 0;
}
