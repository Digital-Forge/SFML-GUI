#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

namespace DF
{
	class FontAlbum
	{
	protected:
		std::vector<sf::Font*> combo;

	public:
		FontAlbum();
		~FontAlbum();

		bool add(sf::String path); // patch to load font file
		void add(sf::Font* font); // add other object font

		sf::Font* getFont(unsigned short i);
	};
}

