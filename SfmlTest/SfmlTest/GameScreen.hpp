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

	TilesetManager *tilesetManagerPtr = nullptr;
	sf::Sprite test;
	
	Player player;
	Map map;

	void Init();
};
#endif // !GAMESCREEN_H