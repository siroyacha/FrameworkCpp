#pragma once
#include"Bridge.h"

class EnemyBridge :public Bridge
{
protected:
	char* Texture[3];
	int Color;
public:
	char* GetTexture(int _i) { return Texture[_i]; }
	int GetColor() { return Color; }
public:
	virtual void Start()PURE;
	virtual int Update(Transform& _Transfom)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Bridge* Clone()PURE;
public:
	EnemyBridge() {}
	virtual ~EnemyBridge() {}
};