#pragma once
#include"Bullet.h"

class Object;
class Type1:public Bullet
{
private:
	int Index;
	ULONGLONG Time;
	float Speed;

	Object* pPlayer;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual int DamegeControl(int _Att)override;
public:
	Type1();
	virtual ~Type1();
};

