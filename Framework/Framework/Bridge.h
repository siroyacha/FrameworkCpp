#pragma once
#include"Headers.h"

class Object;
class Bridge
{
protected:
	Object* pObject;
	Infomation Dumy;
public:
	void SetObject(Object* _Object) { pObject = _Object; }
public:
	virtual void Start()PURE;
	virtual int Update(Transform& _Transfom)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Bridge* Clone()PURE;
public:
	Bridge() : pObject(nullptr) {}
	virtual ~Bridge() {}
};