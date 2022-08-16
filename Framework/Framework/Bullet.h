#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	int Index;
	ULONGLONG Time;
	BulletType Type[5];
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual int DamegeControl(int _Index)override;
public:
	void SetIndex(int _Index) { Index = _Index; }
	int GetIndex() { return Index; }
	void BulletSeting(int _Att);
	int GetBulletDamage();
	void BulletLVUP(int _Index);
	int GetBulletLV(int _Index) { return Type[_Index].LV; }
public:
	Bullet();
	virtual ~Bullet();
};

