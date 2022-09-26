#pragma once
#include "Headers.h"

class UserInterface;
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
	Object* pBullet;
private:
	int MaxSize;
	int NowSize;
	float Percent;

	vector<Object*> pSkillList;
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