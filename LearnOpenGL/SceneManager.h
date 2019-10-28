#pragma once
#include "Object.h"
#include <vector>
#include "Scene.h"

class SceneManager : public Object
{
public:
	SceneManager();
	void Update();
	void LateUpdate();
	std::vector<Scene> scenes;
	static SceneManager* instance;
};
