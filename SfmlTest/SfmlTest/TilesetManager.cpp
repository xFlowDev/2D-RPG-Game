#include "TilesetManager.hpp"

void TilesetManager::loadTexture() {
	if (!tilesetTexture.loadFromFile(tilesetPath)) {
		std::cerr << "Fehler beim Laden des Tileset" << std::endl;
	}
}

sf::Sprite TilesetManager::getSprite(int x, int y) {
	//Lade den Teil des Tileset welche angefordert wurde
	//Hole Tile von Position x y
	sf::Sprite sprite;
	sprite.setTexture(tilesetTexture);
	sprite.setTextureRect(sf::IntRect(x * tileSize, y * tileSize, tileSize, tileSize));
	return sprite;
}

sf::Sprite TilesetManager::getSprite(int x, int y, int width, int height) {
	//Lade Sprite abweichend von der Standard Größe
	//Position auf dem SpriteSheet muss noch stimmen
	sf::Sprite sprite;
	sprite.setTextureRect(sf::IntRect(x * tileSize, y * tileSize, width, height));
	return sprite;
}

sf::Sprite TilesetManager::getSpriteFromPath(std::string path) {
	sf::Texture texture;
	sf::Sprite sprite;
	if (!texture.loadFromFile(path))
		std::cerr << "Fehler beim Laden von: " << path << std::endl;
	else
		sprite.setTexture(texture);

	return sprite;
}