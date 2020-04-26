#pragma once
#include "Element.h"

namespace DF
{
	class Text :
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
		sf::Text txt;

		bool last_set_text; // 0 - setText  ;  1 - setGlobalText
		sf::String text[2];

	public:
		class Style
		{
			friend class Text;
		private:
			// active true
			sf::Color active_text_color;
			sf::Color active_outline_color;

			// active false
			sf::Color inactive_text_color;
			sf::Color inactive_outline_color;
			//all
			sf::Font* font;
			double outline_size;
			double font_size;
			double level_correct;

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
			void setFont(sf::Font* font);
			void setCorrectLevel(double level);
			double getCorrectLevel();

			void setTextSize(double size);
			double getTextSize();

			void setHook(Style::Hook hook);
			Style::Hook getHook();

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
			void setStyle(Text* object);
		};

		static Style defoult_style;

	protected:
		DF::Text::Style* graphic_config;

	public:
		Text(Window* window, double x, double y, sf::String text, Text::Style* style = &Text::defoult_style);
		~Text();

		// ### Base Class ###
		//void event();
		void show(); // drawing element

		static Text* returnOrigin(Base* object);

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
		void _setText(sf::String text);			// change single text
		void setGlobalText(sf::String text);	// change text with reposition

		void resetStyle();
		void setStyle(Text::Style* style);
	};
}