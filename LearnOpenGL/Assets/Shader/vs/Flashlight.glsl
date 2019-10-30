#version 330 core
layout (location = 0) vec3 aVertex;
layout (location = 1) vec3 aNormal;
layout (location = 2) vec2 aTexCoord;

uniform vec3 model;
uniform vec3 view;
uniform vec3 projection;

out vec3 FragPos;
out vec3 Normal;
out vec2 TexCoord;

void main()
{
	FragPos = model * aVertex;
	gl_Position = projection * view * position;
	Normal = aNormal;
	TexCoord = aTexCoord;
}