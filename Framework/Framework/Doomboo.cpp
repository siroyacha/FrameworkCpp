#include "Doomboo.h"
#include"CursorManager.h"
#include"Enemy.h"

Doomboo::Doomboo()
{
}

Doomboo::~Doomboo()
{
}

void Doomboo::Start()
{
}

int Doomboo::Update(Transform& _Transfom)
{
	return 0;
}

void Doomboo::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"Doomboo",13);
}

void Doomboo::Release()
{
}
