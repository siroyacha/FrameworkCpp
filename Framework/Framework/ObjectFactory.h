#pragma once
#include"Headers.h"

class ObjectFactory
{
public:
	static Object* CreatePlayer()
	{
		Object* pObject = new Player;
		pObject->Start();

		return pObject;
	}

	static Object* CreateBullet()
	{
		Object* pObject = new Bullet;
		pObject->Start();

		return pObject;
	}
	static Object* CreateBullet(Vector3 _Position)
	{
		Object* pObject = new Bullet;

		pObject->Start();
		pObject->SetPosition(_Position);

		return pObject;
	}

	// ** Enemy
	static Object* CreateEnemy()
	{
		Object* pObject = new Enemy;
		pObject->Start();

		return pObject;
	}

	static Object* CreateEnemy(Vector3 _Position)
	{
		Object* pObject = new Enemy;

		pObject->Start();
		pObject->SetPosition(_Position);

		return pObject;
	}

	static Object* CreateItem()
	{
		Object* pObject = new Item;
		pObject->Start();

		return pObject;
	}
	static Object* CreateItem(Vector3 _Position)
	{
		Object* pObject = new Item;

		pObject->Start();
		pObject->SetPosition(_Position);

		return pObject;
	}
};