#pragma once
#include "Scene.h"

class Object;
class StagetClear :public Scene
{
private:
	char* Buffer[2];
	int Length[2];
	int Cursor;

	char* WordBuffer[32];
	int WordMaxSize;
	int WordLength;

	int Color;
	ULONGLONG Time;

public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	StagetClear();
	virtual	~StagetClear();
};
