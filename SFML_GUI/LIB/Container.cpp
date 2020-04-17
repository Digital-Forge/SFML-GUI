#include "Container.h"

DF::Container::Container(bool active) :
	active(active)
{
}

DF::Container::~Container()
{
}

void DF::Container::event()
{
	if (active)
	{
		for (size_t i = 0; i < combo.size(); i++)
		{
			combo[i]->event();
		}
	}
}

void DF::Container::show()
{
	if (active)
	{
		for (size_t i = 0; i < combo.size(); i++)
		{
			combo[i]->show();
		}
	}
}

void DF::Container::videoReset()
{
	for (size_t i = 0; i < combo.size(); i++)
	{
		combo[i]->videoReset();
	}
}

DF::Container* DF::Container::returnOrigin()
{
	return this;
}

void DF::Container::add(Base* element)
{
	combo.push_back(element);
}

void DF::Container::deleteALL()
{
	for (size_t i = 0; i < combo.size(); i++)
	{
		delete combo[i];
	}
	combo.clear();
}

void DF::Container::setActiv(bool active)
{
	this->active = active;
}

bool DF::Container::getActiv()
{
	return active;
}
