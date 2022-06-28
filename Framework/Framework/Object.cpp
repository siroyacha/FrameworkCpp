#include "Object.h"


Object::Object()
{
}

Object::~Object()
{
	Release();
}

void Object::Start()
{
	Time = 0;
}

void Object::Update()
{
	++Time;
}

void Object::Render()
{
	cout << Time << endl;
}

void Object::Release()
{
}