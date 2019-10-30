#pragma once
#include "Object.h"

class Renderer : public Object
{
public:
	glm::mat4 worldToLocalMatrix();
};

