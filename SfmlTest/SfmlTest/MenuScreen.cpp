#include "MenuScreen.hpp"

MenuScreen::MenuScreen() {
}

void MenuScreen::Update(sf::RenderWindow &gameWindow, GameState &gameState) {
	if (!isInitialized)
	{
		Init();
	}
	if (isInitialized)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (isButtonPressed(PlayButton, gameWindow))
				gameState = Playing;
			else if (isButtonPressed(OptionsButton, gameWindow))
				gameState = Options;
			else if (isButtonPressed(ExitButton, gameWindow))
				gameState = Exit;
		}
	}
}

void MenuScreen::Draw(sf::RenderWindow &gameWindow) {
	gameWindow.draw(TitleText);
	//TODO Buttons durch Texte ersetzen
	gameWindow.draw(PlayButton);
	gameWindow.draw(OptionsButton);
	gameWindow.draw(ExitButton);

}

void MenuScreen::Init() {
	setTitleText();

	//Setze all Buttons an ihre Stelle relativ zum Bildschrim
	ButtonSize.x = 300;
	ButtonSize.y = 100;
	float spaceBetweenButtons = 50;
	float vertSplit = 3;
	placeButton(PlayButton, sf::Color::Red, sf::Vector2f(WIDTH / 2 - ButtonSize.x / 2, HEIGHT / vertSplit));
	placeButton(OptionsButton, sf::Color::Green, sf::Vector2f(WIDTH / 2 - ButtonSize.x / 2, HEIGHT / vertSplit + ButtonSize.y + spaceBetweenButtons));
	placeButton(ExitButton, sf::Color::Blue, sf::Vector2f(WIDTH / 2 - ButtonSize.x / 2, HEIGHT / vertSplit + (2 * ButtonSize.y) + spaceBetweenButtons * 2));
	isInitialized = true;
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

void MenuScreen::setTitleText()
{
	if (!TitleFont.loadFromFile("Assets\\Fonts\\wintersolstice.ttf"))
	{
		std::cerr << "Error Loading Title Font asdasd as" << std::endl;
	}
	else {
		TitleText.setString(GameTitle);
		TitleText.setFont(TitleFont);
		TitleText.setCharacterSize(TitleCharSize);
		//damit die Width berechnet werden kann, müssen String, Font und CharSize vorher festgelegt werden
		float textWidth = TitleText.getLocalBounds().width;
		TitlePosition = sf::Vector2f(WIDTH / 2.f - textWidth / 2.f, 0);
		TitleText.setPosition(TitlePosition);
		TitleText.setFillColor(TitleTextColor);
	}
}
