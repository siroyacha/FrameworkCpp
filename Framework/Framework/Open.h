#pragma once
#include "Scene.h"

class Open :public Scene
{
private:
	ULONGLONG Time;
	int Counter;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Open();
	virtual	~Open();
};
