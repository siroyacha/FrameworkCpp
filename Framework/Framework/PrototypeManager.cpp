#include "PrototypeManager.h"
#include"Enemy.h"
#include"Player.h"
#include"Bullet.h"
#include"Item.h"

PrototypeManager* PrototypeManager::Instance = nullptr;

PrototypeManager::PrototypeManager()
{
}

PrototypeManager::~PrototypeManager()
{
}

void PrototypeManager::Initialize()
{
	Transform Info;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	string Key = "";

	Key = "Enemy";
	ObjectList[Key] = (new Enemy(Info))->Start(Key);

	Key = "Player";
	ObjectList[Key] = (new Player(Info))->Start(Key);

	Key = "Bullet";
	ObjectList[Key] = (new Bullet(Info))->Start(Key);

	Key = "Item";
	ObjectList[Key] = (new Item(Info))->Start(Key);
}

Object* PrototypeManager::FindObject(string _Key)
{
	map<string, Object*>::iterator iter = ObjectList.find(_Key);

	if (iter == ObjectList.end())
		return nullptr;
	else
		return iter->second;
}
