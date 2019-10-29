#include "Flashlight.h"

Flashlight::Flashlight(Camera* pCamera)
{
	pShader = new Shader("Flashlight.glsl", "Flashlight.glsl");
	mCamera = pCamera;
}

Flashlight::~Flashlight()
{
	delete pShader;
}

void Flashlight::Update()
{
	pShader->use();
}