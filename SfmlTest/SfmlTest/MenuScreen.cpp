#include "MenuScreen.hpp"

MenuScreen::MenuScreen()
{
	ButtonSize.x = 150;
	ButtonSize.y = 50;

	PlayButton.setFillColor(sf::Color::Red);
	PlayButton.setSize(ButtonSize);
	PlayButton.setPosition(sf::Vector2f(325, 225));

	OptionsButton.setFillColor(sf::Color::Green);
	OptionsButton.setSize(ButtonSize);
	OptionsButton.setPosition(sf::Vector2f(325, 225 + ButtonSize.y));

	ExitButton.setFillColor(sf::Color::Blue);
	ExitButton.setSize(ButtonSize);
	ExitButton.setPosition(sf::Vector2f(325, 225 + (2 * ButtonSize.y)));

}

//überwacht die Funktionen im Menu
//Button-Press etc
void MenuScreen::Update() {

}

void MenuScreen::Draw(sf::RenderWindow &gameWindow) {
	gameWindow.draw(PlayButton);
	gameWindow.draw(OptionsButton);
	gameWindow.draw(ExitButton);
}