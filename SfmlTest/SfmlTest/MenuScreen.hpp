#pragma once
#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <iostream>
#include "Variables.hpp"

class MenuScreen
{
public:
	MenuScreen();
	void Update(sf::RenderWindow &, GameState&);
	void Draw(sf::RenderWindow &);
	void placeButton(sf::RectangleShape &, sf::Color, sf::Vector2f);

private:
	bool isInitialized = false;

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

	void Init();

	bool isButtonPressed(sf::RectangleShape, sf::RenderWindow &);

	void setTitleText();
};
#endif // !MENUSCREEN_H