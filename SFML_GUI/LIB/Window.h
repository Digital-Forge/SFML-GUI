#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Element.h"
#include "Util.hpp"

extern class Element;

namespace DF
{
	class Window
	{
		friend class Element;
	protected:
		sf::VideoMode vm;
		std::string title;
		bool fullscreen;
		sf::RenderWindow* window;

	public:
		// base options
		Window(unsigned int width, unsigned int height, sf::String titel);
		~Window();

		void open();
		bool isOpen();
		void display(sf::Color color = sf::Color::Black);

		sf::RenderWindow* _getWindow();

		// more option
		unsigned int getVideoWidth();
		unsigned int getVideoHeight();

		void setFPS(unsigned int fps);

		void fullscreen_changer(bool activ);

		void reSize(unsigned int width, unsigned int height);

	};
}