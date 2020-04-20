#pragma once
#include <iostream>
#include <exception>

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

		static Base* returnOrigin(Base* object); 

		virtual void videoReset(); // if window change render size (VideoMode)
	};
}