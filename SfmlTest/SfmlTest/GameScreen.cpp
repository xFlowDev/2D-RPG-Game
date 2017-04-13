#include "GameScreen.hpp"

GameScreen::GameScreen() {
}

void GameScreen::Update(sf::RenderWindow &GameWindow, GameState &GameState) {
	if (!isInitialzed)
		Init();
	if (isInitialzed)
	{
		player.Update(GameWindow, GameState);
	}
}

void GameScreen::Draw(sf::RenderWindow &GameWindow) {
	if (isInitialzed)
	{
		player.Draw(GameWindow);
		GameWindow.draw(test);
	}
}

void GameScreen::Init()
{
	TilesetManager tilesetManager;
	tilesetManagerPtr = &tilesetManager;
	//Damit die Texturen des TileSets da sind
	//Sonst werden nur weiﬂe Balken auf dem Screen angezeigt
	tilesetManagerPtr->loadTexture();
	test.setPosition(sf::Vector2f(0, 0));
	test = tilesetManagerPtr->getSprite(1, 1);
	//TODO das funktioniert nicht, es wird immer noch der weiﬂe Balken ausgegeben


	player.setPosition(sf::Vector2f(600, 450));
	player.setSize(sf::Vector2f(20, 40));
	player.setSprite("Assets\\Entities\\Player.png");

	isInitialzed = true;
}