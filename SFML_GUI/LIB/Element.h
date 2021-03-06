#pragma once
#include "Base.h"
#include "Window.h"


namespace DF
{
	class Element :
		public Base
	{
	protected:
		Window* window; // window to drow element
		//size in %
		double x;
		double y;
		double w;
		double h;

		bool active; // set other style	// default true
		bool visible; // render off and activ = false // default true

	public:
		Element(Window* window, double x, double y, double w, double h);
		virtual ~Element();

		// ### with Base class ###
		//virtual void event();
		//virtual void show(); // drawing element

		static Element* returnOrigin(Base* object);

		//virtual void videoReset(); // if window change render size (VideoMode)

		// ### more function ###

		// position & size config
		void setPosition(double x, double y);
		virtual void move(double x, double y);


		// activ & visible config
		virtual void setActive(bool a);
		virtual bool getActive();

		virtual void setVisible(bool a);
		virtual bool getVisible();
	};
}