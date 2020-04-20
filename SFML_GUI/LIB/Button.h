#pragma once
#include "Element.h"
#include "FunctionInterface.h"

namespace DF
{
	class Button :
		public Element
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

		// ### more ###
		sf::RectangleShape rect;
		sf::Vector2f mouse_poz;
		bool buff; // buffored pressed button to not repeted
		FunctionInterface* fun_IF;

	public:
		class Style
		{
			friend class Button;
		private:
			// active true
			sf::Color active_rect_color;
			sf::Color active_outline_color;
			
			// active false
			sf::Color inactive_rect_color;
			sf::Color inactive_outline_color;
			//all
			double outline_size;
		public:
			Style();
			~Style();

			// get & set element style
			void setActiveColor(sf::Color color);
			sf::Color getActiveColor();

			void setActiveOutlineColor(sf::Color color);
			sf::Color getActiveOutlineColor();

			void setInActiveColor(sf::Color color);
			sf::Color getInActiveColor();

			void setInActiveOutlineColor(sf::Color color);
			sf::Color getInActiveOutlineColor();

			void setOutlineSize(double size);
			double getOutlineSize();

		private:
			void setStyle(Button* object);
		};

		static Style defoult_style;

	protected:
		DF::Button::Style* graf_config;

	public:
		Button(Window* window, double x, double y, double w, double h, FunctionInterface* function, Button::Style* style = &Button::defoult_style);
		~Button();


		// ### Base Class ###
		void event();
		void show(); // drawing element

		static Button* returnOrigin(Base* object);

		void videoReset(); // if window change render size (VideoMode)

		// ### Element Class ###
		// position & size config
		void setPosition(double x, double y);
		void move(double x, double y);
		void setSize(double width, double height);


		// activ & visible config
		void setActive(bool a);
		//bool getActive();

		//void setVisible(bool a);
		//bool getVisible();


		// ### more ###
		bool isPress();

		void resetStyle();

		void setFunction(FunctionInterface* function);

		void setStyle(Button::Style* style);
	};
}