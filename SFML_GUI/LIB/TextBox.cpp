#include "TextBox.h"

DF::TextBox::Style::Style() :
	active_rect_color(sf::Color(0x9F9F9FFF)),
	active_rect_outline_color(sf::Color::Black),
	active_text_color(sf::Color::Black),
	active_text_outline_color(sf::Color::Black),
	active_phantom_text_color(sf::Color(0xAFAFAFFF)),
	active_phantom_text_outline_color(sf::Color(0xAFAFAFFF)),
	inactive_rect_color(sf::Color(0x4F4F4FFF)),
	inactive_rect_outline_color(sf::Color::Black),
	inactive_text_color(sf::Color::Black),
	inactive_text_outline_color(sf::Color::Black),
	inactive_phantom_text_color(sf::Color(0x5F5F5FFF)),
	inactive_phantom_text_outline_color(sf::Color(0x5F5F5FFF)),
	font(nullptr),
	level_correct(1.7),
	text_outline_size(0.0),
	phantom_text_outline_size(0.0),
	rect_outline_size(0.0),
	hook(Style::Hook::left)
{
}

DF::TextBox::Style::~Style()
{
}

DF::TextBox::Style DF::TextBox::defoult_style;

void DF::TextBox::Style::setActiveRectColor(sf::Color color)
{
	active_rect_color = color;
}

sf::Color DF::TextBox::Style::getActiveRectColor()
{
	return active_rect_color;
}

void DF::TextBox::Style::setActiveRectOutlineColor(sf::Color color)
{
	active_rect_outline_color = color;
}

sf::Color DF::TextBox::Style::getActiveRectOutlineColor()
{
	return active_rect_outline_color;
}

void DF::TextBox::Style::setInActiveRectColor(sf::Color color)
{
	inactive_rect_color = color;
}

sf::Color DF::TextBox::Style::getInActiveRectColor()
{
	return inactive_rect_color;
}

void DF::TextBox::Style::setInActiveRectOutlineColor(sf::Color color)
{
	inactive_rect_outline_color = color;
}

sf::Color DF::TextBox::Style::getInActiveRectOutlineColor()
{
	return inactive_rect_outline_color;
}

void DF::TextBox::Style::setRectOutlineSize(double size)
{
	rect_outline_size = size;
}

double DF::TextBox::Style::getRectOutlineSize()
{
	return rect_outline_size;
}

void DF::TextBox::Style::setFont(sf::Font* font)
{
	this->font = font;
}

void DF::TextBox::Style::setTextCorrectLevel(double level)
{
	level_correct = level;
}

double DF::TextBox::Style::getTextCorrectLevel()
{
	return level_correct;
}

void DF::TextBox::Style::setActiveTextColor(sf::Color color)
{
	active_text_color = color;
}

sf::Color DF::TextBox::Style::getActiveTextColor()
{
	return active_text_color;
}

void DF::TextBox::Style::setActiveTextOutlineColor(sf::Color color)
{
	active_text_outline_color = color;
}

sf::Color DF::TextBox::Style::getActiveTextOutlineColor()
{
	return active_text_outline_color;
}

void DF::TextBox::Style::setInActiveTextColor(sf::Color color)
{
	inactive_text_color = color;
}

sf::Color DF::TextBox::Style::getInActiveTextColor()
{
	return inactive_text_color;
}

void DF::TextBox::Style::setInActiveTextOutlineColor(sf::Color color)
{
	inactive_text_outline_color = color;
}

sf::Color DF::TextBox::Style::getInActiveTextOutlineColor()
{
	return inactive_text_outline_color;
}

void DF::TextBox::Style::setTextOutlineSize(double size)
{
	text_outline_size = size;
}

double DF::TextBox::Style::getTextOutlineSize()
{
	return text_outline_size;
}

void DF::TextBox::Style::setActivePhantomTextColor(sf::Color color)
{
	active_phantom_text_color = color;
}

sf::Color DF::TextBox::Style::getActivePhantomTextColor()
{
	return active_phantom_text_color;
}

void DF::TextBox::Style::setActivePhantomTextOutlineColor(sf::Color color)
{
	active_phantom_text_outline_color = color;
}

sf::Color DF::TextBox::Style::getActivePhantomTextOutlineColor()
{
	return active_phantom_text_outline_color;
}

void DF::TextBox::Style::setInActivePhantomTextColor(sf::Color color)
{
	inactive_phantom_text_color = color;
}

sf::Color DF::TextBox::Style::getInActivePhantomTextColor()
{
	return inactive_phantom_text_color;
}

void DF::TextBox::Style::setInActivePhantomTextOutlineColor(sf::Color color)
{
	inactive_phantom_text_outline_color = color;
}

sf::Color DF::TextBox::Style::getInActivePhantomTextOutlineColor()
{
	return inactive_phantom_text_outline_color;
}

void DF::TextBox::Style::setPhantomTextOutlineSize(double size)
{
	phantom_text_outline_size = size;
}

double DF::TextBox::Style::getPhantomTextOutlineSize()
{
	return phantom_text_outline_size;
}

void DF::TextBox::Style::setStyle(TextBox* object)
{
}

DF::TextBox::TextBox(Window* window, double x, double y, double w, double h, sf::String phantom_text, TextBox::Style* style) :
	Element(window,x,y,w,h),
	write_active(false),
	limit_letters(0)
{
}

DF::TextBox::~TextBox()
{
}

void DF::TextBox::event()
{
}

void DF::TextBox::show()
{
	if (visible)
	{
		window->_getWindow()->draw(rect);
		if (text[0].isEmpty())
		{
			window->_getWindow()->draw(txt[1]);
		}
		else
		{
			window->_getWindow()->draw(txt[0]);
		}
	}
}

DF::TextBox* DF::TextBox::returnOrigin(Base* object)
{
	return nullptr;
}

void DF::TextBox::videoReset()
{
}

void DF::TextBox::setPosition(double x, double y)
{
}

void DF::TextBox::move(double x, double y)
{
}

void DF::TextBox::setActive(bool a)
{
}

void DF::TextBox::setSize(double width, double height)
{
}

void DF::TextBox::resetStyle()
{
}

void DF::TextBox::setStyle(TextBox::Style* style)
{
	graphic_config = style;
}

void DF::TextBox::setText(sf::String text)
{
}

sf::String DF::TextBox::getText()
{
	return text[0];
}

void DF::TextBox::setPhantomText(sf::String text)
{
}

void DF::TextBox::setLettersLimit(unsigned int limit)
{
	limit_letters = limit;
}
