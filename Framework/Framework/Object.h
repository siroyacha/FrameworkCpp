#pragma once
#include "Headers.h"

class Object
{
private:
	int Time;
public:
	void Start();		// �ʱ�ȭ
	void Update();	// ������� �� �⵹ ���� �̺�Ʈ üũ
	void Render();	// �׸���
	void Release();	//�޸� ����
public:
	Object();
	~Object();
};

