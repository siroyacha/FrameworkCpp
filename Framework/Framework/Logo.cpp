#include "Logo.h"
#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"StartManager.h"
Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Start()
{
	StartManager::GetInstance()->Start();
}

void Logo::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Logo::Render()
{
	CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"Crusader Subaver", 10);

	CursorManager::GetInstance()->WriteBuffer(100.0f, 6.0f, (char*)"¢Ã¢Ã¢Ã", 15);
	CursorManager::GetInstance()->WriteBuffer(100.0f, 7.0f, (char*)"¢Ã¢Ã¡Þ¡Þ¡Þ", 15);
	CursorManager::GetInstance()->WriteBuffer(100.0f, 8.0f, (char*)"¢Ã¢Ã¢Ã", 15);
	CursorManager::GetInstance()->WriteBuffer(100.0f, 16.0f, (char*)"    ¢Ã¢Ã¢Ã", 15);
	CursorManager::GetInstance()->WriteBuffer(100.0f, 17.0f, (char*)"¡Þ¡Þ¡Þ¢Ã¢Ã", 15);
	CursorManager::GetInstance()->WriteBuffer(100.0f, 18.0f, (char*)"    ¢Ã¢Ã¢Ã", 15);
	CursorManager::GetInstance()->WriteBuffer(50.0f, 16.0f, (char*)"    ¢Ã¢Ã¢Ã", 15);
	CursorManager::GetInstance()->WriteBuffer(50.0f, 17.0f, (char*)"¡Þ¡Þ¡Þ¢Ã¢Ã", 15);
	CursorManager::GetInstance()->WriteBuffer(50.0f, 18.0f, (char*)"    ¢Ã¢Ã¢Ã", 15);
}

void Logo::Release()
{

}