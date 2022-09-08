#pragma once
#include"EnemyBridge.h"

class Type3 : public EnemyBridge
{
public:
	virtual void Start()override;
	virtual int Update(Transform& _Transfom)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Bridge* Clone()override
	{
		return new Type3(*this);
	}
public:
	Type3();
	virtual ~Type3();
};
