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

public:
	void Start();
	void Release();
	Object* LoadPlayer() { return pPlayer; }
	int GetStageLv();
private:
	StartManager();
public:
	~StartManager();
};
