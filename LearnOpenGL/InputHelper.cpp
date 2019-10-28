#include "InputHelper.h"
#include "Application.h"

InputHelper::InputHelper()
{
	instance = this;
	xpos = Application::SCR_WIDTH/2;
	ypos = Application::SCR_HEIGHT/2;
	xoffset = 0;
	yoffset = 0;
	firstMouse = true;
	fov = 0;
	glfwSetCursorPosCallback(window, MouseCallback);
	glfwSetScrollCallback(window, ScrollCallback);
}

void InputHelper::MouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (instance->firstMouse)
	{
		instance->xpos = xpos;
		instance->ypos = ypos;
		instance->firstMouse = false;
	}
	instance->xoffset = xpos - instance->xpos;
	instance->yoffset = ypos - instance->ypos;
	instance->xpos = xpos;
	instance->ypos = ypos;
}

void InputHelper::ScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	float fov = instance->fov;
	if (fov >= 1.0f && fov <= 45.0f)
	{
		fov -= yoffset;
	}
	if (fov <= 1.0f)
		fov = 1.0f;
	if (fov >= 45.0f)
		fov = 45.0f;
	instance->fov = fov;
}

InputHelper* InputHelper::instance = NULL;