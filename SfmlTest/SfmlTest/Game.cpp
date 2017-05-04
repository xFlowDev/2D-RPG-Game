#include "Game.hpp"

Game::Game() {
	GameWindow.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "2D RPG Rougelike");
	GameState = Menu;
	setDebugText();
}
Game::~Game() {
	GameWindow.close();
}

void Game::GameLoop() {
	timer = std::chrono::high_resolution_clock::now();
	dt = 0.016666666666666667f;

	currentTime = std::chrono::high_resolution_clock::now();
	accumulator = 0.0f;

	while (GameWindow.isOpen())
	{
		sf::Event event;
		while (GameWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				GameWindow.close();
		}

		newTime = std::chrono::high_resolution_clock::now();
		frameTime = newTime - currentTime;
		currentTime = newTime;
		accumulator += frameTime.count();

		while (accumulator >= dt) {
			Update();
			accumulator -= dt;
			Updates++;
		}

		Draw();
		FPS++;

		now = std::chrono::high_resolution_clock::now();
		diff = now - timer;
		if (diff > std::chrono::seconds(1)) {
			timer += std::chrono::seconds(1);
			UpdatesText.setString("UPS: " + std::to_string(Updates));
			FpsText.setString("FPS: " + std::to_string(FPS));
			FPS = 0;
			Updates = 0;
		}
	}
}

//Jede Klasse ist für ihre eigenen Updates zuständig
//GameWindow muss mitgegeben werden damit ich zugriff auf die Maus-Position relativ zum GameWindow habe
void Game::Update() {
	view = GameWindow.getView();
	setDebugTextPosition();

	switch (GameState)
	{
	case Menu:
		menuScreen.Update(GameWindow, GameState);
		break;
	case Options:
		//optionsScreen.Update(GameWindow, GameState);
		break;
	case Playing:
		gameScreen.Update(GameWindow, GameState);
		break;
	case Pause:
		break;
	case Exit:
		GameWindow.close();
		break;
	default:
		break;
	}
}

//Jede Klasse zeichnet ihren eigenen Kram
void Game::Draw() {
	GameWindow.clear();

	switch (GameState)
	{
	case Menu:
		menuScreen.Draw(GameWindow);
		break;
	case Options:
		//optionsScreen.Update(GameWindow, GameState);
		break;
	case Playing:
		gameScreen.Draw();
		break;
	case Pause:
		break;
	case Exit:
		GameWindow.close();
		break;
	default:
		break;
	}

	GameWindow.draw(FpsText);
	GameWindow.draw(UpdatesText);

	GameWindow.display();
}

void Game::setDebugText() {
	if (!DebugFont.loadFromFile("Assets\\Fonts\\VCR_OSD_MONO.ttf")) {
		std::cerr << "Error Loading Font" << std::endl;
	}
	else {
		//TODO Funktion kleiner machen
		//Doppeltes ausführen von gleichen Befehlen
		FpsText.setFont(DebugFont);
		FpsText.setCharacterSize(DebugFontSize);
		FpsText.setFillColor(DebugTextColor);
		FpsText.setPosition(FpsTextPosition);

		UpdatesText.setFont(DebugFont);
		UpdatesText.setCharacterSize(DebugFontSize);
		UpdatesText.setFillColor(DebugTextColor);
		UpdatesText.setPosition(UpdatesTextPosition);
	}
}

void Game::setDebugTextPosition() {
	sf::Vector2f view_center = view.getCenter();
	float x = view_center.x - WINDOW_WIDTH / 2;
	float y = view_center.y - WINDOW_HEIGHT / 2;

	UpdatesText.setPosition(UpdatesTextPosition + sf::Vector2f(x, y));
	FpsText.setPosition(FpsTextPosition + sf::Vector2f(x, y));
}