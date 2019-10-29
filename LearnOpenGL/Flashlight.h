#pragma once
#include "Object.h"
#include "Shader.h"

class Camera;

class Flashlight : public Object
{
public:
	Flashlight(Camera* pCamera);
	~Flashlight();
	Shader* pShader;
	Camera* mCamera;
	void Update();
};

