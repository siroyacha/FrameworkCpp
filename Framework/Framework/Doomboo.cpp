#include "Doomboo.h"
#include"CursorManager.h"
#include"Enemy.h"

Doomboo::Doomboo()
{
}

Doomboo::~Doomboo()
{
}

Bridge* Doomboo::Start(string _Key)
{
	return nullptr;
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

Bridge* Doomboo::Clone()
{
	return nullptr;
}
