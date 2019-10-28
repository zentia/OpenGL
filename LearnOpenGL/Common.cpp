#include "Common.h"
float randf(int value)
{
	value = value - rand() % (2 * value);
	return value;
}
float x = 0;
float y = 0;
float z = 0;
glm::vec3 MakePosition()
{
	x = x + 0.5;
	if (x > 3)
	{
		x = 0;
		y += 0.5;
	}
	return glm::vec3(x, y, z);
}

