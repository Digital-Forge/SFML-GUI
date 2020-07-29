#pragma once
#include "Element.h"

namespace DF
{
	class Rect :
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

	public:
		class Style;

		static Style defoult_style;

	protected:
		Rect::Style* graphic_config;

	public:
		Rect(Window* window, double x, double y, double w, double h, Rect::Style* style = &Rect::defoult_style);
		~Rect();

		// ### Base Class ###
		//void event();
		void show(); // drawing element

		static Rect* returnOrigin(Base* object);

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

		/// ### more ###
		void resetStyle();

		void setSize(double w, double h);
	};

	class Rect::Style
	{
		friend class Rect;
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

		void setLineThickness(double size);
		double getLineThickness();

		void setOutlineSize(double size);
		double getOutlineSize();

	private:
		void setStyle(Rect* object);
	};
}

