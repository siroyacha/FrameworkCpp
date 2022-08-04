#include "Player.h"
#include"Bullet.h"
#include"SceneManager.h"
#include "InputManager.h"
#include"ObjectManager.h"
#include"CursorManager.h"

Player::Player():X_Shift(1.0f),Y_Shift(1.0f)
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
	Value.Hp = 5;
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
	}	
	if (dwKey & KEY_RIGHT)
	{
		++Info.Position.x;
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
		SceneManager::GetInstance()->SetScene(SCENEID::PAUSE);
	}
	if (Value.Exp >= 100)
	{
		++Value.Lv;
		Value.Exp -= 100;
	}

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"��");
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
