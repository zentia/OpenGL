#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	vec4 pos = model * vec4(aPos.x,aPos.y,aPos.z,1.0);
	FragPos = vec3(pos);
	gl_Position = projection * view * pos;
	TexCoord = aTexCoord;
}