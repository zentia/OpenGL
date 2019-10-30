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
	GameObject();
	~GameObject();
	void Update();
};

