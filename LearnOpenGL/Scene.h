#pragma once
#include "Object.h"
#include "Flashlight.h"

class Scene : public Object
{
public:
	Scene();
	~Scene();
	void Update();
	void LateUpdate();
	Flashlight flashlight;
};

