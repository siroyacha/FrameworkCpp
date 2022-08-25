#include "BPattenManager.h"
#include"Doomboo.h"
#include"Mutant.h"
#include"Goolops.h"
BPattenManager* BPattenManager::Instance = nullptr;

BPattenManager::BPattenManager()
{
}

BPattenManager::~BPattenManager()
{
}

void BPattenManager::Initialize()
{
	Transform Info;

	Info.Position = Vector3(0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f);
	Info.Direction = Vector3(0.0f, 0.0f);

	string Key = "";

	Key = "Enemy";
	BridgeList[Key] = (new Mutant)->Start(Key);

	Key = "Player";
	BridgeList[Key] = (new Goolops)->Start(Key);

	Key = "Bullet";
	BridgeList[Key] = (new Doomboo)->Start(Key);
}

Bridge* BPattenManager::FindBridge(string _Key)
{
	map<string, Bridge*>::iterator iter = BridgeList.find(_Key);

	if (iter == BridgeList.end())
		return nullptr;
	else
		return iter->second;
}
