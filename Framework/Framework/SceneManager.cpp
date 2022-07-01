#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr)
{
}

SceneManager::~SceneManager()
{
}

void SceneManager::SetScene(SCENEID _State)
{
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}
	switch (_State)
	{
	case SCENEID::LOGO:
		//SceneState = new Logo;
		break;

	case SCENEID::MENU:
		//SceneState = new Menu;
		break;

	case SCENEID::STAGE:
		//SceneState = new Stage;
		break;

	case SCENEID::EXIT:
		cout << "EXIT" << endl;
		exit(NULL);
		break;
	}
	SceneState->Start();
}
