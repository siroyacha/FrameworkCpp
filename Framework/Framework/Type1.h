#pragma once
#include"Bullet.h"

class Type1:public Object
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
	Type1();
	virtual ~Type1();
};

