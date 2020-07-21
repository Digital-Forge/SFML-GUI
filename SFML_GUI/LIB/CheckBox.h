#pragma once
#include "Button.h"

namespace DF
{
	class CheckBox :
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
		FunctionInterface<bool>* fun_IF;

		// ### more ###
		sf::RectangleShape symbol[2];
		bool check;

	public:
		class Style;

		static Style defoult_style;

	protected:
		DF::CheckBox::Style* graphic_config;

	public:
		CheckBox(Window* window, double x, double y, double size, FunctionInterface<bool>* function = nullptr, CheckBox::Style* style = &CheckBox::defoult_style);
		~CheckBox();

		// ### Base Class ###
		//void event();
		void show(); // drawing element

		static CheckBox* returnOrigin(Base* object);

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
		void setSize(double width, double height) = delete;
		void setSize(double size);

		bool isPress() = delete;

		void resetStyle();
		void setStyle(CheckBox::Style* style);

		void setFunction(FunctionInterface<bool>* function);

		// ### more ###
		bool isCheck();

		void setCheck(bool status);

	protected:
		void checkExecute();
	};

	class CheckBox::Style
	{
		friend class CheckBox;
	private:
		// active true
		sf::Color active_rect_color;
		sf::Color active_outline_color;
		sf::Color active_symbol_color;

		// active false
		sf::Color inactive_rect_color;
		sf::Color inactive_outline_color;
		sf::Color inactive_symbol_color;

		//all
		double symbol_size;
		double outline_size;
		double symbol_angle_ray_left, symbol_angle_ray_right, symbol_scale;
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

		void setActiveSymbolColor(sf::Color color);
		sf::Color getActiveSymbolColor();

		void setInActiveSymbolColor(sf::Color color);
		sf::Color getInActiveSymbolColor();

		void setOutlineSize(double size);
		double getOutlineSize();

		void setSymbolSize(double size);
		double getSymbolSize();

		void setSymbolRayScale(double scale);
		double getSymbolRayScale();

		void setSymbolRayLeftAngle(double angle);
		double setSymbolRayLeftAngle();

		void setSymbolRayRightAngle(double angle);
		double setSymbolRayRightAngle();

	private:
		void setStyle(CheckBox* object);
	};

}