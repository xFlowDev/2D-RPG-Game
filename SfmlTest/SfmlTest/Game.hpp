#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <chrono>
#include <iostream>

#include "Enums.hpp"
#include "GameScreen.hpp"
#include "MenuScreen.hpp"

class Game {
public:
	Game();
	~Game();
	void GameLoop();
private:
	const int WIDTH = 800;
	const int HEIGHT = 600;
	sf::RenderWindow GameWindow;

	GameState GameState;

	std::chrono::high_resolution_clock::time_point Timer;

	std::chrono::high_resolution_clock::time_point currentTime;
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::duration deltaTime;

	float frameTime;
	float deltaTimeMs;
	float deltaTimeSaccumulator;
	int Updates;
	int FPS;

	sf::Text FpsText;
	sf::Text DeltaTimeText;
	sf::Text DebugMessage;

	void Update();
	void Draw();

	void drawGameStatistics();

	MenuScreen menuScreen;
	GameScreen gameScreen;

};