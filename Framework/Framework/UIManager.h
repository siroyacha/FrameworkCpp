#pragma once
#include "Headers.h"

class Object;
class UIManager
{
private:
	static UIManager* Instance;
public:
	static UIManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new UIManager;
		return Instance;
	}
private:
	Object* pPlayer;
private:
	int MaxSize;
	/*
	char* Buffer[9];
	char* Buffer2[9];
	char* Buffer3[9];
	int Cursor;

	int Color;
	ULONGLONG Time;
	*/
public:
	void Start();
	void Update();
	void Render();
	void Release();
private:
	UIManager();
public:
	~UIManager();
};