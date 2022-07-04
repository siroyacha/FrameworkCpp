#include "Stage.h"
#include "SceneManager.h"
#include"Player.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{
	pPlayer = new Player;
	pPlayer->Start();
}

void Stage::Update()
{
	pPlayer->Update();
	//Count++;

	if (Count >= 100)
		SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
}

void Stage::Render()
{
	pPlayer->Render();
	cout << "Stage : " << Count << endl;
}

void Stage::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}
