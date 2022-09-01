#pragma once
#include "Scene.h"

class UserInterface;
class Stage :public Scene
{
private:
	UserInterface* Box;
	char* aaa[10];
	int MaxSize;
	ULONGLONG EnemyTime;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage();
	virtual	~Stage();
};
