#include "Test.h"

Test::Test()
{
	window = new DF::Window(1280, 720, "test");
	
	num = 0;

	fonts.add("TEST/Verdana.ttf");

	button_style.setOutlineSize(0.15);
	button_style.setActiveOutlineColor(sf::Color::Red);
	button_style.setActiveColor(sf::Color::Yellow);

	tx_button_style.setFont(fonts.getFont(0));
	tx_button_style.setActiveButtonColor(sf::Color::Black);
	tx_button_style.setActiveTextColor(sf::Color::Green);

	text_style.setFont(fonts.getFont(0));
	text_style.setHook(DF::Text::Style::Hook::right);
	text_style.setTextSize(3);
	
	DF::TextBox::defoult_style.setFont(fonts.getFont(0));
	DF::TextBox::defoult_style.setHook(DF::TextBox::Style::Hook::left);
	texbox_style.setFont(fonts.getFont(0));
	texbox_style.setHook(DF::TextBox::Style::Hook::center);
	texbox_style2.setFont(fonts.getFont(0));
	texbox_style2.setHook(DF::TextBox::Style::Hook::right);


	box.add(new DF::Button(window, 7, 4, 10, 5, new DF::FunctionInterface<>(&Test::buttonNum, this, true), &button_style));
	box.add(new DF::Button(window, 7, 10, 10, 5, new DF::FunctionInterface<>(&Test::buttonTextMove, this, true)));

	box.add(new DF::TxButton(window, 7, 16, 10, 5, "button1", new DF::FunctionInterface<>(&Test::button1SetActive, this, true), &tx_button_style));
	box.add(new DF::TxButton(window, 7, 22, 10, 5, "test button 2", new DF::FunctionInterface<>(&Test::Button2MoveIt, this, true), &tx_button_style));

	box.add(new DF::Text(window, 99, 4, std::to_string(num), &text_style));
	box.add(new DF::Text(window, 99, 10, "Welcome", &text_style));

	box.add(new DF::CheckBox(window, 50, 15, 5));

	box.add(new DF::ProgressBar(window, 50, 93, 90, 10));
	box.add(new DF::TxButton(window, 5, 75, 5, 5, " - ", new DF::FunctionInterface<>(&Test::progressBarMinus, this, true), &tx_button_style));
	box.add(new DF::TxButton(window, 12, 75, 5, 5, " + ", new DF::FunctionInterface<>(&Test::progressBarPlus, this, true), &tx_button_style));

	box.add(new DF::TextBox(window, &event, 15, 50, 25, 10, "Test"));
	box.add(new DF::TextBox(window, &event, 50, 50, 25, 10, "Test", &texbox_style));
	box.add(new DF::TextBox(window, &event, 85, 50, 25, 10, "Test", &texbox_style2));

	box.add(new DF::RadioButtons(window, 15, 40, 1));

	DF::RadioButtons::returnOrigin(box.combo[13])->add(50, 40);
	(*DF::RadioButtons::returnOrigin(box.combo[13]))[0].setCheck(true);
	//DF::RadioButtons::returnOrigin(box.combo[13])->clearAllCheck();

	box.add(new DF::Line(window, 33, 75, 33, 25));
}

Test::~Test()
{
	box.deleteALL();
	delete window;
}

void Test::loop()
{
	window->open();

	while (window->isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		
		while (window->_getWindow()->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window->_getWindow()->close();
		}
		box.event();
		
		box.show();
		window->display(sf::Color::White);
	}
}

void Test::buttonNum()
{
	DF::Text::returnOrigin(box.combo[4])->setGlobalText(std::to_string(++num));
}

void Test::buttonTextMove()
{
	DF::Text::returnOrigin(box.combo[4])->move(-0.1, 0.05);
}

void Test::button1SetActive()
{
	DF::Text::returnOrigin(box.combo[4])->setActive(!DF::Text::returnOrigin(box.combo[4])->getActive());
	DF::Button::returnOrigin(box.combo[0])->setActive(!DF::Button::returnOrigin(box.combo[0])->getActive());
}

void Test::Button2MoveIt()
{
	DF::Button::returnOrigin(box.combo[3])->move(-0.1, 0);
}

void Test::progressBarPlus()
{
	DF::ProgressBar::returnOrigin(box.combo[7])->setProgress(DF::ProgressBar::returnOrigin(box.combo[7])->getProgress() + 1);
}

void Test::progressBarMinus()
{
	DF::ProgressBar::returnOrigin(box.combo[7])->setProgress(DF::ProgressBar::returnOrigin(box.combo[7])->getProgress() - 1);
}
