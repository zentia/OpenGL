#pragma once
#include "Object.h"
class Application : public Object
{
public:
	static Application* instance;
	Application();
	~Application();
	float deltaTime = 0.0f;
	float lastFrame = 0.0f;
	const static unsigned int SCR_WIDTH = 1200;
	const static unsigned int SCR_HEIGHT = 800;
	void Update();
};

