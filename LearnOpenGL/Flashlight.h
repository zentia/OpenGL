#pragma once
#include "Object.h"
#include "Shader.h"

class Flashlight : public Object
{
public:
	Flashlight();
	~Flashlight();
	Shader* pShader;
};

