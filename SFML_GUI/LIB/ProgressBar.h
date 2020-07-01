#pragma once
#include "Element.h"

namespace DF
{
	class ProgressBar :
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
		sf::RectangleShape box[2];
		sf::RectangleShape progress_bar;
		double progress;

	public:
		class Style
		{
			friend class ProgressBar;
		private:
			// active true
			sf::Color active_outbox_color;
			sf::Color active_outbox_outline_color;
			sf::Color active_inbox_color;
			sf::Color active_inbox_outline_color;
			sf::Color active_progress_bar_color;
			sf::Color active_progress_bar_outline_color;

			// active false
			sf::Color inactive_outbox_color;
			sf::Color inactive_outbox_outline_color;
			sf::Color inactive_inbox_color;
			sf::Color inactive_inbox_outline_color;
			sf::Color inactive_progress_bar_color;
			sf::Color inactive_progress_bar_outline_color;

			//all
			double outbox_outline_size;
			double progress_bar_outline_size;
			double inbox_outline_size;
			sf::Vector2f inbox_padding;

		public:
			Style();
			~Style();

			// get & set element style
			void setActiveOutBoxColor(sf::Color color);
			sf::Color getActiveOutBoxColor();

			void setActiveOutBoxOutlineColor(sf::Color color);
			sf::Color getActiveOutBoxOutlineColor();

			void setActiveInBoxColor(sf::Color color);
			sf::Color getActiveInBoxColor();

			void setActiveInBoxOutlineColor(sf::Color color);
			sf::Color getActiveInBoxOutlineColor();

			void setActiveProgressBarColor(sf::Color color);
			sf::Color getActiveProgressBarColor();

			void setActiveProgressBarOutlineColor(sf::Color color);
			sf::Color getActiveProgressBarOutlineColor();

			void setInActiveOutBoxColor(sf::Color color);
			sf::Color getInActiveOutBoxColor();

			void setInActiveOutBoxOutlineColor(sf::Color color);
			sf::Color getInActiveOutBoxOutlineColor();

			void setInActiveInBoxColor(sf::Color color);
			sf::Color getInActiveInBoxColor();

			void setInActiveInBoxOutlineColor(sf::Color color);
			sf::Color getInActiveInBoxOutlineColor();

			void setInActiveProgressBarColor(sf::Color color);
			sf::Color getInActiveProgressBarColor();

			void setInActiveProgressBarOutlineColor(sf::Color color);
			sf::Color getInActiveProgressBarOutlineColor();

			void setOutBoxOutlineSize(double size);
			double getOutBoxOutlineSize();

			void setInBoxOutlinesSize(double size);
			double getInBoxOutlinesSize();

			void setPorgressBarOutlinesSize(double size);
			double getProgressBarOutlinesSize();

			void setInBoxPadding(sf::Vector2f scale);
			void setInBoxPadding(double scale_x, double scale_y);
			sf::Vector2f getInBoxPadding();


		private:
			void setStyle(ProgressBar* object);
		};

		static Style defoult_style;

	protected:
		DF::ProgressBar::Style* graphic_config;

	public:
		ProgressBar(Window* window, double x, double y, double w, double h, ProgressBar::Style* style = &ProgressBar::defoult_style);
		~ProgressBar();

		// ### Base Class ###
		//void event();
		void show(); // drawing element

		static ProgressBar* returnOrigin(Base* object);

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
		void resetStyle();

		void setSize(double w, double h);

		void setProgress(double progress);
		double getProgress();
	};
}