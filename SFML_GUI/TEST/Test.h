#pragma once
#include "LIB/Window.h"
#include "LIB/Button.h"

class Test
{
	DF::Button::Style* a;
	DF::Window* window;

	DF::Button* b1;
	DF::Button* b2;

	DF::Base* wsk;

public:
	Test();
	~Test();
	void loop();

	void fun1();

	void fun2();
};

