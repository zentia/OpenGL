#include "Transform.h"

Transform::Transform()
{
	position = MakePosition();
	scale = glm::vec3(1.0f);
}