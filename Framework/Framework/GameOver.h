#pragma once
#include "Scene.h"

class GameOver :public Scene
{
private:
	int CountDown;

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
