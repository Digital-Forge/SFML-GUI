#pragma once
#include "LIB/Window.h"
#include "LIB/Button.h"
#include "LIB/Container.h"
#include "LIB/FontAlbum.h"
#include "LIB/Text.h"
#include "LIB/TxButton.h"

class Test
{
	DF::Window* window;

	DF::Button::Style button_style;
	DF::TxButton::Style tx_button_style;
	DF::Text::Style text_style;
	
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
};

