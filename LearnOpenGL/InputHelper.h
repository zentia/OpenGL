#pragma once
#include "Object.h"

class InputHelper : public Object
{
public:
	InputHelper();
	static void MouseCallback(GLFWwindow *window,double xpos,double ypos);
	static void ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	double xpos;
	double ypos;
	float xoffset;
	float yoffset;
	bool firstMouse;
	float fov;
	static InputHelper* instance;
};

