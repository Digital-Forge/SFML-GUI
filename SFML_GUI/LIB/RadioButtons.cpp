#include "RadioButtons.h"

DF::RadioButtons::RadioButtons(Window* window, double x, double y, double radius, DF::FunctionInterface<>* fun, RadioButtons::Style* style)
{
	list.push_back(new Buttons(this, window, x, y, radius, style, fun));
}

DF::RadioButtons::~RadioButtons()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		delete list[i];
	}
	list.clear();
}

void DF::RadioButtons::event()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i]->event();
	}
}

void DF::RadioButtons::show()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i]->show();
	}
}

DF::RadioButtons* DF::RadioButtons::returnOrigin(Base* object)
{
	RadioButtons* to_origin;
	to_origin = dynamic_cast<RadioButtons*>(object);
	return to_origin;
}

void DF::RadioButtons::videoReset()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i]->videoReset();
	}
}

DF::RadioButtons::Buttons& DF::RadioButtons::operator[](const std::size_t n)
{
	return *(list[n]);
}

void DF::RadioButtons::add(double x, double y, DF::FunctionInterface<>* fun)
{
	list.push_back(new Buttons(this, list[0]->window, x, y, list[0]->w, list[0]->graphic_config, fun));
}

long DF::RadioButtons::getNumberCheckButton()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list[i]->getCheck())
		{
			return i;
		}
	}
	return -1;
}

void DF::RadioButtons::clearAllCheck()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i]->setCheck(false);
	}
}

void DF::RadioButtons::setActive(bool a)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i]->setActive(a);
	}
}

bool DF::RadioButtons::getActive()
{
	return list[0]->getActive();
}

void DF::RadioButtons::setVisible(bool a)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i]->setVisible(a);
	}
}

bool DF::RadioButtons::getVisible()
{
	return list[0]->getVisible();
}

void DF::RadioButtons::setSize(double radius)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i]->setSize(radius);
	}
}

void DF::RadioButtons::resetStyle()
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i]->resetStyle();
	}
}

void DF::RadioButtons::setStyle(RadioButtons::Style* style)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		list[i]->setStyle(style);
	}
}

DF::RadioButtons::Buttons::Buttons(RadioButtons* master, Window* window, double x, double y, double radius, RadioButtons::Style* style, DF::FunctionInterface<>* fun) :
	Element(window, x, y, radius, radius* (style->scale_size_ring)),
	master(master),
	graphic_config(style),
	fun(fun),
	press_buff(false),
	check(false)
{
	resetStyle();
}

DF::RadioButtons::Buttons::~Buttons()
{
	if (fun != nullptr)
	{
		if (fun->getDelete)
		{
			delete fun;
		}
	}
}

void DF::RadioButtons::Buttons::event()
{
	if (active && visible && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		if (!press_buff)
		{
			press_buff = true;
			mouse_poz = window->_getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*window->_getWindow()));

			if (sqrt(pow(fabs(circle[0].getPosition().x - mouse_poz.x),2) + pow(fabs(circle[0].getPosition().y - mouse_poz.y),2)) < (window->getVideoDiagonal() * w * 0.01))
			{
				if (!check)
				{
					master->clearAllCheck();
					check = true;

					if (fun != nullptr)
					{
						fun->function();
					}
				}
			}
		}
	}
	else
	{
		press_buff = false;
	}
}

void DF::RadioButtons::Buttons::show()
{
	if (visible)
	{
		window->_getWindow()->draw(circle[0]);

		if (check)
		{
			window->_getWindow()->draw(circle[1]);
		}
	}
}

DF::RadioButtons::Buttons* DF::RadioButtons::Buttons::returnOrigin(Base* object)
{
	Buttons* to_origin;
	to_origin = dynamic_cast<Buttons*>(object);
	return to_origin;
}

void DF::RadioButtons::Buttons::videoReset()
{
	h = w * graphic_config->getScaleRing();

	circle[0].setRadius(window->getVideoDiagonal() * w * 0.01);
	circle[1].setRadius(window->getVideoDiagonal() * h * 0.01);

	circle[0].setOrigin(circle[0].getLocalBounds().width * 0.5, circle[0].getLocalBounds().height * 0.5);
	circle[1].setOrigin(circle[1].getLocalBounds().width * 0.5, circle[1].getLocalBounds().height * 0.5);

	circle[0].setPosition(window->getVideoWidth() * x * 0.01, window->getVideoHeight() * y * 0.01);
	circle[1].setPosition(window->getVideoWidth() * x * 0.01, window->getVideoHeight() * y * 0.01);

	graphic_config->setStyle(this);
}

DF::RadioButtons::Style::Style() :
	active_out_circle_color(0x7B7B7BFF),
	active_out_circle_outline_color(sf::Color::Black),
	active_in_circle_color(0xBBBBBBFF),
	active_in_circle_outline_color(sf::Color::Black),
	inactive_out_circle_color(0x5F5F5FFF),
	inactive_out_circle_outline_color(0x4F4F4F80),
	inactive_in_circle_color(0x7B7B7BFF),
	inactive_in_circle_outline_color(0x4F4F4F80),
	out_outline_size(0.3),
	in_outline_size(0.2),
	scale_size_ring(0.5)
{
}

DF::RadioButtons::Style::~Style()
{
}

DF::RadioButtons::Style DF::RadioButtons::defoult_style;

void DF::RadioButtons::Style::setActiveOutCircleColor(sf::Color color)
{
	active_out_circle_color = color;
}

sf::Color DF::RadioButtons::Style::getActiveOutCircleColor()
{
	return active_out_circle_color;
}

void DF::RadioButtons::Style::setActiveOutCircleOutlineColor(sf::Color color)
{
	active_out_circle_outline_color = color;
}

sf::Color DF::RadioButtons::Style::getActiveOutCircleOutlineColor()
{
	return active_out_circle_outline_color;
}

void DF::RadioButtons::Style::setActiveInCircleColor(sf::Color color)
{
	active_in_circle_color = color;
}

sf::Color DF::RadioButtons::Style::getActiveInCircleColor()
{
	return active_in_circle_color;
}

void DF::RadioButtons::Style::setActiveInCircleOutlineColor(sf::Color color)
{
	active_in_circle_outline_color = color;
}

sf::Color DF::RadioButtons::Style::getActiveInCircleOutlineColor()
{
	return active_in_circle_outline_color;
}

void DF::RadioButtons::Style::setInActiveOutCircleColor(sf::Color color)
{
	inactive_out_circle_color = color;
}

sf::Color DF::RadioButtons::Style::getInActiveOutCircleColor()
{
	return inactive_out_circle_color;
}

void DF::RadioButtons::Style::setInActiveOutCircleOutlineColor(sf::Color color)
{
	inactive_out_circle_outline_color = color;
}

sf::Color DF::RadioButtons::Style::getInActiveOutCircleOutlineColor()
{
	return inactive_out_circle_outline_color;
}

void DF::RadioButtons::Style::setInActiveInCircleColor(sf::Color color)
{
	inactive_in_circle_color = color;
}

sf::Color DF::RadioButtons::Style::getInActiveInCircleColor()
{
	return inactive_in_circle_color;
}

void DF::RadioButtons::Style::setInActiveInCircleOutlineColor(sf::Color color)
{
	inactive_in_circle_outline_color = color;
}

sf::Color DF::RadioButtons::Style::getInActiveInCircleOutlineColor()
{
	return inactive_in_circle_outline_color;
}

void DF::RadioButtons::Style::setOutCircleOutlineSize(double size)
{
	out_outline_size = size;
}

double DF::RadioButtons::Style::getOutCircleOutlineSize()
{
	return out_outline_size;
}

void DF::RadioButtons::Style::setInCircleOutlineSize(double size)
{
	in_outline_size = size;
}

double DF::RadioButtons::Style::getInCircleOutlineSize()
{
	return in_outline_size;
}

void DF::RadioButtons::Style::setScaleRing(double size)
{
	scale_size_ring = size;
}

double DF::RadioButtons::Style::getScaleRing()
{
	return scale_size_ring;
}

void DF::RadioButtons::Style::setStyle(Buttons* object)
{
	object->circle[0].setOutlineThickness(object->window->getVideoDiagonal() * out_outline_size * 0.01);
	object->circle[1].setOutlineThickness(object->window->getVideoDiagonal() * in_outline_size * 0.01);

	if (object->active)
	{
		object->circle[0].setFillColor(active_out_circle_color);
		object->circle[1].setFillColor(active_in_circle_color);
		object->circle[0].setOutlineColor(active_out_circle_outline_color);
		object->circle[1].setOutlineColor(active_in_circle_outline_color);
	}
	else
	{
		object->circle[0].setFillColor(inactive_out_circle_color);
		object->circle[1].setFillColor(inactive_in_circle_color);
		object->circle[0].setOutlineColor(inactive_out_circle_outline_color);
		object->circle[1].setOutlineColor(inactive_in_circle_outline_color);
	}
}

void DF::RadioButtons::Buttons::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
	videoReset();
}

void DF::RadioButtons::Buttons::move(double x, double y)
{
	this->x += x;
	this->y += y;
	videoReset();
}

void DF::RadioButtons::Buttons::setActive(bool a)
{
	active = a;
	graphic_config->setStyle(this);
}

void DF::RadioButtons::Buttons::setSize(double radius)
{
	w = radius;
	videoReset();
}

void DF::RadioButtons::Buttons::resetStyle()
{
	videoReset();
}

void DF::RadioButtons::Buttons::setStyle(RadioButtons::Style* style)
{
	graphic_config = style;
}

void DF::RadioButtons::Buttons::setCheck(bool a)
{
	if (a)
	{
		master->clearAllCheck();
	}
	check = a;
}

bool DF::RadioButtons::Buttons::getCheck()
{
	return check;
}

void DF::RadioButtons::Buttons::setFunction(FunctionInterface<>* function)
{
	if (fun != nullptr)
	{
		if (fun->getDelete)
		{
			delete fun;
		}
	}
	fun = function;
}

void DF::RadioButtons::Buttons::goFunction()
{
	if (fun != nullptr)
	{
		fun->function();
	}
}
