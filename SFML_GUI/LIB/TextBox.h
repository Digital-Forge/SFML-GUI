#pragma once
#include "Element.h"

namespace DF
{
	class TextBox :
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
		bool write_active;	
		sf::Text txt[2];
		sf::String text[2];
		unsigned int limit_letters;

	public:
		class Style
		{
			friend class TextBox;
		private:
			// active true
			sf::Color active_rect_color;
			sf::Color active_rect_outline_color;

			sf::Color active_text_color;
			sf::Color active_text_outline_color;

			sf::Color active_phantom_text_color;
			sf::Color active_phantom_text_outline_color;

			// active false
			sf::Color inactive_rect_color;
			sf::Color inactive_rect_outline_color;

			sf::Color inactive_text_color;
			sf::Color inactive_text_outline_color;

			sf::Color inactive_phantom_text_color;
			sf::Color inactive_phantom_text_outline_color;

			// font
			sf::Font* font;
			double level_correct;
			double text_outline_size;
			double phantom_text_outline_size;
			double rect_outline_size;

		public:
			enum class Hook
			{
				left,
				center,
				right
			};
		private:
			Hook hook;

		public:
			Style();
			~Style();

			// get & set element style
			// # rect
			void setActiveRectColor(sf::Color color);
			sf::Color getActiveRectColor();

			void setActiveRectOutlineColor(sf::Color color);
			sf::Color getActiveRectOutlineColor();

			void setInActiveRectColor(sf::Color color);
			sf::Color getInActiveRectColor();

			void setInActiveRectOutlineColor(sf::Color color);
			sf::Color getInActiveRectOutlineColor();

			void setRectOutlineSize(double size);
			double getRectOutlineSize();

			// # text
			void setFont(sf::Font* font);
			void setTextCorrectLevel(double level);
			double getTextCorrectLevel();

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

			void setActivePhantomTextColor(sf::Color color);
			sf::Color getActivePhantomTextColor();

			void setActivePhantomTextOutlineColor(sf::Color color);
			sf::Color getActivePhantomTextOutlineColor();

			void setInActivePhantomTextColor(sf::Color color);
			sf::Color getInActivePhantomTextColor();

			void setInActivePhantomTextOutlineColor(sf::Color color);
			sf::Color getInActivePhantomTextOutlineColor();

			void setPhantomTextOutlineSize(double size);
			double getPhantomTextOutlineSize();

		private:
			void setStyle(TextBox* object);
		};

		static Style defoult_style;

	protected:
		DF::TextBox::Style* graphic_config;

	public:
		TextBox(Window* window, double x, double y, double w, double h, sf::String phantom_text = "", TextBox::Style* style = &TextBox::defoult_style);
		~TextBox();

		// ### Base Class ###
		void event();
		void show(); // drawing element

		static TextBox* returnOrigin(Base* object);

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


		// ### more ###
		void setSize(double width, double height);

		void resetStyle();
		void setStyle(TextBox::Style* style);

		void setText(sf::String text);
		sf::String getText();

		void setPhantomText(sf::String text);

		void setLettersLimit(unsigned int limit);
	};
}