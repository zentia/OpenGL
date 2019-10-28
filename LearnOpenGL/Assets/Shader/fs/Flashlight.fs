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
	float cutOff;// �й��

	vec3 diffuse;
	vec3 ambient;
	vec3 specular;

	// ˥��
	float constant; // ����
	float linear;//һ����
	float quadratic; // ������
};

uniform Light light;

in vec3 position;
in vec3 normal;
in vec2 TexCoord;

void main()
{
	FragColor = vec4(1.0f,1.0f,1.0f,1.0f);
} 
