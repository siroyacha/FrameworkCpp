#include "Goolops.h"
#include"CursorManager.h"
#include"Enemy.h"

Goolops::Goolops()
{
}

Goolops::~Goolops()
{
}

void Goolops::Start()
{
}

int Goolops::Update(Transform& _Transfom)
{
	return 0;
}

void Goolops::Render()
{
	CursorManager::GetInstance()->WriteBuffer(
		pObject->GetPosition(), (char*)"Goolops",10);
}

void Goolops::Release()
{
}
