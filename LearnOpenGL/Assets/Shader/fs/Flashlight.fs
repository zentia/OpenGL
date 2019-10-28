#version 330 core

struct Material
{
	sampler diffuse;
	sampler specular;
	float shininess;
};

uniform Material material;

struct Light
{
	vec3 position;
	vec3 direction;
	float cutOff;// 切光角

	vec3 diffuse;
	vec3 ambient;
	vec3 specular;

	// 衰减
	float constant; // 常量
	float linear;//一次项
	float quadratic; // 二次项
};

uniform Light light;

in vec3 position;
in vec3 normal;
in vec2 TexCoord;

void main()
{
	FragColor = vec4(1.0f,1.0f,1.0f,1.0f);
} 
