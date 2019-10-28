#pragma once
#include "Object.h"
#include <list>

class Shader : public Object
{
public:
	Shader(const std::string vertexFile,const std::string fragmentFile);
	~Shader();
	void Reload();
	void use();
	unsigned int ID;
	unsigned int vertexShader;
	unsigned int fragmentShader;
	void setBool(const std::string& name, bool value);
	void setInt(const std::string& name, int value);
	void setFloat(const std::string& name, float value);
	void setFloat3(const std::string& name, float x, float y, float z);
	void setFloat4(const std::string& name, float x, float y, float z, float w);
	void setMatrix4fv(const std::string& name, glm::mat4 &value);
	void setVec3(const std::string& name, glm::vec3& value);
	void SetModelViewProjection(glm::mat4& model, glm::mat4& view, glm::mat4& projection);
	void Update();
	std::string vertexFileName;
	std::string fragmentFileName;
	static const char* vsRootDir;
	static const char* fsRootDir;
	static void OnFileModify(const char* path);
	static std::list<Shader*> shaderList;
};

