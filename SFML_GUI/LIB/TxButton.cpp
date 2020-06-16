#include "TxButton.h"

DF::TxButton::Style::Style():
	active_rect_color(sf::Color(0x9F9F9FFF)),
	active_rect_outline_color(sf::Color::Black),
	active_text_color(sf::Color::Black),
	active_text_outline_color(sf::Color::Black),
	inactive_rect_color(sf::Color(0x4F4F4FFF)),
	inactive_rect_outline_color(sf::Color::Black),
	inactive_text_color(sf::Color::Black),
	inactive_text_outline_color(sf::Color::Black),
	font(nullptr),
	level_correct(1.7),
	text_outline_size(0.0),
	rect_outline_size(0.0),
	distance_from_edge(0.8)
{
}

DF::TxButton::Style::~Style()
{
}

DF::TxButton::Style DF::TxButton::defoult_style;

void DF::TxButton::Style::setActiveButtonColor(sf::Color color)
{
	active_rect_color = color;
}

sf::Color DF::TxButton::Style::getActiveButtonColor()
{
	return active_rect_color;
}

void DF::TxButton::Style::setActiveButtonOutlineColor(sf::Color color)
{
	active_rect_outline_color = color;
}

sf::Color DF::TxButton::Style::getActiveButtonOutlineColor()
{
	return active_rect_outline_color;
}

void DF::TxButton::Style::setInActiveButtonColor(sf::Color color)
{
	inactive_rect_color = color;
}

sf::Color DF::TxButton::Style::getInActiveButtonColor()
{
	return inactive_rect_color;
}

void DF::TxButton::Style::setInActiveButtonOutlineColor(sf::Color color)
{
	inactive_rect_outline_color = color;
}

sf::Color DF::TxButton::Style::getInActiveButtonOutlineColor()
{
	return inactive_rect_outline_color;
}

void DF::TxButton::Style::setButtonOutlineSize(double size)
{
	rect_outline_size = size;
}

double DF::TxButton::Style::getButtonOutlineSize()
{
	return rect_outline_size;
}

void DF::TxButton::Style::setFont(sf::Font* font)
{
	this->font = font;
}

void DF::TxButton::Style::setCorrectLevel(double level)
{
	level_correct = level;
}

double DF::TxButton::Style::getCorrectLevel()
{
	return level_correct;
}

void DF::TxButton::Style::setActiveTextColor(sf::Color color)
{
	active_text_color = color;
}

sf::Color DF::TxButton::Style::getActiveTextColor()
{
	return active_text_color;
}

void DF::TxButton::Style::setActiveTextOutlineColor(sf::Color color)
{
	active_text_outline_color = color;
}

sf::Color DF::TxButton::Style::getActiveTextOutlineColor()
{
	return active_text_outline_color;
}

void DF::TxButton::Style::setInActiveTextColor(sf::Color color)
{
	inactive_text_color = color;
}

sf::Color DF::TxButton::Style::getInActiveTextColor()
{
	return inactive_text_color;
}

void DF::TxButton::Style::setInActiveTextOutlineColor(sf::Color color)
{
	inactive_text_outline_color = color;
}

sf::Color DF::TxButton::Style::getInActiveTextOutlineColor()
{
	return inactive_text_outline_color;
}

void DF::TxButton::Style::setTextOutlineSize(double size)
{
	text_outline_size = size;
}

double DF::TxButton::Style::getTextOutlineSize()
{
	return text_outline_size;
}

void DF::TxButton::Style::_setDistanceFromEdge(double size)
{
	distance_from_edge = size;
}

double DF::TxButton::Style::_setDistanceFromEdge()
{
	return distance_from_edge;
}

void DF::TxButton::Style::setStyle(TxButton* object)
{
	object->rect.setOutlineThickness(rect_outline_size);
	object->txt.setOutlineThickness(text_outline_size);
	object->txt.setFont(*font);

	if (object->active)
	{
		object->rect.setFillColor(active_rect_color);
		object->rect.setOutlineColor(active_rect_outline_color);
		object->txt.setFillColor(active_text_color);
		object->txt.setOutlineColor(active_text_outline_color);
	}
	else
	{
		object->rect.setFillColor(inactive_rect_color);
		object->rect.setOutlineColor(inactive_rect_outline_color);
		object->txt.setFillColor(inactive_text_color);
		object->txt.setOutlineColor(inactive_text_outline_color);
	}
}

DF::TxButton::TxButton(Window* window, double x, double y, double w, double h, sf::String text, FunctionInterface<>* function, TxButton::Style* style):
	Button(window, x, y, w, h, function),
	graphic_config(style),
	txt()
{
	txt.setString(text);
	graphic_config->setStyle(this);
	videoReset();
}

DF::TxButton::~TxButton()
{
}

void DF::TxButton::show()
{
	if (visible)
	{
		window->_getWindow()->draw(rect);
		window->_getWindow()->draw(txt);
	}
}

DF::TxButton* DF::TxButton::returnOrigin(Base* object)
{
	TxButton* to_origin;
	to_origin = dynamic_cast<TxButton*>(object);

	if (to_origin == nullptr)
	{
		return nullptr;
	}
	else
	{
		return to_origin;
	}
}

void DF::TxButton::videoReset()
{
	rect.setSize(sf::Vector2f(window->getVideoWidth() * (w * 0.01), window->getVideoHeight() * (h * 0.01)));
	rect.setOrigin(rect.getSize().x * 0.5, rect.getSize().y * 0.5);
	rect.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));
	rect.setOutlineThickness(graphic_config->rect_outline_size * window->getVideoDiagonal() * 0.01);

	textReset();
}

void DF::TxButton::setPosition(double x, double y)
{
	Button::setPosition(x, y);
	txt.setPosition(window->getVideoWidth() * (this->x * 0.01), window->getVideoHeight() * (this->y * 0.01));
}

void DF::TxButton::move(double x, double y)
{
	Button::move(x, y);
	txt.setPosition(window->getVideoWidth() * (this->x * 0.01), window->getVideoHeight() * (this->y * 0.01));
}

void DF::TxButton::setActive(bool a)
{
	active = a;
	graphic_config->setStyle(this);
}

void DF::TxButton::setSize(double width, double height)
{
	Button::setSize(width, height);
	textReset();
}

void DF::TxButton::resetStyle()
{
	graphic_config->setStyle(this);
	videoReset();
}

void DF::TxButton::setStyle(TxButton::Style* style)
{
	this->graphic_config = style;
}

void DF::TxButton::setText(sf::String text)
{
	txt.setString(text);
	textReset();
}

void DF::TxButton::textReset()
{
	txt.setCharacterSize(rect.getSize().y);
	txt.setOrigin(txt.getLocalBounds().width * 0.5, txt.getLocalBounds().height * 0.5);
	txt.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));

	while ((txt.getLocalBounds().left < Button::rect.getLocalBounds().left) ||
		   (txt.getLocalBounds().left + txt.getLocalBounds().width > Button::rect.getLocalBounds().left + Button::rect.getLocalBounds().width) ||
		   (txt.getLocalBounds().top < Button::rect.getLocalBounds().top) ||
		   (txt.getLocalBounds().top + txt.getLocalBounds().height > Button::rect.getLocalBounds().top + Button::rect.getLocalBounds().height))
	{
		txt.setCharacterSize(txt.getCharacterSize() - 1);
		txt.setOrigin(txt.getLocalBounds().width * 0.5, txt.getLocalBounds().height * 0.5);
	}

	txt.setCharacterSize(txt.getCharacterSize() * graphic_config->_setDistanceFromEdge());
	txt.setOrigin(txt.getLocalBounds().width * 0.5, txt.getLocalBounds().height * 0.5 * graphic_config->getCorrectLevel());
	txt.setPosition(window->getVideoWidth() * (x * 0.01), window->getVideoHeight() * (y * 0.01));
}
