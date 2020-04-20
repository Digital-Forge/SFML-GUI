#pragma once
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <Windows.h>

namespace DF
{
	class Window
	{
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
		double getVideoDiagonal();

		void setFPS(unsigned int fps);

		void fullscreen_changer(bool activ);

		void reSize(unsigned int width, unsigned int height);

	};
}