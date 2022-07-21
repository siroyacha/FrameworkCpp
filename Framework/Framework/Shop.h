#pragma once
#include "Scene.h"

class Shop :public Scene
{
private:
	int MaxSize;
	char* Buffer[4];
	int Length[4];
	int Cursor;

	int Color;
	ULONGLONG Time;
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Shop();
	virtual	~Shop();
};
