#pragma once
#include "Object.h"
#include "Shader.h"
#include "Transform.h"
#include "Mesh.h"
#include "Texture.h"

class Cube : public Object
{
public:
	Mesh* pMesh;
	Shader* pShader;
	Transform transform;
	Texture* pDiffuseTexture;
	Texture* pSpecularTexture;
	Cube();
	~Cube();
	void Update();
};

