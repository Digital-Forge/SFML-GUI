#include "Element.h"

DF::Element::Element(Window* window, double x, double y, double w, double h):
	Base(),
	window(window),
	x(x),
	y(y),
	w(w),
	h(h),
	active(true),
	visible(true)
{
}

DF::Element::~Element()
{
}

DF::Element* DF::Element::returnOrigin(Base* object)
{
	Element* to_origin;
	to_origin = dynamic_cast<Element*>(object);

	if (to_origin == nullptr)
	{
		return nullptr;
	}
	else
	{
		return to_origin;
	}
}

void DF::Element::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
}

void DF::Element::move(double x, double y)
{
	this->x += x;
	this->y += y;
}

void DF::Element::setActive(bool a)
{
	active = a;
}

bool DF::Element::getActive()
{
	return active;
}

void DF::Element::setVisible(bool a)
{
	visible = a;
}

bool DF::Element::getVisible()
{
	return visible;
}

