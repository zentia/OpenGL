#pragma once
#include "Object.h"
#include "Shader.h"
#include "Mesh.h"
#include "Transform.h"
#include "Texture.h"

class Camera;

class Flashlight : public Object
{
public:
	Flashlight(Camera* pCamera);
	~Flashlight();
	Shader* pShader;
	Camera* mCamera;
	Mesh* pMesh;
	Texture* pDiffuse;
	Texture* pSpecular;
	Transform transform;
	void Update();
};

