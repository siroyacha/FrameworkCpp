#pragma once

// ** Singleton
// ** 1. 관리자 형태-두개의 관리자로 인한 충돌 방지 가능
// ** 1. 단일 인스턴스로 구성됨. (인스턴스가 여러개로 주성되지 않음)
// ** 2. 어디에서나 호출 가능
class Singleton
{
private:
	static Singleton* Instance;
public:
	static Singleton* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new Singleton;
		}
		return Instance;
	}
private:
	string SceneState;
private:
	Singleton() { }
public:
	~Singleton() { }
};
