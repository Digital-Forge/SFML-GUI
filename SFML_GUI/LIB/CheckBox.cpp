#include "CheckBox.h"

DF::CheckBox::Style::Style() :
	active_rect_color(0xC6C6C6FF),
	inactive_rect_color(0xDDDDDD80),
	active_outline_color(sf::Color::Black),
	inactive_outline_color(sf::Color::Black),
	active_symbol_color(0x00FF00FF),
	inactive_symbol_color(0x00FF0099),
	outline_size(2.0),
	symbol_size(15.0),
	symbol_scale(0.9),
	symbol_angle_ray_left(46),
	symbol_angle_ray_right(299)
{
}

DF::CheckBox::Style::~Style()
{
}

DF::CheckBox::Style DF::CheckBox::defoult_style;

void DF::CheckBox::Style::setActiveColor(sf::Color color)
{
	active_rect_color = color;
}

sf::Color DF::CheckBox::Style::getActiveColor()
{
	return active_rect_color;
}

void DF::CheckBox::Style::setActiveOutlineColor(sf::Color color)
{
	active_outline_color = color;
}

sf::Color DF::CheckBox::Style::getActiveOutlineColor()
{
	return active_outline_color;
}

void DF::CheckBox::Style::setInActiveColor(sf::Color color)
{
	inactive_rect_color = color;
}

sf::Color DF::CheckBox::Style::getInActiveColor()
{
	return inactive_rect_color;
}

void DF::CheckBox::Style::setInActiveOutlineColor(sf::Color color)
{
	inactive_outline_color = color;
}

sf::Color DF::CheckBox::Style::getInActiveOutlineColor()
{
	return inactive_outline_color;
}

void DF::CheckBox::Style::setActiveSymbolColor(sf::Color color)
{
	active_symbol_color = color;
}

sf::Color DF::CheckBox::Style::getActiveSymbolColor()
{
	return active_symbol_color;
}

void DF::CheckBox::Style::setInActiveSymbolColor(sf::Color color)
{
	inactive_symbol_color = color;
}

sf::Color DF::CheckBox::Style::getInActiveSymbolColor()
{
	return inactive_symbol_color;
}

void DF::CheckBox::Style::setOutlineSize(double size)
{
	outline_size = size;
}

double DF::CheckBox::Style::getOutlineSize()
{
	return outline_size;
}

void DF::CheckBox::Style::setSymbolSize(double size) 
{
	symbol_size = size;
}

double DF::CheckBox::Style::getSymbolSize()
{
	return symbol_size;
}

void DF::CheckBox::Style::setSymbolRayScale(double scale)
{
	symbol_scale = scale;
}

double DF::CheckBox::Style::getSymbolRayScale()
{
	return symbol_scale;
}

void DF::CheckBox::Style::setSymbolRayLeftAngle(double angle)
{
	symbol_angle_ray_left = angle;
}

double DF::CheckBox::Style::setSymbolRayLeftAngle()
{
	return symbol_angle_ray_left;
}

void DF::CheckBox::Style::setSymbolRayRightAngle(double angle)
{
	symbol_angle_ray_right = angle;
}

double DF::CheckBox::Style::setSymbolRayRightAngle()
{
	return symbol_angle_ray_right;
}

void DF::CheckBox::Style::setStyle(CheckBox* object)
{
	object->rect.setOutlineThickness(outline_size);
	object->symbol[0].setOutlineThickness(0.0);
	object->symbol[1].setOutlineThickness(0.0);

	if (object->active)
	{
		object->rect.setFillColor(active_rect_color);
		object->rect.setOutlineColor(active_outline_color);
		object->symbol[0].setFillColor(active_symbol_color);
		object->symbol[1].setFillColor(active_symbol_color);
	}
	else
	{
		object->rect.setFillColor(inactive_rect_color);
		object->rect.setOutlineColor(inactive_outline_color);
		object->symbol[0].setFillColor(inactive_symbol_color);
		object->symbol[1].setFillColor(inactive_symbol_color);
	}
}

DF::CheckBox::CheckBox(Window* window, double x, double y, double size, FunctionInterface<bool>* function, CheckBox::Style* style) :
	Button(window, x, y, size, size, new DF::FunctionInterface<>(&CheckBox::checkExecute, this, true)),
	graphic_config(style),
	fun_IF(nullptr),
	check(false)
{
	if (function == nullptr)
	{
		fun_IF = new FunctionInterface<bool>(nullptr, true);
	}
	else
	{
		fun_IF = function;
	}

	resetStyle();
}

DF::CheckBox::~CheckBox()
{
	if (fun_IF->getDelete)
	{
		delete fun_IF;
	}
}

void DF::CheckBox::show()
{
	Button::show();

	if (visible && check)
	{
		window->_getWindow()->draw(symbol[0]);
		window->_getWindow()->draw(symbol[1]);
	}
}

DF::CheckBox* DF::CheckBox::returnOrigin(Base* object)
{
	CheckBox* to_origin;
	to_origin = dynamic_cast<CheckBox*>(object);

	if (to_origin == nullptr)
	{
		return nullptr;
	}
	else
	{
		return to_origin;
	}
}

void DF::CheckBox::videoReset()
{
	rect.setSize(sf::Vector2f(window->getVideoDiagonal() * (w * 0.01), window->getVideoDiagonal() * (h * 0.01)));
	rect.setOrigin(rect.getSize().x * 0.5, rect.getSize().y * 0.5);
	rect.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));
	rect.setOutlineThickness(graphic_config->outline_size * window->getVideoDiagonal() * 0.01);

	symbol[0].setSize(sf::Vector2f(sqrt(((double)rect.getSize().x * 0.5) * ((double)rect.getSize().x * 0.5) + ((double)rect.getSize().y * 0.5) * ((double)rect.getSize().y * 0.5)) * graphic_config->symbol_scale,
		(sqrt(((double)rect.getSize().x * (double)rect.getSize().x) + ((double)rect.getSize().y * (double)rect.getSize().y)) * graphic_config->getSymbolSize() * 0.01)));

	symbol[1].setSize(sf::Vector2f(sqrt((((double)rect.getSize().x * 0.5) * ((double)rect.getSize().x * 0.5)) + ((double)rect.getSize().y * (double)rect.getSize().y)) * graphic_config->symbol_scale,
		(sqrt(((double)rect.getSize().x * (double)rect.getSize().x) + ((double)rect.getSize().y * (double)rect.getSize().y)) * graphic_config->getSymbolSize() * 0.01)));

	symbol[0].setOrigin(symbol[0].getSize().x, 0);
	symbol[1].setOrigin(0, symbol[1].getSize().y);

	symbol[0].setPosition(rect.getPosition().x + (rect.getSize().x * 0.05), rect.getPosition().y + (rect.getSize().y * 0.42));
	symbol[1].setPosition(rect.getPosition().x + (rect.getSize().x * 0.05), rect.getPosition().y + (rect.getSize().y * 0.42));

	symbol[0].setRotation(graphic_config->symbol_angle_ray_left);
	symbol[1].setRotation(graphic_config->symbol_angle_ray_right);
}

void DF::CheckBox::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
	videoReset();
}

void DF::CheckBox::move(double x, double y)
{
	this->x += x;
	this->y += y;
	videoReset();
}

void DF::CheckBox::setActive(bool a)
{
	active = a;
	resetStyle();
}

void DF::CheckBox::setSize(double size)
{
	w = size;
	h = size;
	videoReset();
}

void DF::CheckBox::resetStyle()
{
	videoReset();
	graphic_config->setStyle(this);
}

void DF::CheckBox::setStyle(CheckBox::Style* style)
{
	graphic_config = style;
}

void DF::CheckBox::setFunction(FunctionInterface<bool>* function)
{
	if (fun_IF->getDelete)
	{
		delete fun_IF;
	}
	fun_IF = function;
}

bool DF::CheckBox::isCheck()
{
	return check;
}

void DF::CheckBox::setCheck(bool status)
{
	check = status;
	fun_IF->function(check);
}

void DF::CheckBox::checkExecute()
{
	if (check)
	{
		check = false;
	}
	else
	{
		check = true;
	}

	fun_IF->function(check);
}