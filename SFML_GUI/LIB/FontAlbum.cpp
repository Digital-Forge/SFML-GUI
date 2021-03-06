#include "FontAlbum.h"

DF::FontAlbum::FontAlbum()
{
}

DF::FontAlbum::~FontAlbum()
{
	for (unsigned short i = 0; i < combo.size(); i++)
	{
		delete combo[i];
	}
	combo.clear();
}

bool DF::FontAlbum::add(sf::String path)
{
	combo.push_back(new sf::Font);

	if (combo[combo.size() - 1]->loadFromFile(path))
	{
		return true;
	}
	else
	{
		delete combo[combo.size() - 1];
		combo.pop_back();
		return false;
	}
}

void DF::FontAlbum::add(sf::Font* font)
{
	combo.push_back(new sf::Font(*font));
}

sf::Font* DF::FontAlbum::getFont(unsigned short i)
{
	if (combo.size() > i)
	{
		return combo[i];
	}
	return nullptr;
}
