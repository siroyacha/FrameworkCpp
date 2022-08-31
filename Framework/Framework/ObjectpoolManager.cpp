#include "ObjectpoolManager.h"
#include"PrototypeManager.h"
#include"Object.h"

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
	{
		if (iter == DisableList.end())
			return false;		
		else
			return true;
	}
}

void ObjectpoolManager::AddObject(string _Key)
{
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter == DisableList.end())
	{
		list<Object*> Temp;
		Object* pProtoObj = PrototypeManager::GetInstance()->FindObject(_Key);
		for (int i = 0; i < 5; ++i)
		{
			if (pProtoObj)
			{
				Object* pObject = pProtoObj->Clone();
				Temp.push_back(pObject);
				DisableList.insert(make_pair(_Key, Temp));
			}
			else
			{
				// Err : pProtoObj 에서 객체 원본을 찾을 수 없음
				return;
			}
		}
	}
	else
	{
		// ** 리스트는 존재하지만 객체가 없는 상태 확인
		if (iter->second.empty())
		{
			// 크리에이트 오브젝트 써서 만들어보기
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
	}
	// ** 여기까지 도달했다면 여분의 객체가 생성된 것이므로 
	// ** DisableList -> EnableList 이동.
	SwitchingDObject(_Key);
}

void ObjectpoolManager::SwitchingDObject(string _Key)
{
	// 디스에이블에서 인에이블로
	map<string, list<Object*>>::iterator iter = DisableList.find(_Key);

	if (iter == DisableList.end())
	{
		AddObject(_Key);
	}
	else
	{
		for (int i = 0; i < iter->second.size(); ++i)
		{
			list<Object*> Temp;
			Temp.push_back(iter->second.front());
			EnableList.insert(make_pair(_Key, Temp));
			iter->second.pop_front();
		}
	}
}

void ObjectpoolManager::SwitchingEObject(string _Key)
{
	// 인에이블에서 디스에이블로
	map<string, list<Object*>>::iterator iter = EnableList.find(_Key);

	if (iter == EnableList.end())
	{
		Update();
	}
	else
	{
		for (int i = 0; i < iter->second.size(); ++i)
		{
			list<Object*> Temp;
			Temp.push_back(iter->second.front());
			DisableList.insert(make_pair(_Key, Temp));
			iter->second.pop_front();
		}
	}
}

void ObjectpoolManager::Update()
{
	for (auto iter = EnableList.begin(); iter != EnableList.end(); ++iter)
	{
		for (auto iter2 = iter->second.begin(); iter2 != iter->second.end(); ++iter2)
		{
			int Result = (*iter2)->Update();

			if (Result)
			{
				//SwitchingObject((*iter2));
				iter2 = iter->second.erase(iter2);
			}
			else
				++iter2;
		}
	}
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
