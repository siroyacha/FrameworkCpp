#pragma once
#include"EnemyBridge.h"

class Mutant : public EnemyBridge
{
public:	
	virtual Bridge* Start(string _Key)override;
	virtual int Update(Transform& _Transfom)override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Bridge* Clone()override;
public:
	Mutant();
	virtual ~Mutant();
};
