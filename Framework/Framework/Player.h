#pragma once
#include "Object.h"

class Bullet;
class Player : public Object
{
private:
	float X_Shift;
	float Y_Shift;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Player();
	virtual ~Player();
};
