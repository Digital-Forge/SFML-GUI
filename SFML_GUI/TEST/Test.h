#pragma once
#include "LIB/Window.h"
#include "LIB/Button.h"
#include "LIB/Container.h"
#include "LIB/FontAlbum.h"
#include "LIB/Text.h"
#include "LIB/TxButton.h"
#include "LIB/CheckBox.h"
#include "LIB/ProgressBar.h"
#include "LIB/TextBox.h"
#include "LIB/RadioButtons.h"
#include "LIB/Line.h";

class Test
{
	DF::Window* window;
	sf::Event event;

	DF::Button::Style button_style;
	DF::TxButton::Style tx_button_style;
	DF::Text::Style text_style;
	DF::TextBox::Style texbox_style;
	DF::TextBox::Style texbox_style2;

	
	DF::Container box;
	DF::FontAlbum fonts;

	int num;

public:
	Test();
	~Test();
	void loop();

	void buttonNum();
	void buttonTextMove();

	void button1SetActive();
	void Button2MoveIt();

	void progressBarPlus();
	void progressBarMinus();
};