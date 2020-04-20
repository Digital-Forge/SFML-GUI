#include "Test.h"

Test::Test()
{
	window = new DF::Window(1280, 720, "test");
	a = new DF::Button::Style();
	b1 = new DF::Button(window, 50, 50, 25, 25, new DF::FunctionInterface(std::bind(&Test::fun1, this)), a);
	b2 = new DF::Button(window, 25, 25, 25, 25, new DF::FunctionInterface(std::bind(&Test::fun2, this)));
	
	wsk = b1;
}

Test::~Test()
{
	delete a;
	delete b1;
	delete b2;
	delete window;
}

void Test::loop()
{
	window->open();

	while (window->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window->_getWindow()->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window->_getWindow()->close();
		}

		wsk->event();
		b2->event();

		wsk->show();
		b2->show();
		window->display(sf::Color::White);
	}
}

void Test::fun1()
{
	a->setOutlineSize(a->getOutlineSize() + 1.0);
	DF::Button::returnOrigin(wsk)->resetStyle();
}

void Test::fun2()
{
	b2->setActive(false);
	std::cout << "ELO  ";
}
