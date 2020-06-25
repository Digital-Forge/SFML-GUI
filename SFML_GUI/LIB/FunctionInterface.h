#pragma once
#include <functional>


namespace DF
{
	//typedef FunctionInterface Fun_IF;

	//Intrface to used add (class metods) or functions to oder element 

	template<typename T = void>
	class FunctionInterface;


	template<typename T>
	class FunctionInterface
	{
	private:
		std::function<void(T)> func;

	public:
		const bool getDelete;

		template<typename FUNCTION, typename OBJECT>
		FunctionInterface(FUNCTION&& function, OBJECT&& object, bool set_delete); // use for method with class -> FI(&CLASS::METHOD, &OBJECT)
		FunctionInterface(std::function<void(T)> function, bool set_delete); // use for normal function -> FI(function)

		void function(T arg); // to play functions
	};

	template<>
	class FunctionInterface<void>
	{
	private:
		std::function<void()> func;

	public:
		const bool getDelete;

		template<typename FUNCTION, typename OBJECT>
		FunctionInterface(FUNCTION&& function, OBJECT&& object, bool set_delete); // use for method with class -> FI(&CLASS::METHOD, &OBJECT)
		FunctionInterface(std::function<void()> function, bool set_delete); // use for normal function -> FI(function)

		void function(void); // to play functions
	};
}

//##################################################################################################################################
//##################################################################################################################################
//##################################################################################################################################

template<typename T>
template<typename FUNCTION, typename OBJECT>
inline DF::FunctionInterface<T>::FunctionInterface(FUNCTION&& function, OBJECT&& object, bool set_delete) :
	getDelete(set_delete)
{
	func = std::bind(function, object, std::placeholders::_1);
}

template<typename FUNCTION, typename OBJECT>
inline DF::FunctionInterface<void>::FunctionInterface(FUNCTION&& function, OBJECT&& object, bool set_delete) :
	getDelete(set_delete)
{
	func = std::bind(function, object);
}

template<class T>
inline DF::FunctionInterface<T>::FunctionInterface(std::function<void(T)> function, bool set_delete) :
	getDelete(set_delete),
	func(function)
{
}

inline DF::FunctionInterface<void>::FunctionInterface(std::function<void()> function, bool set_delete) :
	getDelete(set_delete),
	func(function)
{
}

template<typename T>
inline void DF::FunctionInterface<T>::function(T arg)
{
	if(func != nullptr)	func(arg);
}

inline void DF::FunctionInterface<void>::function(void)
{
	if (func != nullptr) func();
}