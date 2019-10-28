#include <glad/glad.h>
#include "Common.h"
#include "Shader.h"
#include "Camera.h"
#include "Application.h"
#include "InputHelper.h"
#include "Light.h"
#include "Cube.h"
#include "FileWatcher.h"
#include "SceneManager.h"
#include "Event.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	unsigned int seed = 100;
	srand(seed);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	Object::window = glfwCreateWindow(Application::SCR_WIDTH, Application::SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (Object::window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(Object::window);
	glfwSetFramebufferSizeCallback(Object::window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
		
	glEnable(GL_DEPTH_TEST);

	Object *objects[] = {
		new Camera,
		new Application,
		new InputHelper,
		new Light,
		new SceneManager,
		new Event,
		new FileWatcher,
	};
	unsigned int count = sizeof(objects)/sizeof(void*);
	Event::Register(Event::Type::FileModify, (void*)&Shader::OnFileModify);
	while (!glfwWindowShouldClose(Object::window))
	{
		for (unsigned int i = 0; i < count; i++)
		{
			objects[i]->Update();
		}
		for (unsigned int i = 0; i < count; i++)
		{
			objects[i]->LateUpdate();
		}
		// 检查并调用事件，交换缓冲
		glfwSwapBuffers(Object::window);
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}