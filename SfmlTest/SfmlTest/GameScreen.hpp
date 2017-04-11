#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Enums.hpp"
#include "Player.hpp"

class GameScreen
{
public:
	GameScreen(int, int);
	void Update(sf::RenderWindow &, GameState &);
	void Draw(sf::RenderWindow &);
private:
	int WIDTH, HEIGHT;

	sf::RectangleShape TestBlock;
	Player Player;
};
