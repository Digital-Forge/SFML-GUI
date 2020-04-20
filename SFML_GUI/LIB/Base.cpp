#include "Base.h"

DF::Base::Base()
{
}

DF::Base::~Base()
{
}

void DF::Base::event()
{
}

void DF::Base::show()
{
}

DF::Base* DF::Base::returnOrigin(Base* object)
{
	Base* to_origin;
	to_origin = dynamic_cast<Base*>(object);

	if (to_origin == nullptr)
	{
		return nullptr;
	}
	else
	{
		return to_origin;
	}
}

void DF::Base::videoReset()
{
}
