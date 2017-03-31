#include "MenuScreen.hpp"

MenuScreen::MenuScreen() {
	ButtonSize.x = 150;
	ButtonSize.y = 50;

	placeButton(PlayButton, sf::Color::Red, sf::Vector2f(325, 225));
	placeButton(OptionsButton, sf::Color::Green, sf::Vector2f(325, 225 + ButtonSize.y));
	placeButton(ExitButton, sf::Color::Blue, sf::Vector2f(325, 225 + (2 * ButtonSize.y)));
}

//void MenuScreen::Init() {
//
//}

//überwacht die Funktionen im Menu
//Button-Press etc
void MenuScreen::Update(sf::RenderWindow &gameWindow, GameState &gameState) {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (isButtonPressed(PlayButton, gameWindow))
		{
			gameState = Playing;
		}
		else if (isButtonPressed(OptionsButton, gameWindow))
		{
			gameState = Options;
		}
		else if (isButtonPressed(ExitButton, gameWindow))
		{
			gameState = Exit;
		}
	}
}

void MenuScreen::Draw(sf::RenderWindow &gameWindow) {
	gameWindow.draw(PlayButton);
	gameWindow.draw(OptionsButton);
	gameWindow.draw(ExitButton);
}

void MenuScreen::placeButton(sf::RectangleShape &xButton, sf::Color xColor, sf::Vector2f xButtonPosition) {
	xButton.setFillColor(xColor);
	xButton.setSize(ButtonSize);
	xButton.setPosition(xButtonPosition);
}

bool MenuScreen::isButtonPressed(sf::RectangleShape xButton, sf::RenderWindow &xRelativeWindow) {
	sf::Vector2i lMousePosition = sf::Mouse::getPosition(xRelativeWindow);
	sf::Vector2f lButtonPosition = xButton.getPosition();
	sf::Vector2f lButtonSize = xButton.getSize();

	if (lMousePosition.x > lButtonPosition.x && lMousePosition.x < lButtonPosition.x + lButtonSize.x &&
		lMousePosition.y > lButtonPosition.y && lMousePosition.y < lButtonPosition.y + lButtonSize.y)
		return true;

	return false;
}