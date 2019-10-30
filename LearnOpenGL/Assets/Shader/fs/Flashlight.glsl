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
uniform vec3 cameraPos;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

void main()
{
	float theta = dot(lightDir, normalize(-light.direction));

	if (theta > light.cutOff)
	{
		float distance = length(light.position - position);
		float attenuation = 1.0 / (constant + light.linear * distance + light.quadratic * distance * distance);
		float3 ambient = light.ambient;
		float3 lightDir = normalize(FragPos - light.position);
		float3 norm = normalize(Normal);
		float diff = max(dot(lightDir, norm), 0.0);
		float3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse,TexCoord));
		float3 viewDir = normalize(FragPos - cameraPos); 
		float ref = reflect(-lightDir, norm);
		float value = pow(max(dot(viewDir, ref), 0.0), material.shininess);
		float3 specular = value * light.specular * vec3(texture(material.specular, TexCoord));
		FragColor = vec4((ambient + diffuse + specular) * attenuation, 1.0);
	}
	else
	{
		FragColor = vec4(light.ambient * vec3(texture(material.diffuse, TexCoords)),1.0);
	}
}
