#pragma once
#include "Object.h"

// bullet¿¡¼­ °¡Á®¿È
class Item : public Object
{
private:
	int Index;
	ULONGLONG Time;
public:
	virtual Object* Start(string _Key)override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Item(*this); }
public:
	void SetIndex(int _Index) { Index = _Index; }
public:
	Item();
	Item(Transform _Info) :Object(_Info) {};
	virtual ~Item();
};