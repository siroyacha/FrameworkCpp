#pragma once
#include"EnemyBridge.h"

class Type2 : public EnemyBridge
{
public:	
	virtual void Start()override;
	virtual int Update(Transform& _Transfom)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Bridge* Clone()override
	{
		return new Type2(*this);
	}
public:
	Type2();
	virtual ~Type2();
};
