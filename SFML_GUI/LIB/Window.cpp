#include "Window.h"

DF::Window::Window(unsigned int width, unsigned int height, sf::String titel) :
	vm(width, height),
	title(title),
	fullscreen(false),
	window(new sf::RenderWindow())
{
}

DF::Window::~Window()
{
	if (window != nullptr)
	{
		delete window;
	}
}

void DF::Window::open()
{
	if (!window->isOpen())
	{
		window->create(vm, title, sf::Style::Default);
	}
}

bool DF::Window::isOpen()
{
	return window->isOpen();
}

void DF::Window::display(sf::Color color)
{
	window->display();
	window->clear(color);
}

sf::RenderWindow* DF::Window::_getWindow()
{
	return window;
}

unsigned int DF::Window::getVideoWidth()
{
	return vm.width;
}

unsigned int DF::Window::getVideoHeight()
{
	return vm.height;
}

void DF::Window::setFPS(unsigned int fps)
{
	window->setFramerateLimit(fps);
}

void DF::Window::fullscreen_changer(bool activ)
{
	if (window->isOpen())
	{
		MONITORINFO info;
		info.cbSize = sizeof(MONITORINFO);
		GetMonitorInfo(MonitorFromWindow(window->getSystemHandle(), MONITOR_DEFAULTTONEAREST), &info);
		if (activ)
		{
			fullscreen = true;
			window->create(vm, title, sf::Style::None);
			window->setSize(sf::Vector2u(info.rcMonitor.right - info.rcMonitor.left, info.rcMonitor.bottom - info.rcMonitor.top));
			window->setPosition(sf::Vector2i(info.rcMonitor.left, info.rcMonitor.top));
			SetWindowPos(window->getSystemHandle(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
		}
		else
		{
			fullscreen = false;
			window->create(vm, title, sf::Style::Default);
			window->setSize(sf::Vector2u((info.rcMonitor.right - info.rcMonitor.left) * 0.5, (info.rcMonitor.bottom - info.rcMonitor.top) * 0.5));
			window->setPosition(sf::Vector2i(info.rcMonitor.left + ((info.rcMonitor.right - info.rcMonitor.left) * 0.25), info.rcMonitor.top + ((info.rcMonitor.bottom - info.rcMonitor.top) * 0.25)));
			SetWindowPos(window->getSystemHandle(), HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
		}
	}
}

void DF::Window::reSize(unsigned int width, unsigned int height)
{
	vm.width = width;
	vm.height = height;
	if (fullscreen)
	{
		fullscreen_changer(true);
	}
	else
	{
		fullscreen_changer(false);
	}
}
