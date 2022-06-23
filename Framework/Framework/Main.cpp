// ** Framework v.0.3
#include <iostream>

using namespace std;

// ** [Class] 5가지 특징(OOP : 객체 지향 프로그래밍)

// ** 1. 정보 은닉
// ** 2. 캡슐화
// ** 3. 상속
// ** 4. 추상화
// ** 5. 다형성

/*
class Object
{
public:
	// ** 생성자 & 소멸자 = 별도 호출이 없어도 자동으로 호출 됨
	Object();
	~Object();
	// ================================================
	// ** 복사 생성자 = 사용자가 호출한 경우에만 호출됨

	Object(string _str);
	Object(string _str, int _i);
	Object(string _str, float _f);

private:

};

Object::Object()
{
	// ** 생성자
	cout << "생성자" << endl;
}

Object::~Object()
{
	// ** 소멸자
	cout << "소멸자" << endl;
}

Object::Object(string _str)
{
	// ** 복사 생성자 
	cout << "복사 생성자 : " << _str << endl;
}

Object::Object(string _str, int _i)
{
	cout << _str << " : " << _i << endl;
}

Object::Object(string _str, float _f)
{
	cout << _str << " : " << _f << endl;
}

class Player
{
public:
	Player();
	~Player();

private:

};

Player::Player()
{
}

Player::~Player()
{
}
*/

class Parent
{
protected:
	string Name;
public:
	virtual void Output() = 0;

	Parent() {}
	Parent(string _str) : Name(_str) {}
};
class Child : public Parent
{
public:
	void Output()
	{
		cout << Name << endl;
	}

	Child() {}
	Child(string _str) : Parent(_str) {}
};

class Object : public Parent
{
public:
	void Output()
	{
		cout << Name << endl;
	}

	Object() {}
	Object(string _str) : Parent(_str) {}
};

int main(void)
{
	/*
	Object o;
	Object o2("복사 생성자");
	Object o3("복사 생성자", 3);
	Object o4("복사 생성자", 3.141592f);

	cout << "===============================" << endl;
	*/

	// ** 다형성
	Parent* p[2];

	p[0] = new Child("Child");
	p[1] = new Object("Object");

	for (int i = 0; i < 2; ++i)
		p[i]->Output();

	return 0;
}