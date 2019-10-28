#include "Mesh.h"

Mesh::Mesh(float vertices[], int verticesSize, unsigned int indexArray[], int indexArraySize, int stepLength)
{
	
	// °ó¶¨VAO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, verticesSize, vertices, GL_STATIC_DRAW);
	
	glBindVertexArray(VAO);

	int offset = 0;
	for (int i = 0; i < indexArraySize; i++)
	{
		glVertexAttribPointer(i, indexArray[i], GL_FLOAT, GL_FALSE, stepLength * sizeof(float), (void*)(offset * sizeof(float)));
		glEnableVertexAttribArray(i);
		offset += indexArray[i];
	}
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void Mesh::Update()
{
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}