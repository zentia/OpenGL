#pragma once
#include "Object.h"
#include "GameObject.h"
#include "Cube.h"
#include "Light.h"
#include "Flashlight.h"

class Camera : public Object
{
public:
	Camera();
	~Camera();
	glm::vec3 position = glm::vec3(-7.0f, -0.50f, -11.0f);
	glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 direction = glm::normalize(position - cameraTarget);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight = glm::normalize(glm::cross(up, direction));
	glm::vec3 Front = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::cross(direction, cameraRight);
	glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));
	void Update();
	void LateUpdate();
	GameObject gameObject;
	Cube cube;
	Light light;
	Flashlight* mFlashlight;
	const static unsigned int count = 10;
	glm::vec3 modelPositions[count];
	glm::vec3 cubePositions[count];
	float pitch;//µãÍ·
	float yaw; //Ò¡Í·
	float roll; // ·­¹ö
	glm::mat4 GetModelMatrix(glm::vec3 position, glm::vec3 ratation, glm::vec3 scale);
	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
};