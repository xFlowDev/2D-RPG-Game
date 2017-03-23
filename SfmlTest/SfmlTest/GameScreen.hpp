#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Enums.hpp"

class GameScreen
{
public:
	GameScreen();
	void Update(sf::RenderWindow &, GameState &);
	void Draw(sf::RenderWindow &);
private:
	sf::RectangleShape TestBlock;
};
