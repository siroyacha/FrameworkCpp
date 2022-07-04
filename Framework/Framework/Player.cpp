#include "Player.h"
#include "InputManager.h"
Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	Info.Position;
}

void Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_UP)
	{
		cout << "Key_up" << endl;		
		++Info.Position.y;
		cout << Info.Position.x << ", " << Info.Position.y << endl;
	}	
	if (dwKey & KEY_DOWN)
	{
		cout << "Key_DOWN" << endl;
		--Info.Position.y;
		cout << Info.Position.x << ", " << Info.Position.y << endl;
	}	
	if (dwKey & KEY_LEFT)
	{
		cout << "Key_LEFT" << endl;
		--Info.Position.x;
		cout << Info.Position.x << ", " << Info.Position.y << endl;
	}	
	if (dwKey & KEY_RIGHT)
	{
		cout << "Key_RIGHT" << endl;
		++Info.Position.x;
		cout << Info.Position.x << ", " << Info.Position.y << endl;
	}
	if (dwKey & KEY_SPACE)
	{
		cout << "Key_SPACE" << endl;
	}
	if (dwKey & KEY_RETURN)
	{
		cout << "Key_RETURN" << endl;
	}
	if (dwKey & KEY_ESCAPE)
	{
		cout << "Key_ESCAPE" << endl;
	}
}

void Player::Render()
{

}

void Player::Release()
{

}