#include "ProgressBar.h"

DF::ProgressBar::Style::Style() :
	active_outbox_color(0x5F5F5FFF),
	active_outbox_outline_color(sf::Color::Black),
	active_inbox_color(0x2F2F2FFF),
	active_inbox_outline_color(0x3F3F3FFF),
	active_progress_bar_color(sf::Color::Blue),
	active_progress_bar_outline_color(0x0000FF66),
	inactive_outbox_color(0x2F2F2F55),
	inactive_outbox_outline_color(sf::Color::Black),
	inactive_inbox_color(0x2F2F2F55),
	inactive_inbox_outline_color(0x3F3F3F55),
	inactive_progress_bar_color(0x0000FF66),
	inactive_progress_bar_outline_color(0x0000FF33),
	outbox_outline_size(0.6),
	inbox_outline_size(1.0),
	progress_bar_outline_size(0.3),
	inbox_padding(0.9, 0.5)
{
}

DF::ProgressBar::Style::~Style()
{
}

DF::ProgressBar::Style DF::ProgressBar::defoult_style;

void DF::ProgressBar::Style::setActiveOutBoxColor(sf::Color color)
{
	active_outbox_color = color;
}

sf::Color DF::ProgressBar::Style::getActiveOutBoxColor()
{
	return active_outbox_color;
}

void DF::ProgressBar::Style::setActiveOutBoxOutlineColor(sf::Color color)
{
	active_outbox_outline_color = color;
}

sf::Color DF::ProgressBar::Style::getActiveOutBoxOutlineColor()
{
	return active_outbox_outline_color;
}

void DF::ProgressBar::Style::setActiveInBoxColor(sf::Color color)
{
	active_inbox_color = color;
}

sf::Color DF::ProgressBar::Style::getActiveInBoxColor()
{
	return active_inbox_color;
}

void DF::ProgressBar::Style::setActiveInBoxOutlineColor(sf::Color color)
{
	active_inbox_outline_color = color;
}

sf::Color DF::ProgressBar::Style::getActiveInBoxOutlineColor()
{
	return active_inbox_outline_color;
}

void DF::ProgressBar::Style::setActiveProgressBarColor(sf::Color color)
{
	active_progress_bar_color = color;
}

sf::Color DF::ProgressBar::Style::getActiveProgressBarColor()
{
	return active_progress_bar_color;
}

void DF::ProgressBar::Style::setActiveProgressBarOutlineColor(sf::Color color)
{
	active_progress_bar_outline_color = color;
}

sf::Color DF::ProgressBar::Style::getActiveProgressBarOutlineColor()
{
	return active_progress_bar_outline_color;
}

void DF::ProgressBar::Style::setInActiveOutBoxColor(sf::Color color)
{
	inactive_outbox_color = color;
}

sf::Color DF::ProgressBar::Style::getInActiveOutBoxColor()
{
	return inactive_outbox_color;
}

void DF::ProgressBar::Style::setInActiveOutBoxOutlineColor(sf::Color color)
{
	inactive_outbox_outline_color = color;
}

sf::Color DF::ProgressBar::Style::getInActiveOutBoxOutlineColor()
{
	return inactive_outbox_outline_color;
}

void DF::ProgressBar::Style::setInActiveInBoxColor(sf::Color color)
{
	inactive_inbox_color = color;
}

sf::Color DF::ProgressBar::Style::getInActiveInBoxColor()
{
	return inactive_inbox_color;
}

void DF::ProgressBar::Style::setInActiveInBoxOutlineColor(sf::Color color)
{
	inactive_inbox_outline_color = color;
}

sf::Color DF::ProgressBar::Style::getInActiveInBoxOutlineColor()
{
	return inactive_inbox_outline_color;
}

void DF::ProgressBar::Style::setInActiveProgressBarColor(sf::Color color)
{
	inactive_progress_bar_color = color;
}

sf::Color DF::ProgressBar::Style::getInActiveProgressBarColor()
{
	return inactive_progress_bar_color;
}

void DF::ProgressBar::Style::setInActiveProgressBarOutlineColor(sf::Color color)
{
	inactive_progress_bar_outline_color = color;
}

sf::Color DF::ProgressBar::Style::getInActiveProgressBarOutlineColor()
{
	return inactive_progress_bar_outline_color;
}

void DF::ProgressBar::Style::setOutBoxOutlineSize(double size)
{
	outbox_outline_size = size;
}

double DF::ProgressBar::Style::getOutBoxOutlineSize()
{
	return outbox_outline_size;
}

void DF::ProgressBar::Style::setInBoxOutlinesSize(double size)
{
	inbox_outline_size = size;
}

double DF::ProgressBar::Style::getInBoxOutlinesSize()
{
	return inbox_outline_size;
}

void DF::ProgressBar::Style::setPorgressBarOutlinesSize(double size)
{
	progress_bar_outline_size = size;
}

double DF::ProgressBar::Style::getProgressBarOutlinesSize()
{
	return progress_bar_outline_size;
}

void DF::ProgressBar::Style::setInBoxPadding(sf::Vector2f scale)
{
	inbox_padding = scale;
}

void DF::ProgressBar::Style::setInBoxPadding(double scale_x, double scale_y)
{
	inbox_padding = sf::Vector2f(scale_x, scale_y);
}

sf::Vector2f DF::ProgressBar::Style::getInBoxPadding()
{
	return inbox_padding;
}

void DF::ProgressBar::Style::setStyle(ProgressBar* object)
{
	double inbox_diagonal = sqrt((object->box[0].getSize().x * object->box[0].getSize().x) + (object->box[0].getSize().y * object->box[0].getSize().y));

	object->box[0].setOutlineThickness(outbox_outline_size * object->window->getVideoDiagonal() * 0.01);
	object->box[1].setOutlineThickness(inbox_outline_size * inbox_diagonal * 0.01);
	object->progress_bar.setOutlineThickness(progress_bar_outline_size * inbox_diagonal * 0.01);

	if (object->active)
	{
		object->box[0].setFillColor(active_outbox_color);
		object->box[0].setOutlineColor(active_outbox_outline_color);
		object->box[1].setFillColor(active_inbox_color);
		object->box[1].setOutlineColor(active_inbox_outline_color);
		object->progress_bar.setFillColor(active_progress_bar_color);
		object->progress_bar.setOutlineColor(active_progress_bar_outline_color);
	}
	else
	{
		object->box[0].setFillColor(inactive_outbox_color);
		object->box[0].setOutlineColor(inactive_outbox_outline_color);
		object->box[1].setFillColor(inactive_inbox_color);
		object->box[1].setOutlineColor(inactive_inbox_outline_color);
		object->progress_bar.setFillColor(inactive_progress_bar_color);
		object->progress_bar.setOutlineColor(inactive_progress_bar_outline_color);
	}
}

DF::ProgressBar::ProgressBar(Window* window, double x, double y, double w, double h, ProgressBar::Style* style) :
	Element(window,x,y,w,h),
	graphic_config(style),
	progress(0.0)
{
	videoReset();
	resetStyle();
}

DF::ProgressBar::~ProgressBar()
{
}

void DF::ProgressBar::show()
{
	window->_getWindow()->draw(box[0]);
	window->_getWindow()->draw(box[1]);

	if(progress != 0)	window->_getWindow()->draw(progress_bar);
}

DF::ProgressBar* DF::ProgressBar::returnOrigin(Base* object)
{
	ProgressBar* to_origin;
	to_origin = dynamic_cast<ProgressBar*>(object);

	if (to_origin == nullptr)
	{
		return nullptr;
	}
	else
	{
		return to_origin;
	}
}

void DF::ProgressBar::videoReset()
{
	box[0].setSize(sf::Vector2f(window->getVideoWidth() * w * 0.01, window->getVideoHeight() * h * 0.01));
	box[1].setSize(sf::Vector2f(box[0].getSize().x * graphic_config->inbox_padding.x, box[0].getSize().y * graphic_config->inbox_padding.y));
	progress_bar.setSize(sf::Vector2f(box[1].getSize().x * progress, box[1].getSize().y));

	box[0].setOrigin(box[0].getSize().x * 0.5, box[0].getSize().y * 0.5);
	box[1].setOrigin(box[1].getSize().x * 0.5, box[1].getSize().y * 0.5);
	progress_bar.setOrigin(0, box[1].getOrigin().y);

	box[0].setPosition(x * window->getVideoWidth() * 0.01, y * window->getVideoHeight() * 0.01);
	box[1].setPosition(x * window->getVideoWidth() * 0.01, y * window->getVideoHeight() * 0.01);
	progress_bar.setPosition((x * window->getVideoWidth() * 0.01) - (box[1].getSize().x * 0.5), y * window->getVideoHeight() * 0.01);
}

void DF::ProgressBar::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
	box[0].setPosition(x * window->getVideoWidth() * 0.01, y * window->getVideoHeight() * 0.01);
	box[1].setPosition(x * window->getVideoWidth() * 0.01, y * window->getVideoHeight() * 0.01);
	progress_bar.setPosition(x * window->getVideoWidth() * 0.01 - (box[1].getSize().x * 0.5), y * window->getVideoHeight() * 0.01);
}

void DF::ProgressBar::move(double x, double y)
{
	this->x += x;
	this->y += y;
	box[0].setPosition(x * window->getVideoWidth() * 0.01, y * window->getVideoHeight() * 0.01);
	box[1].setPosition(x * window->getVideoWidth() * 0.01, y * window->getVideoHeight() * 0.01);
	progress_bar.setPosition(x * window->getVideoWidth() * 0.01 - (box[1].getPosition().x * 0.5), y * window->getVideoHeight() * 0.01);
}

void DF::ProgressBar::setActive(bool a)
{
	active = a;
	graphic_config->setStyle(this);
}

void DF::ProgressBar::resetStyle()
{
	graphic_config->setStyle(this);
}

void DF::ProgressBar::setSize(double w, double h)
{
	this->w = w;
	this->h = h;

	box[0].setSize(sf::Vector2f(window->getVideoWidth() * w * 0.01, window->getVideoHeight() * h * 0.01));
	box[1].setSize(sf::Vector2f(box[0].getSize().x * 0.9, box[0].getSize().y * 0.9));;
	progress_bar.setSize(sf::Vector2f(box[1].getSize().x * progress, box[1].getSize().y));

	box[0].setOrigin(box[0].getSize().x * 0.5, box[0].getSize().y * 0.5);
	box[1].setOrigin(box[1].getSize().x * 0.5, box[1].getSize().y * 0.5);
	progress_bar.setOrigin(0, box[1].getOrigin().y);
}

void DF::ProgressBar::setProgress(double progress)
{
	if (progress >= 100)
	{
		this->progress = 1;
	}
	else if (progress <= 0)
	{
		this->progress = 0;
	}
	else
	{
		this->progress = progress * 0.01;
	}

	progress_bar.setSize(sf::Vector2f(box[1].getSize().x * this->progress, box[1].getSize().y));
	progress_bar.setOrigin(0, box[1].getOrigin().y);
}

double DF::ProgressBar::getProgress()
{
	return progress * 100;
}
