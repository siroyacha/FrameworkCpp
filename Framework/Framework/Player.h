#pragma once
#include "Object.h"

class Bullet;
class Player : public Object
{
private:
	float X_Shift;
	float Y_Shift;
	int Lv_Check;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual int DamegeControl(int _Att)override;
public:
	Player();
	virtual ~Player();
};
