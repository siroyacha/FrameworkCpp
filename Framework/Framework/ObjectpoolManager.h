#pragma once
#include"Headers.h"

class Object;
class ObjectpoolManager
{
private:
	static ObjectpoolManager* Instance;
public:
	static ObjectpoolManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectpoolManager;
		return Instance;
	}
private:
	map<string, list<Object*>> EnableList;
	map<string, list<Object*>> DisableList;
public:
	bool FindObject(string _Key);
	void AddObject(string _Key);
	void SwitchingDObject(string _Key);
	void SwitchingEObject(string _Key);
	void Update();
	void Render();
private:
	ObjectpoolManager();
public:
	~ObjectpoolManager();
};