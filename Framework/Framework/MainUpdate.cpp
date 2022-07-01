#include "MainUpdate.h"
#include "SceneManager.h"
MainUpdate::MainUpdate():Count(0)
{

}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Start()
{
	SceneManager::GetInstance()->SetScene(LOGO);
}

void MainUpdate::Update()
{
	++Count;
	switch (Count)
	{
	case 100:
		SceneManager::GetInstance()->SetScene(MENU);
		break;
	case 150:
		SceneManager::GetInstance()->SetScene(STAGE);
		break;
	case 200:
		SceneManager::GetInstance()->SetScene(EXIT);
		break;
	}
}

void MainUpdate::Render()
{
	cout << Count << endl;
}

void MainUpdate::Release()
{

}