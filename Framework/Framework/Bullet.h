#pragma once
#include "Object.h"

class Bridge;
class Bullet : public Object
{
private:
	Bridge* pBBridge;
	float Speed;
	ULONGLONG Time;
public:
	void SetBridge(Bridge* _Bridge) { pBBridge = _Bridge; }
public:
	virtual void Start()override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Bullet();
	virtual ~Bullet();
};
