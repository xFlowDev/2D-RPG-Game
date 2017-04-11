#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <chrono>
#include <iostream>

#include "Enums.hpp"
#include "GameScreen.hpp"
#include "MenuScreen.hpp"

#define TIME_POINT std::chrono::time_point<std::chrono::high_resolution_clock>
#define DURATION std::chrono::duration<double>

class Game {
public:
	Game();
	~Game();
	void GameLoop();
private:
	const int WIDTH = 1200;
	const int HEIGHT = 900;
	sf::RenderWindow GameWindow;
	
	GameState GameState;
	MenuScreen menuScreen = MenuScreen(WIDTH, HEIGHT);
	GameScreen gameScreen = GameScreen(WIDTH, HEIGHT);

	//timer: Für das Messen der Zeit vom ersten Starten des GameLoops
	//currentTime: enthällt immer die Zeit zu der die Updates gemessen werden
	//newTime: immer der Zeitpunkt am Anfang des GameLoop
	//now: Für das Abmessen einer Sekunde um die Updates/s und FPS zu messen
	TIME_POINT timer, currentTime, newTime, now;
	//frameTime: Die Zeit die ein Frame/Update benötigt
	//diff: Zum Abmessen einer Sekunde, wenn diff größer als 1s ist dann wird die Anzahl der UPS und FPS ausgegeben
	DURATION frameTime, diff;
	double dt, accumulator;
	int Updates, FPS;

	const int DebugFontSize = 18;
	sf::Color DebugTextColor = sf::Color::White;
	sf::Font DebugFont;
	sf::Vector2f FpsTextPosition = sf::Vector2f(0,0);
	sf::Text FpsText;
	sf::Vector2f UpdatesTextPosition = sf::Vector2f(0, DebugFontSize + 6);
	sf::Text UpdatesText;

	
	void Update();
	void Draw();

	void setDebugText();


};