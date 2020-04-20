#pragma once
#include <vector>
#include "Base.h"

namespace DF
{
	class Container :
		public Base
	{
	protected:
		bool active; // to used element // if false -> show & event don't working

	public:
		std::vector<Base*> combo;


		Container(bool active = true);
		~Container();

		// ### BASE class ###
		void event();
		void show();
		void videoReset();
		static Container* returnOrigin(Base* object);

		// ### more ###
		void add(Base* element);
		void deleteALL();

		void setActiv(bool active);
		bool getActiv();
	};
}