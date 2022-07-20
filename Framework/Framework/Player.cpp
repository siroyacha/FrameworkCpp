#include "Player.h"
#include"Bullet.h"
#include"SceneManager.h"
#include "InputManager.h"
#include"ObjectManager.h"
#include"CursorManager.h"
Player::Player():X_Shift(1),Y_Shift(1)
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
		ObjectManager::GetInstance()->CreatePlayerObject(2, dwKey - KEY_SPACE);
	}
	
	if (dwKey & KEY_SHIFT)
	{
		Y_Shift *= -1;
	}

	if (dwKey & KEY_CONTROL)
	{
		X_Shift *= -1;
	}

	if (dwKey & KEY_ESCAPE)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
	}
	
	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡Ù");
}

void Player::Release()
{

}