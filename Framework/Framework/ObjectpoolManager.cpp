#include "ObjectpoolManager.h"
#include"PrototypeManager.h"
#include"Object.h"
#include"CursorManager.h"
#include"CollisionManager.h"

ObjectpoolManager* ObjectpoolManager::Instance = nullptr;

ObjectpoolManager::ObjectpoolManager()
{
}

ObjectpoolManager::~ObjectpoolManager()
{
}

bool ObjectpoolManager::FindObject(string _Key)
{
	auto iter = DisableList.find(_Key);
	if (iter == DisableList.end())
		return false;
	else
		return true;
}

bool ObjectpoolManager::CheckObject(string _Key)
{
	ULONGLONG Time = 0;
	Time = GetTickCount64();
	auto iter = DisableList.find(_Key);
	int temp_size = iter->second.size();
	if (Time + 5000 < GetTickCount64())
	{
		if (iter->second.size() != temp_size)
			return true;
		else
			return false;
	}
}

bool ObjectpoolManager::CheckingObject(string _Key)
{
	auto iter = DisableList.find(_Key);
	auto iter2 = EnableList.find(_Key);
	if (iter->second.size() > iter2->second.size())
		return true;
	else
		return false;
}

void ObjectpoolManager::AddObject(string _Key)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter == DisableList.end())
	{
		list<Object*> Temp;		
		DisableList.insert(make_pair(_Key, Temp));
		iter = DisableList.find(_Key);
	}

	Object* pProtoObj = PrototypeManager::GetInstance()->FindObject(_Key);
	for (int i = 0; i < 5; ++i)
	{
		if (pProtoObj)
		{
			Object* pObject = pProtoObj->Clone();
			iter->second.push_back(pObject);
		}
		else
		{
			// Err : pProtoObj 에서 객체 원본을 찾을 수 없음
			return;
		}
	}
}

void ObjectpoolManager::LoadObject(string _Key)
{
	map<string, list<Object*>>::iterator iter = EnableList.find(_Key);

	if (iter == EnableList.end())
	{
		list<Object*> Temp;
		EnableList.insert(make_pair(_Key, Temp));
		iter = EnableList.find(_Key);
	}
	Object* pProtoObj = PrototypeManager::GetInstance()->FindObject(_Key);
	for (int i = 0; i < 5; ++i)
	{
		if (pProtoObj)
		{
			Object* pObject = pProtoObj->Clone();
			iter->second.push_back(pObject);
		}
		else
		{
			// Err : pProtoObj 에서 객체 원본을 찾을 수 없음
			return;
		}
	}
}

void ObjectpoolManager::SwitchingObject(string _Key, Vector3 _Position)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);
	if (iter->second.empty())
	{
		AddObject(_Key);
	}
	Object* pObj = iter->second.back();
	pObj->SetPosition(_Position);

	EnableList[_Key].push_back(pObj);
	iter->second.pop_back();
}

void ObjectpoolManager::SwitchingObject2(string _Key, Vector3 _Position)
{
	map<string, list<Object*>>::iterator iter = EnableList.find(_Key);
	if (iter->second.empty())
	{
		LoadObject(_Key);
	}
	Object* pObj = iter->second.back();
	pObj->SetPosition(_Position);

	DisableList[_Key].push_back(pObj);
	iter->second.pop_back();
}

void ObjectpoolManager::Update()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end();)
		{
			int Result = (*iter2)->Update();

			if (Result)
			{
				DisableList[(*iter2)->GetKey()].push_back((*iter2));
				iter2 = iter->second.erase(iter2);
			}
			else
				++iter2;			
		}
	}
	if (DisableList.size() < 50)
	{
		DisableList.clear();
	}
	/*
	auto Citer = EnableList.find("Enemy");
	if (Citer != EnableList.end())
	{
		if (CollisionManager::RectCollision())
		{

		}
	}
	*/
}

void ObjectpoolManager::Render()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			(*iter2)->Render();
		}
	}
}
