#pragma once
#include "Object.h"
#include "Shader.h"
#include "Transform.h"
#include "Texture.h"
#include "Mesh.h"

class GameObject : public Object
{
public:
	Transform transform;
	Shader* pShader;
	Texture* pTexture1;
	Texture* pTexture2;
	Mesh* pMesh;
	GameObject();
	~GameObject();
	void Update();
};

