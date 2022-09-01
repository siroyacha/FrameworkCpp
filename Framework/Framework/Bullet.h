#pragma once
#include "Object.h"

class Bridge;
class Bullet : public Object
{
private:
	static Bridge* BridgeList[BULLETID::BULLETID_TYPE_MAX];
private:
	Bridge* pBridge;
	float Speed;
	ULONGLONG Time;
public:
	void SetBridge(Bridge* _Bridge) { pBridge = _Bridge; }
public:
	virtual Object* Start(string _Key)override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Bullet(*this); }
public:
	Bullet();
	Bullet(Transform _Info) :Object(_Info),Speed(0), Time(0), pBridge(nullptr) {};
	virtual ~Bullet();
};
