#pragma once
#include "Headers.h"

class Object;
class ShopManager
{
private:
	static ShopManager* Instance;
public:
	static ShopManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ShopManager;
		return Instance;
	}
private:
	Object* pPlayer;
	Object* pBullet;
private:
	int MaxSize;
	char* Buffer[9];
	char* Buffer2[9];
	char* Buffer3[9];
	int Cursor;
	int Money;
	int Color;
	ULONGLONG Time;

public:
	void Start();
	void Update();
	void Render();
	void Release();
private:
	ShopManager();
public:
	~ShopManager();
};