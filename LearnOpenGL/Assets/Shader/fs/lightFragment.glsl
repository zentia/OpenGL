#version 330 core
out vec4 FragColor;

struct Light
{
	vec3 position;
	vec4 direction;
	float cutOff;
};



void main()
{
	FragColor = vec4(1.0);
} 