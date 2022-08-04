#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	int Index;
	ULONGLONG Time;
	float Speed;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual int DamegeControl(int _Att)override;
public:
	void SetIndex(int _Index) { Index = _Index; }
public:
	Bullet();
	virtual ~Bullet();
};

