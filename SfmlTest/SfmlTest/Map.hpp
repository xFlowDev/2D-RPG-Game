#pragma once
#ifndef MAP_H
#define MAP_H

#include "Variables.hpp"
#include "TilesetManager.hpp"

class Map {
public:
	Map(std::string, sf::Texture &, TilesetManager *);
	std::vector<std::vector<sf::Sprite>> getMapSprites();
	sf::Vector2u getMapSize();
private:
	sf::Vector2u Size;
	std::vector<std::vector<sf::Sprite>> map;
};
#endif // !MAP_H