#pragma once
#include "Headers.h"

class Object;
class StartManager
{
private:
	static StartManager* Instance;
public:
	static StartManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new StartManager;
		return Instance;
	}
private:
	Object* pPlayer;
	Object* pBullet;

public:
	void Start();
	void Release();
	Object* LoadPlayer() { return pPlayer; }
	Object* LoadBullet() { return pBullet; }
	int GetStageLv();
private:
	StartManager();
public:
	~StartManager();
};
