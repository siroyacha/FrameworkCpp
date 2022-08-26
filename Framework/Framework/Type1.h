#pragma once
#include"EnemyBridge.h"

class Type1 : public EnemyBridge
{
public:
	virtual void Start()override;
	virtual int Update(Transform& _Transfom)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Bridge* Clone()override;
public:
	Type1();
	virtual ~Type1();
};
