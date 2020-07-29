#include "Rect.h"

DF::Rect::Rect(Window* window, double x, double y, double w, double h, Rect::Style* style) :
	Element(window,x,y,w,h),
	graphic_config(style)
{
	videoReset();
}

DF::Rect::~Rect()
{
}

void DF::Rect::show()
{
	if (visible)
	{
		window->_getWindow()->draw(rect);
	}
}

DF::Rect* DF::Rect::returnOrigin(Base* object)
{
	Rect* to_origin;
	to_origin = dynamic_cast<Rect*>(object);
	return to_origin;
}

void DF::Rect::videoReset()
{
	rect.setSize(sf::Vector2f(window->getVideoWidth() * w * 0.01, window->getVideoHeight() * h * 0.01));
	rect.setOrigin(rect.getSize().x * 0.5, rect.getSize().y * 0.5);
	rect.setPosition(window->getVideoWidth() * x * 0.01, window->getVideoHeight() * y * 0.01);

	graphic_config->setStyle(this);
}

void DF::Rect::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
	videoReset();
}

void DF::Rect::move(double x, double y)
{
	this->x += x;
	this->y += y;
	videoReset();
}

void DF::Rect::setActive(bool a)
{
	active = a;
	graphic_config->setStyle(this);
}

void DF::Rect::resetStyle()
{
	graphic_config->setStyle(this);
}

void DF::Rect::setSize(double w, double h)
{
	this->w = w;
	this->h = h;
}

DF::Rect::Style::Style() :
	active_rect_color(0xBABABAFF),
	inactive_rect_color(0x5A5A5A88),
	active_outline_color(sf::Color::Black),
	inactive_outline_color(sf::Color::Black),
	outline_size(0.5)
{
}

DF::Rect::Style::~Style()
{
}

DF::Rect::Style DF::Rect::defoult_style;

void DF::Rect::Style::setActiveColor(sf::Color color)
{
	active_rect_color = color;
}

sf::Color DF::Rect::Style::getActiveColor()
{
	return active_rect_color;
}

void DF::Rect::Style::setActiveOutlineColor(sf::Color color)
{
	active_outline_color = color;
}

sf::Color DF::Rect::Style::getActiveOutlineColor()
{
	return active_outline_color;
}

void DF::Rect::Style::setInActiveColor(sf::Color color)
{
	inactive_rect_color = color;
}

sf::Color DF::Rect::Style::getInActiveColor()
{
	return inactive_rect_color;
}

void DF::Rect::Style::setInActiveOutlineColor(sf::Color color)
{
	inactive_outline_color = color;
}

sf::Color DF::Rect::Style::getInActiveOutlineColor()
{
	return inactive_outline_color;
}

void DF::Rect::Style::setOutlineSize(double size)
{
	outline_size = size;
}

double DF::Rect::Style::getOutlineSize()
{
	return outline_size;
}

void DF::Rect::Style::setStyle(Rect* object)
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