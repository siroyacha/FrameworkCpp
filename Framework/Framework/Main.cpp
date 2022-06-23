// ** Framework v.0.3
#include <iostream>

using namespace std;

// ** [Class] 5���� Ư¡(OOP : ��ü ���� ���α׷���)

// ** 1. ���� ����
// ** 2. ĸ��ȭ
// ** 3. ���
// ** 4. �߻�ȭ
// ** 5. ������

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
	Object o2("���� ������");
	Object o3("���� ������", 3);
	Object o4("���� ������", 3.141592f);

	cout << "===============================" << endl;
	*/

	// ** ������
	Parent* p[2];

	p[0] = new Child("Child");
	p[1] = new Object("Object");

	for (int i = 0; i < 2; ++i)
		p[i]->Output();

	return 0;
}