#pragma once
#include "Scene.h"

class Object;
class GameOver :public Scene
{
private:
	int CountDown;
	
	char* Buffer[32];
	int MaxSize;
	int Length;

	Object* pPlayer;

	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	GameOver();
	virtual	~GameOver();
};
