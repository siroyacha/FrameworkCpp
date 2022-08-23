#pragma once
#include "Enemy.h"

class EType1 : public Enemy
{
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	EType1();
	virtual ~EType1();
};
