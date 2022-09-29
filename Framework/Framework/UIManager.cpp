#include "UIManager.h"
#include"Player.h"
#include"Bullet.h"
#include "SceneManager.h"
#include "InputManager.h"
#include"CursorManager.h"
#include"ObjectManager.h"
#include"StartManager.h"
#include "Skill.h"


UIManager* UIManager::Instance = nullptr;

UIManager::UIManager() :pPlayer(nullptr),MaxSize(0),NowSize(0)
{
}

UIManager::~UIManager()
{
}

void UIManager::Start()
{
	pPlayer = ObjectManager::GetInstance()->GetPlayer();
	for (int i = 0; i < Max; ++i)
	{
		Object* pSkill = new Skill;
		pSkill->SetPosition(10, 5);
		pSkill->Start("Skill");

		pSkillList.push_back(pSkill);
	}
}

void UIManager::Update()
{
	for (vector<Object*>::iterator iter = pSkillList.begin(); iter != pSkillList.end(); ++iter)
	{
		(*iter)->Update();
	}
}

void UIManager::Render()
{
	for (vector<Object*>::iterator iter = pSkillList.begin(); iter != pSkillList.end(); ++iter)
	{
		(*iter)->Render();
	}
}

void UIManager::Release()
{ 

}
