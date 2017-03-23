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
		//Aktuell läuft er so schnell es geht
		//Gucken wie ich das am besten mache
		//Updates maximal genauso schnell ausführen wie Draws, 
		//damit die Bilder mit dem übereinstimmen was passiert.

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

//Jede Klasse ist für ihre eigenen Updates zuständig
//GameWindow muss mitgegeben werden damit ich zugriff auf die Maus-Position relativ zum GameWindow habe
void Game::Update() {
	//if (GameState == Menu)
	//	menuScreen.Update(GameWindow, GameState);
	//else if (GameState == Playing)
	//	gameScreen.Update(GameWindow, GameState);

	switch (GameState)
	{
	case Menu:
		menuScreen.Update(GameWindow, GameState);
		break;
	case Options:
		break;
	case Playing:
		gameScreen.Update(GameWindow, GameState);
		break;
	case Pause:
		break;
	case Exit:
		break;
	default:
		break;
	}

}

//Jede Klasse zeichnet ihren eigenen Kram
void Game::Draw() {
	GameWindow.clear();

	//Referenz von GameWindow wird übergegeben
	//ein Objekt zeichet alles
	if (GameState == Menu)
		menuScreen.Draw(GameWindow);
	else if (GameState == Playing)
		gameScreen.Draw(GameWindow);

	GameWindow.display();
}