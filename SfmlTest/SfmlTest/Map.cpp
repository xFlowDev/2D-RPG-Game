#include "Map.hpp"

Map::Map(std::string file, sf::Texture &texture, TilesetManager *tileset_manager) {
	sf::Image map_image;
	if (!map_image.loadFromFile(file)) {
		std::cerr << "Fehler beim laden des Files: " << file << std::endl;
	}
	else {
		Size = map_image.getSize();
		for (unsigned int y = 0; y < Size.y; y++) {
			std::vector<sf::Sprite> row;
			for (unsigned int x = 0; x < Size.x; x++) {
				sf::Sprite sprite;
				sf::Color color = map_image.getPixel(x, y);
				if (color == GRAS) {
					sprite = tileset_manager->getSprite(0, 0, texture);
				}
				else if (color == WASSER) {
					sprite = tileset_manager->getSprite(1, 0, texture);
				}
				else if (color == RAND_OBEN) {
					sprite = tileset_manager->getSprite(7, 2, texture);
				}
				else if (color == RAND_LINKS) {
					sprite = tileset_manager->getSprite(8, 1, texture);
				}
				else if (color == RAND_UNTEN) {
					sprite = tileset_manager->getSprite(7, 0, texture);
				}
				else if (color == RAND_RECHTS) {
					sprite = tileset_manager->getSprite(6, 1, texture);
				}
				else if (color == ECKE_LINKS_OBEN) {
					sprite = tileset_manager->getSprite(9, 0, texture);
				}
				else if (color == ECKE_LINKS_UNTEN) {
					sprite = tileset_manager->getSprite(5, 2, texture);
				}
				else if (color == ECKE_RECHTS_OBEN) {
					sprite = tileset_manager->getSprite(9, 1, texture);
				}
				else if (color == ECKE_RECHTS_UNTEN) {
					sprite = tileset_manager->getSprite(5, 1, texture);
				}



				sprite.setPosition((float)x * 32, (float)y * 32);
				row.push_back(sprite);
			}
			map.push_back(row);
		}
	}
}

std::vector<std::vector<sf::Sprite>> Map::getMapSprites()
{
	return map;
}

sf::Vector2u Map::getMapSize() {
	return Size;
}
