#include "Event.h"

Event* Event::instance = NULL;

Event::Event()
{
	instance = this;
}

void Event::Push(Event::Type type, ...)
{
	
}

void Event::Dispatch(Event::Type type, ...)
{
	va_list args = NULL;
	switch (type)
	{
	case Event::Type::FileModify:
	{
		unsigned int n = 1;

		va_start(args, n);
		WCHAR* name = va_arg(args, WCHAR*);

	}

	break;
	default:
		break;
	}

	va_end(args);
}

void Event::Register(Event::Type type, void* callback)
{

}