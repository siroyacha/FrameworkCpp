#include "ScrollBox.h"
#include"CursorManager.h"

ScrollBox::ScrollBox() :Width(0), Height(0)
{
}

ScrollBox::~ScrollBox()
{
}

void ScrollBox::Start()
{
	Key = "ScrollBox";
	/*
	Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f, 0.0f);
	*/

	Width = 2;
	Height = 1;

	StartPos = Vector3(50, 10);
	EndPos = Vector3(StartPos.x + Width, StartPos.y + Height);
	
	WidthTexture = "";
	HeightTexture = (char*)("│");

	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";
	int length = int(str.size() / 2) + 1;
}

void ScrollBox::Update()
{
}

void ScrollBox::Render()
{
	/*
	if (GetAsyncKeyState(VK_CONTROL))
	{
		++Height;
		Width += 2;
		WidthTexture += "─";
		EndPos = Vector3(StartPos.x + Width, StartPos.y + Height);
	}
	// ** 좌상
	CursorManager::GetInstance()->WriteBuffer(StartPos.x, StartPos.y, "┌");

	CursorManager::GetInstance()->WriteBuffer(StartPos.x+2, StartPos.y, WidthTexture);
	// ** 우상
	CursorManager::GetInstance()->WriteBuffer(EndPos.x, StartPos.y, "┐");
	// ** 좌하
	CursorManager::GetInstance()->WriteBuffer(StartPos.x, EndPos.y, "└");

	CursorManager::GetInstance()->WriteBuffer(StartPos.x+2, EndPos.y, WidthTexture);
	// ** 우하
	CursorManager::GetInstance()->WriteBuffer(EndPos.x, EndPos.y, "┘");
	for (int y = StartPos.y + 1; y < EndPos.y; ++y)
	{
		CursorManager::GetInstance()->WriteBuffer(StartPos.x, y, HeightTexture);
		CursorManager::GetInstance()->WriteBuffer(EndPos.x, y, HeightTexture);
	}
	*/


	/*
	*/
	if (GetAsyncKeyState(VK_CONTROL))
	{
		auto iter = Texture.begin() + 1;
		Texture.insert(iter, (*iter));
	}

	int n = 0;
	char temp[] = "─";
	for (vector<string>::iterator iter = Texture.begin(); iter != Texture.end(); ++iter)
	{
		string::iterator iter2 = iter->begin() + 2;
		iter->insert(iter2, temp[0]);
		iter->insert(iter2 + 1, temp[1]);

		CursorManager::GetInstance()->WriteBuffer(50, 1 + n, (*iter));
		++n;

		// ** 문자열 추출 함수
		// string.substr(시작 인덱스, 시작인덱스부터 추출 할 문자열의 사이즈)
		//CursorManager::GetInstance()->WriteBuffer(50, 2 + i, str);
	}
}

void ScrollBox::Release()
{
}
