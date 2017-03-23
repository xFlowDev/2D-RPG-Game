#include "Game.hpp"

Game::Game() {
	GameWindow.create(sf::VideoMode(WIDTH, HEIGHT), "2D RPG Rougelike");
	GameState = Menu;
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
	if (GameState == Menu)
	{
		menuScreen.Update(GameWindow, GameState);
	}
	else if (GameState == Playing)
	{
		gameScreen.Update(GameWindow, GameState);
	}
}

//Jede Klasse zeichnet ihren eigenen Kram
void Game::Draw() {
	GameWindow.clear();
	if (GameState == Menu)
	{
		menuScreen.Draw(GameWindow);
	}
	else if (GameState == Playing)
	{
		gameScreen.Draw(GameWindow);
	}
	GameWindow.display();
}