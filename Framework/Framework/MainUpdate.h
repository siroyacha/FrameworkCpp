#pragma once
#include "Headers.h"

class Object;
class MainUpdate
{
private:
	Object* pPlayer;
public:
	void Start();		// �ʱ�ȭ
	void Update();	// ������� �� �⵹ ���� �̺�Ʈ üũ
	void Render();	// �׸���
	void Release();	//�޸� ����
public:
	MainUpdate();
	~MainUpdate();
};

