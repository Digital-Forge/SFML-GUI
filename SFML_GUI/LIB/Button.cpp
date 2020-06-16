#include "Button.h"


DF::Button::Style::Style():
	active_rect_color(0xC6C6C6FF),
	inactive_rect_color(0xDDDDDD80),
	active_outline_color(sf::Color::Black),
	inactive_outline_color(sf::Color::Black),
	outline_size(0.0)
{
}

DF::Button::Style::~Style()
{
}

DF::Button::Style DF::Button::defoult_style;

void DF::Button::Style::setActiveColor(sf::Color color)
{
	active_rect_color = color;
}

sf::Color DF::Button::Style::getActiveColor()
{
	return active_rect_color;
}

void DF::Button::Style::setActiveOutlineColor(sf::Color color)
{
	active_outline_color = color;
}

sf::Color DF::Button::Style::getActiveOutlineColor()
{
	return active_outline_color;
}

void DF::Button::Style::setInActiveColor(sf::Color color)
{
	inactive_rect_color = color;
}

sf::Color DF::Button::Style::getInActiveColor()
{
	return inactive_rect_color;
}

void DF::Button::Style::setInActiveOutlineColor(sf::Color color)
{
	inactive_outline_color = color;
}

sf::Color DF::Button::Style::getInActiveOutlineColor()
{
	return inactive_outline_color;
}

void DF::Button::Style::setOutlineSize(double size)
{
	outline_size = size;
}

double DF::Button::Style::getOutlineSize()
{
	return outline_size;
}

void DF::Button::Style::setStyle(Button* object)
{
	object->rect.setOutlineThickness(outline_size * object->window->getVideoDiagonal() * 0.01);

	if (object->active)
	{
		object->rect.setFillColor(active_rect_color);
		object->rect.setOutlineColor(active_outline_color);
	}
	else
	{
		object->rect.setFillColor(inactive_rect_color);
		object->rect.setOutlineColor(inactive_outline_color);
	}
}

DF::Button::Button(Window* window, double x, double y, double w, double h, FunctionInterface<>* function, Button::Style* style) :
	Element(window, x, y, w, h),
	graphic_config(style),
	fun_IF(nullptr),
	buff(false)
{
	if (function == nullptr)
	{
		fun_IF = new FunctionInterface<>(nullptr, true);
	}
	else
	{
		fun_IF = function;
	}

	videoReset();
	resetStyle();
}

DF::Button::~Button()
{
	if (fun_IF->getDelete)
	{
		delete fun_IF;
	}
}

void DF::Button::event()
{
	if (active && visible && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		if (!buff)
		{
			buff = true;
			mouse_poz = window->_getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*window->_getWindow()));

			if ((mouse_poz.x > (rect.getPosition().x - (rect.getSize().x * 0.5)) && mouse_poz.x < (rect.getPosition().x + (rect.getSize().x * 0.5)))
				&& (mouse_poz.y > (rect.getPosition().y - (rect.getSize().y * 0.5)) && mouse_poz.y < (rect.getPosition().y + (rect.getSize().y * 0.5))))
			{
				fun_IF->function();
			}
		}
	}
	else
	{
		buff = false;
	}
}

void DF::Button::show()
{
	if (visible)
	{
		window->_getWindow()->draw(rect);
	}
}

DF::Button* DF::Button::returnOrigin(Base* object)
{
	Button* to_origin;
	to_origin = dynamic_cast<Button*>(object);

	if (to_origin == nullptr)
	{
		return nullptr;
	}
	else
	{
		return to_origin;
	}
}

void DF::Button::videoReset()
{
	rect.setSize(sf::Vector2f(window->getVideoWidth() * (w * 0.01), window->getVideoHeight() * (h * 0.01)));
	rect.setOrigin(rect.getSize().x * 0.5, rect.getSize().y * 0.5);
	rect.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));
	rect.setOutlineThickness(graphic_config->outline_size * window->getVideoDiagonal() * 0.01);
}

void DF::Button::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
	rect.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));
}

void DF::Button::move(double x, double y)
{
	this->x += x;
	this->y += y;
	rect.setPosition(window->getVideoWidth() * (this->x * 0.01), window->getVideoHeight() * (this->y * 0.01));
}

void DF::Button::setActive(bool a)
{
	active = a;
	graphic_config->setStyle(this);
}

void DF::Button::setSize(double width, double height)
{
	w = width;
	h = height;
	rect.setSize(sf::Vector2f(window->getVideoWidth() * (w * 0.01), window->getVideoHeight() * (h * 0.01)));
	rect.setOrigin(rect.getSize().x * 0.5, rect.getSize().y * 0.5);
}

bool DF::Button::isPress()
{
	if (active && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		if (!buff)
		{
			buff = true;
			mouse_poz = window->_getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*window->_getWindow()));

			if ((mouse_poz.x > (rect.getPosition().x - (rect.getSize().x * 0.5)) && mouse_poz.x < (rect.getPosition().x + (rect.getSize().x * 0.5)))
				&& (mouse_poz.y > (rect.getPosition().y - (rect.getSize().y * 0.5)) && mouse_poz.y < (rect.getPosition().y + (rect.getSize().y * 0.5))))
			{
				return true;
			}
		}
	}
	else
	{
		buff = false;
	}
	return false;
}

void DF::Button::resetStyle()
{
	graphic_config->setStyle(this);
}

void DF::Button::setStyle(Button::Style* style)
{
	graphic_config = style;
	resetStyle();
}

void DF::Button::setFunction(FunctionInterface<>* function)
{
	if (fun_IF->getDelete)
	{
		delete fun_IF;
	}
	fun_IF = function;
}