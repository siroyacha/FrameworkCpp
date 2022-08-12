#include "Type1.h"
#include"Player.h"
#include"StartManager.h"
#include"CursorManager.h"

Type1::Type1():Index(2)
{
}

Type1::~Type1()
{
	Release();
}

void Type1::Start()
{
	pPlayer = StartManager::GetInstance()->LoadPlayer();
	Value.Att = 5 * pPlayer->GetLV();
}

int Type1::Update()
{
	Value.Att = 5 * pPlayer->GetLV();
	return 0;
}

void Type1::Render()
{
}

void Type1::Release()
{
	delete pPlayer;
	pPlayer = nullptr;
}

int Type1::DamegeControl(int _Att)
{
	return 0;
}
