#pragma once
#include"Headers.h"

class Bridge;
class BPattenManager
{
private:
	static BPattenManager* Instance;
public:
	static BPattenManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new BPattenManager;
		return Instance;
	}
private:
	map<string, Bridge*> BridgeList;
public:
	void Initialize();
	Bridge* FindBridge(string _Key);
private:
	BPattenManager();
public:
	~BPattenManager();
};