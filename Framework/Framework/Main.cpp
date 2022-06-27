// ** Framework v.0.5
#include <iostream>
#include <Windows.h>

using namespace std;

// ** [Class] 5���� Ư¡(OOP : ��ü ���� ���α׷���)

// ** 1. ���� ����
// ** 2. ĸ��ȭ
// ** 3. ���
// ** 4. �߻�ȭ
// ** 5. ������

// ** ���� ���� �Լ��� �Լ��� ���������� ����� �����ؼ� �ȵ�
// ** �����ε� = �Ű������� ���� � �Լ��� ȣ������ ����
// ** �������̵� = ��Ӱ����� Ŭ�������� Ŭ������ ������ �ٸ��� ����

// ** [&] ��� �뵵
// ** 1. 2�� ������
// **   - & <- 1���� ���� [��Ʈ ����]
// **   - && <- 2�� ���� [�� ���� & �� ����]

// ** 2. ���� ������
// **   - &���� <- ���� ���ʿ� ������ [ �ּ� ��ȯ ������]
// **   - �ڷ���(����)& <- �ڷ��� ���ʿ� ���� ��� [���۷��� ������]


/*
class Object
{
public:
	// ** ������ & �Ҹ��� = ���� ȣ���� ��� �ڵ����� ȣ�� ��
	Object();
	~Object();
	// ================================================
	// ** ���� ������ = ����ڰ� ȣ���� ��쿡�� ȣ���

	Object(string _str);
	Object(string _str, int _i);
	Object(string _str, float _f);

private:

};

Object::Object()
{
	// ** ������
	cout << "������" << endl;
}

Object::~Object()
{
	// ** �Ҹ���
	cout << "�Ҹ���" << endl;
}

Object::Object(string _str)
{
	// ** ���� ������ 
	cout << "���� ������ : " << _str << endl;
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

// ** �����ε� & �������̵�

class Parent // �߻� Ŭ����
{
protected:
	string Name;
public://												���� : �����ε�
	virtual void Output()PURE; // <������������������������ 
	virtual void Output(string _str)PURE; // <�������������� <����������������������������������������������������
//																																											   ��
	Parent() {}//																																						   ��
	Parent(string _str) : Name(_str) {}//																													   ��
};//																																										   ��
//																																							   [���� : ���� ���̵�]
class Child : public Parent//																																	   ��
{//																																											   ��
public://																												���� : �����ε�						  	   ��
	virtual void Output() override { cout << "Child : " << Name << endl; } // <��������������������������				   ��
	virtual void Output(string _str) override { cout << "Child : " << Name << endl; } // <����������������   <����������
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
	Object o2("���� ������");
	Object o3("���� ������", 3);
	Object o4("���� ������", 3.141592f);

	cout << "===============================" << endl;
	*/

	/*
	// ** ������
	Parent* p[2];

	p[0] = new Child("Child");
	p[1] = new Object("Object");

	for (int i = 0; i < 2; ++i)
		p[i]->Output();
	*/

	/*
	Parent* p[3];

	p[0] = new Child("ȫ�浿");
	p[1] = new Object("�Ӳ���");
	p[2] = new A("�̸���");


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