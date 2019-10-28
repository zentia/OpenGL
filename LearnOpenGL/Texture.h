#pragma once
#include "Object.h"

class Texture : public Object
{
public:
	Texture(const std::string path, int format, int index);
	unsigned int ID;
	int activeIndex;
	void Update();
	static const char* rootDir;
};
