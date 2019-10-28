#pragma once
#include "Object.h"
#include <queue>
#include <vector>

class Event : public Object
{
public:
	enum class Type
	{
		FileModify,
		Count,
	};
	
	std::vector<void*> mEvent[(unsigned int)(Type::Count)];
	Event();
	static void Push(Type type, ...);
	static void Dispatch(Type type, ...);
	static void Register(Type type, void * callback);
	static Event* instance;
};

