#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Enums.hpp"
#include "GameScreen.hpp"
#include "MenuScreen.hpp"

class Game {
public:
	Game();
	~Game();

private:
	const int WIDTH = 800;
	const int HEIGHT = 600;
	sf::RenderWindow GameWindow;

	GameState GameState;
	
	double FPS;
	double DeltaTime;
	double TimeStarted;

	void GameLoop();
	void Update();
	void Draw();

	MenuScreen menuScreen;
	GameScreen gameScreen;

};