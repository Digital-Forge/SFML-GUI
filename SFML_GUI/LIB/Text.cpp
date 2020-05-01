#include "Text.h"

DF::Text::Style::Style() :
	active_text_color(sf::Color::Black),
	active_outline_color(sf::Color::Black),
	inactive_text_color(0x7F7F7FFF),
	inactive_outline_color(0x7F7F7FFF),
	font(nullptr),
	outline_size(0),
	font_size(1.0),
	level_correct(0.9),
	hook(Style::Hook::center)
{
}

DF::Text::Style::~Style()
{
}

DF::Text::Style DF::Text::defoult_style;

void DF::Text::Style::setFont(sf::Font* font)
{
	this->font = font;
}

void DF::Text::Style::setCorrectLevel(double level)
{
	level_correct = level;
}

double DF::Text::Style::getCorrectLevel()
{
	return level_correct;
}

void DF::Text::Style::setTextSize(double size)
{
	font_size = size;
}

double DF::Text::Style::getTextSize()
{
	return font_size;
}

void DF::Text::Style::setHook(Style::Hook hook)
{
	this->hook = hook;
}

DF::Text::Style::Hook DF::Text::Style::getHook()
{
	return hook;
}

void DF::Text::Style::setActiveColor(sf::Color color)
{
	active_text_color = color;
}

sf::Color DF::Text::Style::getActiveColor()
{
	return active_text_color;
}

void DF::Text::Style::setActiveOutlineColor(sf::Color color)
{
	active_outline_color = color;
}

sf::Color DF::Text::Style::getActiveOutlineColor()
{
	return active_outline_color;
}

void DF::Text::Style::setInActiveColor(sf::Color color)
{
	inactive_text_color = color;
}

sf::Color DF::Text::Style::getInActiveColor()
{
	return inactive_text_color;
}

void DF::Text::Style::setInActiveOutlineColor(sf::Color color)
{
	inactive_outline_color = color;
}

sf::Color DF::Text::Style::getInActiveOutlineColor()
{
	return inactive_outline_color;
}

void DF::Text::Style::setOutlineSize(double size)
{
	outline_size = size;
}

double DF::Text::Style::getOutlineSize()
{
	return outline_size;
}

void DF::Text::Style::setStyle(Text* object)
{
	object->txt.setFont(*font);
	object->videoReset();

	if (object->active)
	{
		object->txt.setFillColor(active_text_color);
		object->txt.setOutlineColor(active_outline_color);
	}
	else
	{
		object->txt.setFillColor(inactive_text_color);
		object->txt.setOutlineColor(inactive_outline_color);
	}
}

DF::Text::Text(Window* window, double x, double y, sf::String text, Text::Style* style):
	Element(window, x, y, 0, 0),
	graphic_config(style),
	last_set_text(true),
	txt()
{
	this->text[0] = "";
	this->text[1] = text;
	resetStyle();
}

DF::Text::~Text()
{
}

void DF::Text::show()
{
	if (visible)
	{
		window->_getWindow()->draw(txt);
	}
}

DF::Text* DF::Text::returnOrigin(Base* object)
{
	Text* to_origin;
	to_origin = dynamic_cast<Text*>(object);

	if (to_origin == nullptr)
	{
		return nullptr;
	}
	else
	{
		return to_origin;
	}
}

void DF::Text::videoReset()
{
	txt.setCharacterSize(ceil(graphic_config->getTextSize() * window->getVideoDiagonal() * 0.01));
	txt.setOutlineThickness(graphic_config->getOutlineSize() * window->getVideoDiagonal() * 0.01);

	if (last_set_text)
	{
		setGlobalText(text[1]);
	}
	else
	{
		sf::String buff = text[0];
		setGlobalText(text[1]);
		_setText(buff);
	}

	txt.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));
}

void DF::Text::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
	txt.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));
}

void DF::Text::move(double x, double y)
{
	this->x += x;
	this->y += y;
	txt.setPosition(window->getVideoWidth() * (this->x * 0.01), window->getVideoHeight() * (this->y * 0.01));
}

void DF::Text::setActive(bool a)
{
	active = a;
	resetStyle();
}

void DF::Text::_setText(sf::String text)
{
	this->text[0] = text;
	txt.setString(text);
	last_set_text = false;
}

void DF::Text::setGlobalText(sf::String text)
{
	_setText(text);
	this->text[1] = text;

	switch (graphic_config->getHook())
	{
	case Style::Hook::left:
		txt.setOrigin(0, txt.getLocalBounds().height * graphic_config->getCorrectLevel());
		break;
	case Style::Hook::right:
		txt.setOrigin(txt.getLocalBounds().width, txt.getLocalBounds().height * graphic_config->getCorrectLevel());
		break;
	case Style::Hook::center:
		txt.setOrigin(txt.getLocalBounds().width / 2, txt.getLocalBounds().height * graphic_config->getCorrectLevel());
		break;
	}
	last_set_text = true;
}

void DF::Text::resetStyle()
{
	graphic_config->setStyle(this);
}

void DF::Text::setStyle(Text::Style* style)
{
	graphic_config = style;
}
