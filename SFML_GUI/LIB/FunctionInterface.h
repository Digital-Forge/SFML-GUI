#pragma once
#include <functional>

namespace CK
{
	//typedef FunctionInterface Fun_IF;

	//Intrface to used add (class metods) or functions to oder element 

	class FunctionInterface
	{
	private:
		//all
		bool class_function;

		//class functions
		std::function<void()> func;

		//other functions
		void(*wsk_fun)();

	public:
		const bool getDelete;

		FunctionInterface(std::function<void()> function, bool set_delete = true); // use -> FI(std::bind(&CLASS::METHOD, &OBJECT))
		FunctionInterface(void (*function)(), bool set_delete = true);

		void function(); // to play functions
	};
}

