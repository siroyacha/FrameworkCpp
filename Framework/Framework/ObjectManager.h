#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager;
		return Instance;
	}
private:
	Object* pPlayer;
	Object* pEnemy[32];
	Object* pEBullet[128];
	Object* pPBullet[128];
	Object* pItem[128];
	ULONGLONG EnemyTimer = GetTickCount64();

public:
	void CreateObject(int _StateIndex);
	void CreatePlayerObject(int _StateIndex, int dwKey, float _X_Shift, float _Y_Shift);
	void Start();
	void Update();
	void Render();
	void Release();
	Object* LoadPlayer() { return pPlayer; }
private:
	ObjectManager();
public:
	~ObjectManager();
};

