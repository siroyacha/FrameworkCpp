#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
	Object* Target;
	Infomation Value;
public:
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual int DamegeControl(int _Att)PURE;

public:
	Transform GetTransform() const { return Info; }
	Vector3 GetPosition() const { return Info.Position; }
	void SetPosition(Vector3 _Position) { Info.Position = _Position; }
	void SetPosition(float _x, float _y) { Info.Position = Vector3(_x, _y); }

	void SetDirection(Vector3 _Direction) { Info.Direction = _Direction; }
	void SetDirection(float _x, float _y) { Info.Direction = Vector3(_x, _y); }
	void SetTarget(Object* _Target) { Target = _Target; }

	int GetMoney() const { return Value.Money; }
	void SetMoney(int _Money) { Value.Money += _Money; }
	int GetDamege() const { return Value.Att; }

	int GetExp() const { return Value.Exp; }
	void SetExp(int _Exp) { Value.Exp += _Exp; }
	int GetHP() { return Value.Hp; }
	int GetLV() { return Value.Lv; }

public:
	Object();
	virtual ~Object();
};


