#pragma once
#include"Bridge.h"

class EnemyBridge :public Bridge
{
public:
	virtual Bridge* Start(string _Key)PURE;
	virtual int Update(Transform& _Transfom)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Bridge* Clone()PURE;
public:
	EnemyBridge() {}
	virtual ~EnemyBridge() {}
};