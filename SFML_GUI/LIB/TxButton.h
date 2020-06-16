#pragma once
#include "Button.h"
#include "FunctionInterface.h"

namespace DF
{
	class TxButton :
		public Button
	{
	protected:
		// ### Base Class ###

		// ### Element Class ###
		//Window* window; // window to drow element
		//size in %
		//double x;
		//double y;
		//double w;
		//double h;
		//bool active; // set other style	// default true
		//bool visible; // render off and activ = false  // default true

		// ### Button Class ###
		//sf::RectangleShape rect;
		//sf::Vector2f mouse_poz;
		//bool buff; // buffored pressed button to not repeted
		//FunctionInterface* fun_IF;

		// ### more ###
		sf::Text txt;

	public:
		class Style
		{
			friend class TxButton;
		private:
			// active true
			sf::Color active_rect_color;
			sf::Color active_rect_outline_color;

			sf::Color active_text_color;
			sf::Color active_text_outline_color;

			// active false
			sf::Color inactive_rect_color;
			sf::Color inactive_rect_outline_color;

			sf::Color inactive_text_color;
			sf::Color inactive_text_outline_color;

			// font
			sf::Font* font;
			double level_correct;
			double text_outline_size;
			double rect_outline_size;
			double distance_from_edge;

		public:
			Style();
			~Style();

			// get & set element style
			// # Button/rect
			void setActiveButtonColor(sf::Color color);
			sf::Color getActiveButtonColor();

			void setActiveButtonOutlineColor(sf::Color color);
			sf::Color getActiveButtonOutlineColor();

			void setInActiveButtonColor(sf::Color color);
			sf::Color getInActiveButtonColor();

			void setInActiveButtonOutlineColor(sf::Color color);
			sf::Color getInActiveButtonOutlineColor();

			void setButtonOutlineSize(double size);
			double getButtonOutlineSize();

			// # text
			void setFont(sf::Font* font);
			void setCorrectLevel(double level);
			double getCorrectLevel();

			void setActiveTextColor(sf::Color color);
			sf::Color getActiveTextColor();

			void setActiveTextOutlineColor(sf::Color color);
			sf::Color getActiveTextOutlineColor();

			void setInActiveTextColor(sf::Color color);
			sf::Color getInActiveTextColor();

			void setInActiveTextOutlineColor(sf::Color color);
			sf::Color getInActiveTextOutlineColor();

			void setTextOutlineSize(double size);
			double getTextOutlineSize();

			void _setDistanceFromEdge(double size);
			double _setDistanceFromEdge();

		private:
			void setStyle(TxButton* object);
		};

		static Style defoult_style;

	protected:
		DF::TxButton::Style* graphic_config;

	public:
		TxButton(Window* window, double x, double y, double w, double h, sf::String text = "", FunctionInterface<>* function = nullptr, TxButton::Style* style = &TxButton::defoult_style);
		~TxButton();

		// ### Base Class ###
		//void event();
		void show(); // drawing element

		static TxButton* returnOrigin(Base* object);

		void videoReset(); // if window change render size (VideoMode)

		// ### Element Class ###
		// position & size config
		void setPosition(double x, double y);
		void move(double x, double y);

		// activ & visible config
		void setActive(bool a);
		//bool getActive();

		//void setVisible(bool a);
		//bool getVisible();


		// ### Button Class ###
		void setSize(double width, double height);

		//bool isPress();

		void resetStyle();
		void setStyle(TxButton::Style* style);

		//void setFunction(FunctionInterface* function);

		// ### more ###
		void setText(sf::String text);

		protected:
			void textReset();
		public:

	};
}