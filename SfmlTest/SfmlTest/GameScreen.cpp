#include "GameScreen.hpp"

GameScreen::GameScreen() {
}

void GameScreen::Update(sf::RenderWindow &GameWindow, GameState &GameState) {
	if (!isInitialzed)
		Init();
	if (isInitialzed) {
		player.Update(GameWindow, GameState);
	}
}

void GameScreen::Draw(sf::RenderWindow &GameWindow) {
	if (isInitialzed) {
		for (auto &row : map_sprites) {
			for (auto &sprite : row) {
				GameWindow.draw(sprite);
			}
		}

		player.Draw(GameWindow);
	}
}

void GameScreen::Init()
{
	TilesetManager tileset_manager;
	//Hier wird das SpriteSheet geladen
	//muss geladen werden sonst werden einfach nur weiße Flaechen angezeigt
	tileset_manager.loadTexture(tileset_texture);
	//So wird das ganze dann geladen
	//Das Texture-Objekt wird als Referenz übergeben und gefüllt
	//test = tileset_manager.getSprite(0, 0, tileset_texture);
	//test.setPosition(sf::Vector2f(0, 0));

	Map map = Map("Assets\\Maps\\map1.bmp", tileset_texture, &tileset_manager);
	map_sprites = map.getMap();

	player.setPosition(sf::Vector2f(600, 450));
	player.setSize(sf::Vector2f(20, 40));
	//TODO setSprite gefällt mir noch nicht so
	player.setSprite("Assets\\Entities\\Player.png");

	isInitialzed = true;
}