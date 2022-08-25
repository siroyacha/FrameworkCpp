#pragma once
#include"Headers.h"

class Object;
class Bridge
{
protected:
	Object* pObject;
public:
	void SetObject(Object* _Object) { pObject = _Object; }
public:
	virtual Bridge* Start(string _Key)PURE;
	virtual int Update(Transform& _Transfom)PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual Bridge* Clone()PURE;
public:
	Bridge() : pObject(nullptr) {}
	virtual ~Bridge() {}
};