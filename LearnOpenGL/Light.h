#pragma once
#include "Object.h"
#include "Shader.h"
#include "Mesh.h"
#include "Transform.h"

class Light : public Object
{
public:
	
	Shader* pShader;
	Mesh* pMesh;
	Transform transform;
	Light();
	~Light();
	void Update();
};

