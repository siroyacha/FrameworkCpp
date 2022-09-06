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
	HeightTexture = (char*)("��");

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
		WidthTexture += "��";
		EndPos = Vector3(StartPos.x + Width, StartPos.y + Height);
	}
	// ** �»�
	CursorManager::GetInstance()->WriteBuffer(StartPos.x, StartPos.y, "��");

	CursorManager::GetInstance()->WriteBuffer(StartPos.x+2, StartPos.y, WidthTexture);
	// ** ���
	CursorManager::GetInstance()->WriteBuffer(EndPos.x, StartPos.y, "��");
	// ** ����
	CursorManager::GetInstance()->WriteBuffer(StartPos.x, EndPos.y, "��");

	CursorManager::GetInstance()->WriteBuffer(StartPos.x+2, EndPos.y, WidthTexture);
	// ** ����
	CursorManager::GetInstance()->WriteBuffer(EndPos.x, EndPos.y, "��");
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
	char temp[] = "��";
	for (vector<string>::iterator iter = Texture.begin(); iter != Texture.end(); ++iter)
	{
		string::iterator iter2 = iter->begin() + 2;
		iter->insert(iter2, temp[0]);
		iter->insert(iter2 + 1, temp[1]);

		CursorManager::GetInstance()->WriteBuffer(50, 1 + n, (*iter));
		++n;

		// ** ���ڿ� ���� �Լ�
		// string.substr(���� �ε���, �����ε������� ���� �� ���ڿ��� ������)
		//CursorManager::GetInstance()->WriteBuffer(50, 2 + i, str);
	}
}

void ScrollBox::Release()
{
}
