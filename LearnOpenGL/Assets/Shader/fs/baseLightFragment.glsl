#version 330 core
  
struct Material {
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

uniform Material material;

struct Light {
	vec3 position;
	//vec3 direction;

	vec3 ambient;
	vec3 diffuse;
	vec3 specular;

	float constant;
	float linear;
	float quadratic;
};

uniform Light light;

out vec4 FragColor;

uniform vec3 viewPos;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

void main()
{
	float distance = length(light.position - FragPos);
	float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * distance * distance);
	// 环境光
	vec3 ambient = light.ambient;
	ambient *= attenuation;
	// 漫反射
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(FragPos - light.position);
	float diff = max(dot(norm,lightDir),0.0);
	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords));
	diffuse *= attenuation;
	// 镜面光
	vec3 viewDir = normalize(viewPos - FragPos);
	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords));
	specular *= attenuation;
	vec3 result = ambient + diffuse + specular;
	FragColor = vec4(result, 1.0);
}