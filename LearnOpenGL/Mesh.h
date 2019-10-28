#pragma once
#include "Object.h"

class Mesh:public Object
{
public:
	unsigned int VBO, VAO;
	Mesh(float vertexArray[], int vertexArraySize, unsigned int indexs[], int indexArraySize, int stepLength);
	~Mesh();
	void Update();
};

