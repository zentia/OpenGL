#pragma once
#include "Common.h"

class Object
{
public:
	Object();
	virtual ~Object();
	virtual void Update();
	virtual void LateUpdate();

	static GLFWwindow *window;
};

