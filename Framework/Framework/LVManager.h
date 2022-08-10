#pragma once
#include "Headers.h"

class Object;
class LVManager
{
private:
	static LVManager* Instance;
public:
	static LVManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new LVManager;
		return Instance;
	}
private:
	Object* pEnemy;
public:
	void EnemyUp(int Stage_Lv);
	void DeleteLvManager();
private:
	LVManager();
public:
	~LVManager();
};
