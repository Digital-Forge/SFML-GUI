#pragma once
#include <iostream>

namespace DF
{
	// Base Item to elementary used
	class Base
	{
	public:
		Base();
		virtual ~Base();

		virtual void event();
		virtual void show(); // drawing element

		virtual Base* returnOrigin(); 

		virtual void videoReset(); // if window change render size (VideoMode)
	};
}