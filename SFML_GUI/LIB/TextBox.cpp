#include "TextBox.h"

DF::TextBox::Style::Style() :
	active_rect_color(sf::Color(0x9F9F9FFF)),
	active_rect_outline_color(sf::Color::Black),
	active_text_color(sf::Color::Black),
	active_text_outline_color(sf::Color::Black),
	active_phantom_text_color(sf::Color(0xAFAFAFFF)),
	active_phantom_text_outline_color(sf::Color::Black),
	inactive_rect_color(sf::Color(0x4F4F4FFF)),
	inactive_rect_outline_color(sf::Color::Black),
	inactive_text_color(sf::Color::Black),
	inactive_text_outline_color(sf::Color::Black),
	inactive_phantom_text_color(sf::Color(0x5F5F5FFF)),
	inactive_phantom_text_outline_color(sf::Color(0x5F5F5FFF)),
	font(nullptr),
	level_correct(1.5),
	distance_from_edge(0.8),
	text_outline_size(0.2),
	phantom_text_outline_size(0.2),
	rect_outline_size(0.5),
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

void DF::TextBox::Style::_setDistanceFromEdge(double size)
{
	distance_from_edge = size;
}

double DF::TextBox::Style::_setDistanceFromEdge()
{
	return distance_from_edge;
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

void DF::TextBox::Style::setHook(Style::Hook hook)
{
	this->hook = hook;
}

DF::TextBox::Style::Hook DF::TextBox::Style::getHook()
{
	return hook;
}

void DF::TextBox::Style::setStyle(TextBox* object)
{
	object->txt[0].setFont(*font);
	object->txt[1].setFont(*font);
	object->txt[0].setOutlineThickness(object->window->getVideoDiagonal() * text_outline_size * 0.01);
	object->txt[1].setOutlineThickness(object->window->getVideoDiagonal() * phantom_text_outline_size * 0.01);
	object->rect.setOutlineThickness(object->window->getVideoDiagonal() * rect_outline_size * 0.01);

	if (object->active)
	{
		object->rect.setFillColor(active_rect_color);
		object->rect.setOutlineColor(active_rect_outline_color);
		object->txt[0].setFillColor(active_text_color);
		object->txt[0].setOutlineColor(active_text_outline_color);
		object->txt[1].setFillColor(active_phantom_text_color);
		object->txt[1].setOutlineColor(active_phantom_text_outline_color);
	}
	else
	{
		object->rect.setFillColor(inactive_rect_color);
		object->rect.setOutlineColor(inactive_rect_outline_color);
		object->txt[0].setFillColor(inactive_text_color);
		object->txt[0].setOutlineColor(inactive_text_outline_color);
		object->txt[1].setFillColor(inactive_phantom_text_color);
		object->txt[1].setOutlineColor(inactive_phantom_text_outline_color);
	}
}

DF::TextBox::TextBox(Window* window, sf::Event* events, double x, double y, double w, double h, sf::String phantom_text, TextBox::Style* style) :
	Element(window, x, y, w, h),
	events(events),
	graphic_config(style),
	write_active(false),
	limit_letters(0),
	time(std::chrono::system_clock::now()),
	press_buff(false),
	fun(nullptr)
{
	text[0] = "";
	text[1] = phantom_text;
	txt[0].setString(text[0]);
	txt[1].setString(text[1]);

	graphic_config->setStyle(this);
	videoReset();
}

DF::TextBox::~TextBox()
{
	if (fun != nullptr)
	{
		if (fun->getDelete)
		{
			delete fun;
		}
	}
}

void DF::TextBox::event()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mouse_poz = window->_getWindow()->mapPixelToCoords(sf::Mouse::getPosition(*(window->_getWindow())));

		if ((mouse_poz.x > (rect.getPosition().x - (rect.getSize().x * 0.5)) && mouse_poz.x < (rect.getPosition().x + (rect.getSize().x * 0.5)))
			&& (mouse_poz.y > (rect.getPosition().y - (rect.getSize().y * 0.5)) && mouse_poz.y < (rect.getPosition().y + (rect.getSize().y * 0.5))))
		{
			write_active = true;
		}
		else
		{
			write_active = false;
		}
	}

	if (write_active)
	{
		if (text[0].getSize() <= limit_letters || limit_letters == 0)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
			{
				write_active = false;
				press_buff = false;

				if (fun != nullptr)
				{
					fun->function();
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
			{
				if (!text[0].isEmpty() && (std::chrono::system_clock::now() > time + std::chrono::milliseconds(250) || !press_buff))
				{
					text[0].erase(text[0].getSize() - 1, 1);
					txt[0].setString(text[0]);
					textGraphicScale(txt[0], true);
					time = std::chrono::system_clock::now();
					press_buff = true;
				}
			}
			else if (events->type == sf::Event::TextEntered)
			{
				//if (events->text.unicode < 128)
				if(std::chrono::system_clock::now() > time + std::chrono::milliseconds(350) || !press_buff)
				{
					text[0] += (sf::String)(events->text.unicode);
					txt[0].setString(text[0]);
					textGraphicScale(txt[0]);
					time = std::chrono::system_clock::now();
					press_buff = true;
				}
			}
			else
			{
				press_buff = false;
			}
		}
	}
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
	TextBox* to_origin;
	to_origin = dynamic_cast<TextBox*>(object);

	if (to_origin == nullptr)
	{
		return nullptr;
	}
	else
	{
		return to_origin;
	}
}

void DF::TextBox::videoReset()
{
	rect.setSize(sf::Vector2f(window->getVideoWidth() * w * 0.01, window->getVideoHeight() * h * 0.01));
	rect.setOrigin(rect.getSize().x * 0.5, rect.getSize().y * 0.5);
	rect.setPosition(window->getVideoWidth() * x * 0.01, window->getVideoHeight() * y * 0.01);
	rect.setOutlineThickness(graphic_config->rect_outline_size * window->getVideoDiagonal() * 0.01);

	textGraphicScale(txt[0], true);
	textGraphicScale(txt[1], true);
}

void DF::TextBox::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
	videoReset();
}

void DF::TextBox::move(double x, double y)
{
	this->x += x;
	this->y += y;
	videoReset();
}

void DF::TextBox::setActive(bool a)
{
	active = a;
	graphic_config->setStyle(this);
}

void DF::TextBox::setSize(double width, double height)
{
	this->w = width;
	this->h = height;
	videoReset();
}

void DF::TextBox::resetStyle()
{
	graphic_config->setStyle(this);
	videoReset();
}

void DF::TextBox::setStyle(TextBox::Style* style)
{
	graphic_config = style;
}

void DF::TextBox::setText(sf::String text)
{
	this->text[0] = text;
	txt[0].setString(text[0]);
	textGraphicScale(txt[0], true);
}

sf::String DF::TextBox::getText()
{
	return text[0];
}

void DF::TextBox::setPhantomText(sf::String text)
{
	this->text[1] = text;
	txt[1].setString(text[1]);
	textGraphicScale(txt[1], true);
}

void DF::TextBox::setLettersLimit(unsigned int limit)
{
	limit_letters = limit;
}

void DF::TextBox::setFunction(DF::FunctionInterface<>* fun)
{
	if (this->fun != nullptr)
	{
		if (this->fun->getDelete)
		{
			delete this->fun;
		}
	}
	this->fun = fun;
}

void DF::TextBox::textGraphicScale(sf::Text& graf_txt, bool exact)
{
	graf_txt.setOrigin(graf_txt.getLocalBounds().width * 0.5, graf_txt.getLocalBounds().height * 0.5);
	graf_txt.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));

	if (((graf_txt.getLocalBounds().left < rect.getLocalBounds().left) 
	||   (graf_txt.getLocalBounds().left + graf_txt.getLocalBounds().width > rect.getLocalBounds().left + rect.getLocalBounds().width))
	||   exact)
	{
		graf_txt.setCharacterSize(rect.getSize().y);
		graf_txt.setOrigin(graf_txt.getLocalBounds().width * 0.5, graf_txt.getLocalBounds().height * 0.5);
		graf_txt.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));

		while ((graf_txt.getLocalBounds().left < rect.getLocalBounds().left) ||
			(graf_txt.getLocalBounds().left + graf_txt.getLocalBounds().width > rect.getLocalBounds().left + rect.getLocalBounds().width) ||
			(graf_txt.getLocalBounds().top < rect.getLocalBounds().top) ||
			(graf_txt.getLocalBounds().top + graf_txt.getLocalBounds().height > rect.getLocalBounds().top + rect.getLocalBounds().height))
		{
			graf_txt.setCharacterSize(graf_txt.getCharacterSize() - 1);
			graf_txt.setOrigin(graf_txt.getLocalBounds().width * 0.5, graf_txt.getLocalBounds().height * 0.5);
		}

		graf_txt.setCharacterSize(graf_txt.getCharacterSize() * graphic_config->_setDistanceFromEdge());
		textGraphicScale(graf_txt, false);
	}
	else
	{
		switch (graphic_config->hook)
		{
		case Style::Hook::left:

			graf_txt.setOrigin(0, graf_txt.getLocalBounds().height * 0.5 * graphic_config->getTextCorrectLevel());
			graf_txt.setPosition(window->getVideoWidth() * (x * 0.01) - (rect.getSize().x * 0.5), window->getVideoHeight() * (y * 0.01));

			break;
		case Style::Hook::center:

			graf_txt.setOrigin(graf_txt.getLocalBounds().width * 0.5, graf_txt.getLocalBounds().height * 0.5 * graphic_config->getTextCorrectLevel());
			graf_txt.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));

			break;
		case Style::Hook::right:

			graf_txt.setOrigin(graf_txt.getLocalBounds().width, graf_txt.getLocalBounds().height * 0.5 * graphic_config->getTextCorrectLevel());
			graf_txt.setPosition(window->getVideoWidth() * (x * 0.01) + (rect.getSize().x * 0.5), window->getVideoHeight() * (y * 0.01));

			break;
		}
	}
}
