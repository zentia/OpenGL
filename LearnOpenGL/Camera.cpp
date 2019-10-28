#include "Camera.h"
#include "Application.h"
#include "InputHelper.h"

Camera::Camera()
{
	for (unsigned int i = 0; i < count; i++)
	{
		modelPositions[i] = MakePosition();
		cubePositions[i] = MakePosition();
	}
	pitch = 0;
	yaw = 0;
	roll = 0;
}


Camera::~Camera()
{
	
}

void Camera::Update()
{
	// äÖÈ¾Ö¸Áî
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	gameObject.Update();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, 0.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 view = glm::lookAt(position, position + cameraFront, cameraUp);
	gameObject.pShader->setMatrix4fv("view", view);
	glm::mat4 projection;
	projection = glm::perspective(glm::radians(InputHelper::instance->fov), (float)Application::SCR_WIDTH / (float)Application::SCR_HEIGHT, 0.1f, 1000.0f);
	gameObject.pShader->setMatrix4fv("projection", projection);
	
	gameObject.pMesh->Update();
	for (unsigned int i = 0; i < count; i++)
	{
		model = glm::translate(model, modelPositions[i]);
		float angle = 20.0f * i;
		model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));
		gameObject.pShader->setMatrix4fv("model", model);
		glDrawArrays(GL_TRIANGLES, 0, 36);
	}
	cube.pShader->use();
	cube.pShader->setVec3("viewPos", position);
	
	cube.pShader->setFloat("light.constant", 1.0f);
	cube.pShader->setFloat("light.linear", 0.007);
	cube.pShader->setFloat("light.quadratic", 0.0002);
	for (unsigned int i = 0; i < count; i++)
	{
		model = glm::translate(model, cubePositions[i]);
		cube.pShader->SetModelViewProjection(model, view, projection);
		cube.pShader->setVec3("light.position", light.transform.position);
		cube.Update();
	}

	light.pShader->use();
	model = glm::translate(model, light.transform.position);
	light.pShader->SetModelViewProjection(model, view, projection);
	light.Update();
}

void Camera::LateUpdate()
{
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT))
	{
		float cameraSpeed = 2.50f * Application::instance->deltaTime;
		if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT))
		{
			cameraSpeed *= 10.0f;
		}
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		{
			position += cameraSpeed * cameraFront;
		}
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		{
			position -= cameraSpeed * cameraFront;
		}
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		{
			position -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		}
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		{
			position += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
		}
		float sensitivity = 0.05f;
		float xoffset = InputHelper::instance->xoffset * sensitivity;
		float yoffset = InputHelper::instance->yoffset * sensitivity;
		yaw += xoffset;
		pitch -= yoffset;
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
		direction.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		direction.y = sin(glm::radians(pitch));
		direction.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
		cameraFront = glm::normalize(direction);
	}
}