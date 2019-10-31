#pragma once
#include "Object.h"

class Transform : public Object
{
public:
	glm::vec3 position;
	glm::vec3 ratation;
	glm::vec3 scale;

	glm::vec3 localPosition;
	glm::vec3 localRatation;
	glm::vec3 localScale;
	Transform();
};

