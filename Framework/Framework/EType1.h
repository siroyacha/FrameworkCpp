#pragma once
#include"EnemyBridge.h"

class EType1 : public EnemyBridge
{
public:
	virtual void Start()override;
	virtual int Update(Transform& _Transfom)override;
	virtual void Render()override;
	virtual void Release()override;
public:
	EType1();
	virtual ~EType1();
};