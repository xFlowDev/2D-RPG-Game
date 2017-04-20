#pragma once
#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Variables.hpp"
#include "TilesetManager.hpp"
#include "Player.hpp"
#include "Map.hpp"

class GameScreen {
public:
	GameScreen();
	void Update(sf::RenderWindow &, GameState &);
	void Draw(sf::RenderWindow &);
private:
	bool isInitialzed = false;

	sf::Texture tileset_texture;

	Player player;
	std::vector<std::vector<sf::Sprite>> map_sprites;

	void Init();
};
#endif // !GAMESCREEN_H