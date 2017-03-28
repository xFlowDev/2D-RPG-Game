#include "Game.hpp"

Game::Game() {
	GameWindow.create(sf::VideoMode(WIDTH, HEIGHT), "2D RPG Rougelike");
	GameState = Menu;

	frameTime = 1.f;
	//frameTime = 1.6666666666666666666667f;
	deltaTimeMs = 0.f;
	Updates = 0;
	FPS = 0;
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

		//GameLoop funktioniert
		//Aber läuft nicht so konsistent wie ich das gerne hätte
		//Die Schwankung in den Updates sind meiner Meinung nach zu groß
		//Zwischen 40 und 80 Update/s ist alles drin, ich habe aber keine Ahnung woran das liegt
		//Weil sonst nichts anderes ausgeführt wird was die Leistung verändern würde

		startTime = std::chrono::high_resolution_clock::now();
		deltaTime = startTime - currentTime;
		deltaTimeMs += (float)std::chrono::duration_cast<std::chrono::milliseconds>(deltaTime).count();
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
		if (diff > 1000 && Updates)
		{
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