#version 330 core

out vec4 FragColor;

in vec4 ourColor;
in vec2 TexCoord;

struct Light{
	vec3 position;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

uniform Light light;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{

	FragColor = mix(texture(texture1,TexCoord), texture(texture2, TexCoord), 0.2);
}