#include "SceneManager.h"

SceneManager* SceneManager::instance = NULL;

SceneManager::SceneManager()
{
	instance = this;
	Scene scene;
	scenes.push_back(scene);
}

void SceneManager::Update()
{
	for (auto i = scenes.begin(); i != scenes.end(); ++i)
	{
		i->Update();
	}
}

void SceneManager::LateUpdate()
{
	for (auto i = scenes.begin(); i != scenes.end(); ++i)
	{
		i->LateUpdate();
	}
}