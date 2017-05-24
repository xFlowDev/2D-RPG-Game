#pragma once
#ifndef MAP_H
#define MAP_H

#include "Variables.hpp"
#include "TilesetManager.hpp"

#define GRAS sf::Color(0, 145, 2)

#define RAND_OBEN sf::Color(145, 90, 42)
#define RAND_LINKS sf::Color(145, 90, 43)
#define RAND_UNTEN sf::Color(145, 90, 44)
#define RAND_RECHTS sf::Color(145, 90, 45)
#define ECKE_LINKS_OBEN sf::Color(145, 91, 42)
#define ECKE_LINKS_UNTEN sf::Color(145, 92, 42)
#define ECKE_RECHTS_OBEN sf::Color(145, 93, 42)
#define ECKE_RECHTS_UNTEN sf::Color(145, 94, 42)

#define WASSER sf::Color(33, 70, 255)

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