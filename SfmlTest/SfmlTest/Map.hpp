#pragma once
#ifndef MAP_H
#define MAP_H

#include "Variables.hpp"

class Map {
public:
	Map();

	void Update(sf::RenderWindow &, GameState &);
	void Draw(sf::RenderWindow &);

	void loadMap(std::string);

private:
	float x, y;
	sf::Vector2f Size;
	
	const std::string tilesetFilename = "tileset.png";
	std::string mapFilename;
};
#endif // !MAP_H