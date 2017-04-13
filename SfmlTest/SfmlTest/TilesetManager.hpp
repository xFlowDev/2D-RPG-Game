#pragma once
#ifndef TILESET_MANAGER_H
#define TILESET_MANAGER_H

#include "Variables.hpp"

class TilesetManager
{
public:
	void loadTexture();

	sf::Sprite getSprite(int, int);
	sf::Sprite getSprite(int, int, int, int);
	sf::Sprite getSpriteFromPath(std::string);
private:	
	const int tileSize = 32;
	const std::string tilesetPath = "Assets\\Tilesets\\tileset.png";
	sf::Texture tilesetTexture;
};


#endif // !TILESET_MANAGER_H
