#pragma once
#include "Headers.h"

class UserInterface
{
protected:
	Transform Info;
	string Key;
	vector<string> Texture;
	Vector3 StartPos, EndPos;
public:
	virtual void Start()PURE;
	virtual void Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	void SetBoxSize(int _x, int _y)
	{
		EndPos = Vector3(StartPos.x + _x, StartPos.y + _y);
	}
public:
	UserInterface();
	virtual ~UserInterface();
};
