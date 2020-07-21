#pragma once
#include <math.h>
#include "Base.h"
#include "Element.h"
#include "FunctionInterface.h"

namespace DF
{
	class RadioButtons :
		public Base
	{
	public:
		class Style;
		static Style defoult_style;

	protected:
		class Buttons;
		std::vector<Buttons*> list;

	public:
		RadioButtons(Window* window, double x, double y, double radius, DF::FunctionInterface<>* fun = nullptr, RadioButtons::Style* style = &RadioButtons::defoult_style);
		~RadioButtons();

		/// ### Base ###
		void event();
		void show(); // drawing element

		static RadioButtons* returnOrigin(Base* object);

		void videoReset();

		/// ### more ###
		Buttons& operator [](const std::size_t n);

		void add(double x, double y, DF::FunctionInterface<>* fun = nullptr);

		long getNumberCheckButton();

		void clearAllCheck();

		void setActive(bool a);
		bool getActive();
		void setVisible(bool a);
		bool getVisible();

		void setSize(double radius);
		void resetStyle();
		void setStyle(RadioButtons::Style* style);
	};

	class RadioButtons::Style
	{
		friend class RadioButtons::Buttons;

		// active true
		sf::Color active_out_circle_color;
		sf::Color active_out_circle_outline_color;
		sf::Color active_in_circle_color;
		sf::Color active_in_circle_outline_color;
		// active false
		sf::Color inactive_out_circle_color;
		sf::Color inactive_out_circle_outline_color;
		sf::Color inactive_in_circle_color;
		sf::Color inactive_in_circle_outline_color;
		//all
		double out_outline_size;
		double in_outline_size;
		double scale_size_ring;

	public:
		Style();
		~Style();

		// get & set element style
		void setActiveOutCircleColor(sf::Color color);
		sf::Color getActiveOutCircleColor();

		void setActiveOutCircleOutlineColor(sf::Color color);
		sf::Color getActiveOutCircleOutlineColor();

		void setActiveInCircleColor(sf::Color color);
		sf::Color getActiveInCircleColor();

		void setActiveInCircleOutlineColor(sf::Color color);
		sf::Color getActiveInCircleOutlineColor();

		void setInActiveOutCircleColor(sf::Color color);
		sf::Color getInActiveOutCircleColor();

		void setInActiveOutCircleOutlineColor(sf::Color color);
		sf::Color getInActiveOutCircleOutlineColor();

		void setInActiveInCircleColor(sf::Color color);
		sf::Color getInActiveInCircleColor();

		void setInActiveInCircleOutlineColor(sf::Color color);
		sf::Color getInActiveInCircleOutlineColor();

		void setOutCircleOutlineSize(double size);
		double getOutCircleOutlineSize();

		void setInCircleOutlineSize(double size);
		double getInCircleOutlineSize();

		void setScaleRing(double size);
		double getScaleRing();

	private:
		void setStyle(Buttons* object);
	};

	class RadioButtons::Buttons :
		protected Element
	{
		friend class RadioButtons;
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
		sf::CircleShape circle[2];
		sf::Vector2f mouse_poz;
		bool press_buff; // buffored pressed button to not repeted
		bool check; // check button
		DF::FunctionInterface<>* fun;

		RadioButtons::Style* graphic_config;

		RadioButtons* master;

		Buttons(RadioButtons* master, Window* window, double x, double y, double radius, RadioButtons::Style* style = &RadioButtons::defoult_style, DF::FunctionInterface<>* fun = nullptr);
		~Buttons();

		// ### Base Class ###
		void event();
		void show(); // drawing element

		static Buttons* returnOrigin(Base* object);

		void videoReset(); // if window change render size (VideoMode)

	public:
		// ### Element Class ###
		// position & size config
		void setPosition(double x, double y);
		void move(double x, double y);

	protected:
		// activ & visible config
		void setActive(bool a);
		//bool getActive();

		//void setVisible(bool a);
		//bool getVisible();

		// ### more ###
		void setSize(double radius);
		void resetStyle();
		void setStyle(RadioButtons::Style* style);

	public:
		void setCheck(bool a);
		bool getCheck();

		void setFunction(FunctionInterface<>* function);
		void goFunction();
	};
}