#pragma once
#include "Scene.h"

class Pause :public Scene
{
public:
	virtual void Start()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Pause();
	virtual	~Pause();
};

