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
public:
	Object* GetPlayer() const { return pPlayer; }
	void SetPlayer(Object* _Object) { pPlayer = _Object; }
public:
	//void CollisionObject(string _Key, string _Key2);
	void AddObject(string _Key);
	void AddObject(Vector3 _Position, string _Key);
	void Update();
	void Render();
	void Release();
private:
	ObjectManager();
public:
	~ObjectManager();
};
