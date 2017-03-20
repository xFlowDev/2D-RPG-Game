#include "Game.hpp"

Game::Game() {
	GameWindow.create(sf::VideoMode(WIDTH, HEIGHT), "2D RPG Rougelike");
	gameState = Menu;
	GameLoop();
}
Game::~Game() {
	GameWindow.close();
}

void Game::GameLoop() {
	while (GameWindow.isOpen())
	{
		//Gameloop muss noch auf Performance angepasst werden
		//Aktuell l�uft er so schnell es geht
		//Gucken wie ich das am besten mache
		//Updates maximal genauso schnell ausf�hren wie Draws, 
		//damit die Bilder mit dem �bereinstimmen was passiert.

		sf::Event event;
		while (GameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				GameWindow.close();
		}
		Update();
		Draw();
	}
}

//Jede Klasse ist f�r ihre eigenen Updates zust�ndig
void Game::Update() {
	if (gameState == Menu)
	{
		menuScreen.Update();
	}
	else if (gameState == Playing)
	{
		//gameScreen.Update();
	}
}

//Jede Klasse zeichnet ihren eigenen Kram
void Game::Draw() {
	GameWindow.clear();
	drawActiveScreen();
	GameWindow.display();
}

void Game::drawActiveScreen() {
	if (gameState == Menu)
	{
		menuScreen.Draw(GameWindow);
	}
	//else if (gameState == Playing)
	//{
	//	//gameScreen.Draw();
	//}
}