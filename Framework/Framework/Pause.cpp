#include "Pause.h"
#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"ObjectManager.h"

Pause::Pause()
{
}

Pause::~Pause()
{
}

void Pause::Start()
{
}

void Pause::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_ESCAPE)
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
}

void Pause::Render()
{
	ObjectManager::GetInstance()->Render();
	CursorManager::GetInstance()->WriteBuffer(0.0f, 0.0f, (char*)"Pause", 10);
}

void Pause::Release()
{
}
