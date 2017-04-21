#include "Map.hpp"

Map::Map(std::string file, sf::Texture &texture, TilesetManager *tileset_manager) {
	sf::Image map_image;
	if (!map_image.loadFromFile(file)) {
		std::cerr << "Fehler beim laden des Files: " << file << std::endl;
	}
	else {
		Size = map_image.getSize();
		for (auto y = 0; y < Size.y; y++) {
			std::vector<sf::Sprite> row;
			for (auto x = 0; x < Size.x; x++) {
				sf::Sprite sprite;
				sf::Color color = map_image.getPixel(x, y);
				if (color == GRAS) {
					sprite = tileset_manager->getSprite(0, 0, texture);					
				}
				else if (color == WASSER) {
					sprite = tileset_manager->getSprite(1, 0, texture);
				}
				else if (color == RAND) {
					sprite = tileset_manager->getSprite(2, 0, texture);
				}
				sprite.setPosition(x * 32, y * 32);
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
