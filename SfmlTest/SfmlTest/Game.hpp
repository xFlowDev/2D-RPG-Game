#pragma once
#ifndef GAME_H
#define GAME_H

#include <chrono>
#include <iostream>

#include "Variables.hpp"
#include "GameScreen.hpp"
#include "MenuScreen.hpp"

class Game {
public:
	Game();
	~Game();
	void GameLoop();
private:
	sf::RenderWindow GameWindow;

	GameState GameState;
	MenuScreen menuScreen;
	GameScreen gameScreen;

	//timer: F�r das Messen der Zeit vom ersten Starten des GameLoops
	//currentTime: enth�llt immer die Zeit zu der die Updates gemessen werden
	//newTime: immer der Zeitpunkt am Anfang des GameLoop
	//now: F�r das Abmessen einer Sekunde um die Updates/s und FPS zu messen
	TIME_POINT timer, currentTime, newTime, now;
	//frameTime: Die Zeit die ein Frame/Update ben�tigt
	//diff: Zum Abmessen einer Sekunde, wenn diff gr��er als 1s ist dann wird die Anzahl der UPS und FPS ausgegeben
	DURATION frameTime, diff;
	double dt, accumulator;
	int Updates, FPS;

	const int DebugFontSize = 18;
	sf::Color DebugTextColor = sf::Color::White;
	sf::Font DebugFont;
	sf::Vector2f FpsTextPosition = sf::Vector2f(0.f, 0.f);
	sf::Text FpsText;
	sf::Vector2f UpdatesTextPosition = sf::Vector2f(0.f, DebugFontSize + 6.f);
	sf::Text UpdatesText;


	void Update();
	void Draw();

	void setDebugText();


};
#endif // !GAME_H