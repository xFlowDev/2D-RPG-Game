#include "GameScreen.hpp"

GameScreen::GameScreen() {
	TestBlock.setFillColor(sf::Color::Green);
	TestBlock.setSize(sf::Vector2f(600, 400));
	TestBlock.setPosition(sf::Vector2f(100, 100));

	Player.setPosition(sf::Vector2f(200, 200));
	Player.setSize(sf::Vector2f(20, 40));
	Player.setSprite("Assets\\Entities\\Player.png");
}

void GameScreen::Update(sf::RenderWindow &GameWindow, GameState &GameState) {
	Player.Update(GameWindow, GameState);
}

void GameScreen::Draw(sf::RenderWindow &GameWindow) {
	GameWindow.draw(TestBlock);
	Player.Draw(GameWindow);
}