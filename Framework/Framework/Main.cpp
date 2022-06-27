// ** Framework v.0.5
#include <iostream>
#include <Windows.h>

using namespace std;

// ** [Class] 5가지 특징(OOP : 객체 지향 프로그래밍)

// ** 1. 정보 은닉
// ** 2. 캡슐화
// ** 3. 상속
// ** 4. 추상화
// ** 5. 다형성

// ** 순수 가상 함수는 함수는 존재하지만 기능은 존재해선 안됨
// ** 오버로딩 = 매개변수를 통해 어떤 함수를 호출할지 결정
// ** 오버라이딩 = 상속관계의 클래스에서 클래스의 영역이 다를떄 결정

// ** [&] 사용 용도
// ** 1. 2항 연산자
// **   - & <- 1번만 쓰면 [비트 연산]
// **   - && <- 2번 쓰면 [비교 연산 & 논리 연산]

// ** 2. 단항 연산자
// **   - &변수 <- 변수 앞쪽에 붙으면 [ 주소 반환 연산자]
// **   - 자료형(형태)& <- 자료형 뒷쪽에 붙은 경우 [레퍼런스 연산자]


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

/*
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
*/

/*
struct Vector3
{
	float x, y, z;

	Vector3() {}

	Vector3(float _x, float _y) : x(_x), y(_y), z(0) {}

	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {}
};

// ** 오버로딩 & 오버라이딩

class Parent // 추상 클래스
{
protected:
	string Name;
public://												관계 : 오버로딩
	virtual void Output()PURE; // <───────────┐ 
	virtual void Output(string _str)PURE; // <──────┘ <─────────────────────────┐
//																																											   │
	Parent() {}//																																						   │
	Parent(string _str) : Name(_str) {}//																													   │
};//																																										   │
//																																							   [관계 : 오버 라이딩]
class Child : public Parent//																																	   │
{//																																											   │
public://																												관계 : 오버로딩						  	   │
	virtual void Output() override { cout << "Child : " << Name << endl; } // <────────────┐				   │
	virtual void Output(string _str) override { cout << "Child : " << Name << endl; } // <───────┘   <────┘
	void Input() {  }
public:
	Child() {}
	Child(string _str) : Parent(_str) {}
};


class A : public Child
{
public:
	virtual void Output() override { cout << "A : " << Name << endl; }
	virtual void Output(string _str) override { cout << "A : " << Name << endl; }
public:
	A() {}
	A(string _str) : Child(_str) {}
};

class Object : public Parent
{
public:
	virtual void Output() { cout << "Object : " << Name << endl; }
	virtual void Output(string _str) override { cout << "Object : " << Name << endl; }
public:
	Object() {}
	Object(string _str) : Parent(_str) {}
};
*/

/*
class Object
{
private:
	int Number;
public:
	Object();
	Object(int _number) : Number(_number) {};
	~Object();
	Object& operator+=(Object& _obj)
	{
		this->Number += _obj.Number;
		return (*this);
	}
	Object& operator+=(int _Number)
	{
		this->Number += _Number;
		return (*this);
	}

	Object& operator+(int _Number)
	{
		Object Temp = Object(this->Number + _Number);
		return Temp;
	}
	Object& operator+(Object& _obj1)
	{
		Object Temp = Object(this->Number + _obj1.Number);
		return Temp;
	}
	Object& operator/ (Object& _obj1)
	{
		this->Number /=  _obj1.Number;
		return (*this);
	}

	Object& operator++ ( )
	{
		this->Number++;
		return (*this);
	}

	Object& operator<< (Object& _obj1)
	{
		this->Number = this->Number << _obj1.Number;
		return (*this);
	}

	Object& operator>>(int _Number)
	{
		this->Number = this->Number >> _Number;
		return (*this);
	}

	int  GetNumber() { return Number; }

};

Object::Object()
{
}
Object::~Object()
{
}
*/

int main(void)
{
	/*
	Object o;
	Object o2("복사 생성자");
	Object o3("복사 생성자", 3);
	Object o4("복사 생성자", 3.141592f);

	cout << "===============================" << endl;
	*/

	/*
	// ** 다형성
	Parent* p[2];

	p[0] = new Child("Child");
	p[1] = new Object("Object");

	for (int i = 0; i < 2; ++i)
		p[i]->Output();
	*/

	/*
	Parent* p[3];

	p[0] = new Child("홍길동");
	p[1] = new Object("임꺽정");
	p[2] = new A("이몽룡");


	p[0]->Output();
	p[1]->Output();

	p[2]->Output();
	*/
	
	/*
	Object o1(1), o2(2);
	Object o3;
	
	o1 += o2;
	cout << o1.GetNumber() << endl;

	o1 += 7;
	cout << o1.GetNumber() << endl;

	o1 / o2;
	cout << o1.GetNumber() << endl;

	++o1;
	cout << o1.GetNumber() << endl;

	o1 << o2;
	cout << o1.GetNumber() << endl;

	o1 >> 2;
	cout << o1.GetNumber() << endl;

	o3 = o1 + 7;
	cout << o3.GetNumber() << endl;
	cout << o1.GetNumber() << endl;

	o3 = o1 + o2;
	cout << o3.GetNumber() << endl;
	cout << o1.GetNumber() << endl;
	*/

	return 0;
}