#include "GameScreen.hpp"

GameScreen::GameScreen() {
	TestBlock.setFillColor(sf::Color::Green);
	TestBlock.setSize(sf::Vector2f(600, 400));
	TestBlock.setPosition(sf::Vector2f(100, 100));
}

void GameScreen::Update(sf::RenderWindow &GameWindow, GameState &GameState) {

}

void GameScreen::Draw(sf::RenderWindow &GameWindow) {
	GameWindow.draw(TestBlock);
}