#include "Game.hpp"

#define TIME_POINT std::chrono::time_point<std::chrono::high_resolution_clock>
#define DURATION std::chrono::duration<double>

Game::Game() {
	GameWindow.create(sf::VideoMode(WIDTH, HEIGHT), "2D RPG Rougelike");
	GameState = Menu;
}
Game::~Game() {
	GameWindow.close();
}

void Game::GameLoop() {
	Timer = std::chrono::high_resolution_clock::now();
	double dt = 0.016666666666666667;

	TIME_POINT currentTime = std::chrono::high_resolution_clock::now();
	double accumulator = 0.0;

	while (GameWindow.isOpen())
	{
		sf::Event event;
		while (GameWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				GameWindow.close();
		}

		TIME_POINT newTime = std::chrono::high_resolution_clock::now();
		DURATION frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime.count();
		
		while (accumulator >= dt) {
			Update();
			accumulator -= dt;
			Updates++;
		}

		Draw();
		FPS++;

		TIME_POINT now = std::chrono::high_resolution_clock::now();
		DURATION diff = now - Timer;
		if (diff > std::chrono::seconds(1))	{
			Timer += std::chrono::milliseconds(1000);
			//TODO diese Daten in eine Debug-Anzeige im Screen zeichnen
			//Mit möglichkeit die Anzeige zu aktivieren/deaktivieren
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
	drawDebugInfo();
	//Referenz von GameWindow wird übergegeben
	//ein Objekt zeichnet alles
	if (GameState == Menu)
		menuScreen.Draw(GameWindow);
	else if (GameState == Playing)
		gameScreen.Draw(GameWindow);

	GameWindow.display();
}

//zeichnet FPS, Updates und weiteres als Text in as GameWindow
void Game::drawDebugInfo() {

}