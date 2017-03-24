#include "Game.hpp"

Game::Game() {
	GameWindow.create(sf::VideoMode(WIDTH, HEIGHT), "2D RPG Rougelike");
	GameState = Menu;

	frameTime = 1;
	deltaTimeMs = 0;
	Updates = 0;
	FPS = 0;
	Updates = 0;
	Timer = std::chrono::high_resolution_clock::now();
	currentTime = std::chrono::high_resolution_clock::now();
}
Game::~Game() {
	GameWindow.close();
}

void Game::GameLoop() {
	while (GameWindow.isOpen())
	{
		sf::Event event;
		while (GameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				GameWindow.close();
		}
		//Gameloop muss noch auf Performance angepasst werden
		//Aktuell läuft er so schnell es geht
		//Gucken wie ich das am besten mache
		//Updates maximal genauso schnell ausführen wie Draws, 
		//damit die Bilder mit dem übereinstimmen was passiert.


		startTime = std::chrono::high_resolution_clock::now();
		deltaTime = startTime - currentTime;
		deltaTimeMs += std::chrono::duration_cast<std::chrono::milliseconds>(deltaTime).count();

		currentTime = startTime;

		while (deltaTimeMs >= frameTime)
		{
			Update();
			Updates++;
			deltaTimeMs -= frameTime;
		}

		Draw();
		FPS++;

		auto now = std::chrono::high_resolution_clock::now();
		auto diff = std::chrono::duration_cast<std::chrono::milliseconds>(now - Timer).count();
		if (diff > 1000)
		{
			Timer += std::chrono::milliseconds(1000);
			std::cout << "FPS: " << FPS << " Updates: " << Updates << std::endl;
			FPS = 0;
			Updates = 0;
		}


	}
}

//Jede Klasse ist für ihre eigenen Updates zuständig
//GameWindow muss mitgegeben werden damit ich zugriff auf die Maus-Position relativ zum GameWindow habe
void Game::Update() {
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
	drawGameStatistics();
	//Referenz von GameWindow wird übergegeben
	//ein Objekt zeichet alles
	if (GameState == Menu)
		menuScreen.Draw(GameWindow);
	else if (GameState == Playing)
		gameScreen.Draw(GameWindow);

	GameWindow.display();
}

//zeichnet FPS, Updates und weiteres als Text in as GameWindow
void Game::drawGameStatistics() {

}