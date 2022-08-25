#pragma once
#include"EnemyBridge.h"

class Goolops: public EnemyBridge
{
public:
	virtual Bridge* Start(string _Key)override;
	virtual int Update(Transform& _Transfom)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Bridge* Clone()override;
public:
	Goolops();
	virtual ~Goolops();
};