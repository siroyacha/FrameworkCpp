#pragma once
#include "Object.h"


class Player : public Object
{
private:
	int BulletType;
	int SideCounter;	
	ULONGLONG Time;
	int Move_X;
	int Move_Y;
public:
	int GetStageLV() { return Stat.Stage_Lv; }
	void StageLV_Up() { ++Stat.Stage_Lv; }
	int GetScore() { return Stat.Score; }
	void AddScore(int _Scroe) { Stat.Score = Stat.Score + _Scroe; }
	void SetMoney(int _Money) { Stat.Money = Stat.Money + _Money; }
	void SetExp(int _Exp) { Stat.Exp = Stat.Exp + _Exp; }
	int GetBulletType() { return BulletType; }
	int GetMove_X() { return Move_X; }
	int GetMove_Y() { return Move_Y; }
public:
	virtual Object* Start(string _Key)override;
	virtual int  Update()override;
	virtual void Render()override;
	virtual void Release()override;
	virtual Object* Clone()override { return new Player(*this); }
public:
	Player();
	Player(Transform _Info) :Object(_Info) {};
	virtual ~Player();
};
