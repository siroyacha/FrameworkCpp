#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include"Shop.h"
#include "Stage.h"
#include"Pause.h"
#include"GameOver.h"
#include"Open.h"
#include"StagetClear.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr)
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(SCENEID _SceneID)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneID)
	{
	case SCENEID::LOGO:
		SceneState = new Logo;
		break;

	case SCENEID::MENU:
		SceneState = new Menu;
		break;

	case SCENEID::SHOP:
		SceneState = new Shop;
		break;

	case SCENEID::PAUSE:
		SceneState = new Pause;
		break;

	case SCENEID::STAGE:
		SceneState = new Stage;
		break;

	case SCENEID::GAMEOVER:
		SceneState = new GameOver;
		break;

	case SCENEID::OPEN:
		SceneState = new Open;
		break;

	case SCENEID::STAGECLEAR:
		SceneState = new StagetClear;
		break;

	case SCENEID::EXIT:
		exit(NULL);
		break;
	}
	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{
	delete SceneState;
	SceneState = nullptr;
}