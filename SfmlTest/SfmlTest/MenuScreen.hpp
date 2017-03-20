#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class MenuScreen
{
public:
	MenuScreen();
	void Update();
	void Draw(sf::RenderWindow&);
private:
	sf::Vector2f ButtonSize;
	
	sf::RectangleShape PlayButton;
	sf::RectangleShape OptionsButton;
	sf::RectangleShape ExitButton;
};
