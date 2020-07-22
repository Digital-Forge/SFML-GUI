#include "Line.h"

DF::Line::Line(Window* window, double x1, double y1, double x2, double y2, Line::Style* style) :
	Element(window,x1,y1,x2,y2),
	graphic_config(style)
{
	videoReset();
}

DF::Line::~Line()
{
}

void DF::Line::show()
{
	if (visible)
	{
		window->_getWindow()->draw(rect);
	}
}

DF::Line* DF::Line::returnOrigin(Base* object)
{
	Line* to_origin;
	to_origin = dynamic_cast<Line*>(object);
	return to_origin;
}

void DF::Line::videoReset()
{
	rect.setSize(sf::Vector2f(sqrt(pow(fabs((window->getVideoWidth() * x * 0.01) - (window->getVideoWidth() * w * 0.01)), 2) + pow(fabs((window->getVideoHeight() * y * 0.01) - (window->getVideoHeight() * h * 0.01)), 2)), window->getVideoDiagonal() * graphic_config->thickness * 0.01));
	rect.setOrigin(0, rect.getOrigin().y * 0.5);

	if (x > w)
	{
		rect.setRotation(180.0 + atan(((h - y) * window->getVideoHeight()) / ((w - x) * window->getVideoWidth())) * (180.0 / M_PI));
	}
	else
	{
		rect.setRotation(atan(((h - y) * window->getVideoHeight()) / ((w - x) * window->getVideoWidth())) * (180.0 / M_PI));
	}

	rect.setPosition(window->getVideoWidth() * x * 0.01, window->getVideoHeight() * y * 0.01);

	graphic_config->setStyle(this);
}

void DF::Line::setPosition(double x1, double y1, double x2, double y2)
{
	x = x1;
	y = y1;
	w = x2;
	h = y2;
	videoReset();
}

void DF::Line::move(double x, double y)
{
	this->x += x;
	this->y += y;
	w += x;
	h += y;
	videoReset();
}

void DF::Line::setActive(bool a)
{
	active = a;
	graphic_config->setStyle(this);
}

void DF::Line::resetStyle()
{
	videoReset();
}

DF::Line::Style::Style() :
	active_rect_color(sf::Color::Black),
	inactive_rect_color(sf::Color::Black),
	active_outline_color(sf::Color::Black),
	inactive_outline_color(sf::Color::Black),
	thickness(0.5),
	outline_size(0.0)
{
}

DF::Line::Style::~Style()
{
}

DF::Line::Style DF::Line::defoult_style;

void DF::Line::Style::setActiveColor(sf::Color color)
{
	active_rect_color = color;
}

sf::Color DF::Line::Style::getActiveColor()
{
	return active_rect_color;
}

void DF::Line::Style::setActiveOutlineColor(sf::Color color)
{
	active_outline_color = color;
}

sf::Color DF::Line::Style::getActiveOutlineColor()
{
	return active_outline_color;
}

void DF::Line::Style::setInActiveColor(sf::Color color)
{
	inactive_rect_color = color;
}

sf::Color DF::Line::Style::getInActiveColor()
{
	return inactive_rect_color;
}

void DF::Line::Style::setInActiveOutlineColor(sf::Color color)
{
	inactive_outline_color = color;
}

sf::Color DF::Line::Style::getInActiveOutlineColor()
{
	return inactive_outline_color;
}

void DF::Line::Style::setLineThickness(double size)
{
	thickness = size;
}

double DF::Line::Style::getLineThickness()
{
	return thickness;
}

void DF::Line::Style::setOutlineSize(double size)
{
	outline_size = size;
}

double DF::Line::Style::getOutlineSize()
{
	return outline_size;
}

void DF::Line::Style::setStyle(Line* object)
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