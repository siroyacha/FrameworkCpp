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
	Buffer[0] = (char*)".##..##..##..##..######...####...##..##..######...####............####...##..##..#####...##..##..######..##..##...####...#####....####..";
	Buffer[1] = (char*)".##.##...###.##....##....##......##..##....##....##..............##......##..##..##..##..##..##....##....##..##..##..##..##..##..##.....";
	Buffer[2] = (char*)".####....##.###....##....##.###..######....##.....####............####...##..##..#####...##..##....##....##..##..##..##..#####....####..";
	Buffer[3] = (char*)".##.##...##..##....##....##..##..##..##....##........##..............##..##..##..##..##...####.....##.....####...##..##..##..##......##.";
	Buffer[4] = (char*)".##..##..##..##..######...####...##..##....##.....####............####....####...##..##....##....######....##.....####...##..##...####..";
	Buffer[5] = (char*)"........................................................................................................................................";
	
	Length = strlen(".##..##..##..##..######...####...##..##..######...####............####...##..##..#####...##..##..######..##..##...####...#####....####..");

	MaxSize = 6;

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
	for (int i = 0; i < MaxSize; ++i)
		CursorManager::GetInstance()->WriteBuffer((150.0f / 2) - (Length / 2), 15.0f + i, Buffer[i], 10);
	CursorManager::GetInstance()->WriteBuffer(64.0f, 30.0f, (char*)"Enter 키를 눌러 시작",11);

}

void Logo::Release()
{

}
