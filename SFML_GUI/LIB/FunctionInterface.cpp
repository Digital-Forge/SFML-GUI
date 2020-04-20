#include "FunctionInterface.h"

DF::FunctionInterface::FunctionInterface(std::function<void()> function, bool set_delete) :
	class_function(true),
	getDelete(set_delete),
	func(function),
	wsk_fun(NULL)
{
}

DF::FunctionInterface::FunctionInterface(void(*function)(), bool set_delete) :
	class_function(false),
	getDelete(set_delete),
	wsk_fun(function)
{
}

void DF::FunctionInterface::function()
{
	if (class_function)
	{
		func();
	}
	else
	{
		if (wsk_fun != nullptr)
		{
			wsk_fun();
		}
	}
}
