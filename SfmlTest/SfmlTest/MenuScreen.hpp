#pragma once

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Enums.hpp"

class MenuScreen
{
public:
	MenuScreen(int, int);
	void Update(sf::RenderWindow &, GameState&);
	void Draw(sf::RenderWindow &);
	//void Init();
	void placeButton(sf::RectangleShape &, sf::Color, sf::Vector2f);

private:
	int WIDTH, HEIGHT;

	const int TitleCharSize = 150;
	const std::string GameTitle = "Game";
	sf::Font TitleFont;
	sf::Text TitleText;
	sf::Vector2f TitlePosition;
	sf::Color TitleTextColor = sf::Color::White;


	sf::Vector2f ButtonSize;
	sf::RectangleShape PlayButton;
	sf::RectangleShape OptionsButton;
	sf::RectangleShape ExitButton;

	bool isButtonPressed(sf::RectangleShape, sf::RenderWindow &);

	void setTitleText();
};
