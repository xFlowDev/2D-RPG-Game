#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Enums.hpp"

class MenuScreen
{
public:
	MenuScreen();
	void Update(sf::RenderWindow &, GameState&);
	void Draw(sf::RenderWindow &);
	void placeButton(sf::RectangleShape &, sf::Color, sf::Vector2f);

private:
	sf::Vector2f ButtonSize;

	sf::RectangleShape PlayButton;
	sf::RectangleShape OptionsButton;
	sf::RectangleShape ExitButton;

	bool isButtonPressed(sf::RectangleShape, sf::RenderWindow &);
};
