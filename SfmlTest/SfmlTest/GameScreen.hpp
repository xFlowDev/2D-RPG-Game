#pragma once
#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include "Variables.hpp"
#include "TilesetManager.hpp"
#include "Player.hpp"
#include "Map.hpp"

class GameScreen {
public:
	void Update(sf::RenderWindow &, GameState &);
	void Draw();
private:
	bool isInitialzed = false;
	sf::RenderWindow *game_window = nullptr;
	sf::Texture tileset_texture;

	sf::View view = sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
	float view_move_distance = 105;
	sf::Vector2f map_size;

	Player player;
	std::vector<std::vector<sf::Sprite>> map_sprites;

	void Init(sf::RenderWindow *);
	void move_view();
};
#endif // !GAMESCREEN_H