#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#define WIDTH 1200
#define HEIGHT 900

#define TIME_POINT std::chrono::time_point<std::chrono::high_resolution_clock>
#define DURATION std::chrono::duration<double>

#define GRAS sf::Color(0, 145, 2)
#define RAND sf::Color(145, 90, 42)
#define WASSER sf::Color(33, 70, 255)

enum GameState {
	Menu,
	Options,
	Playing,
	Pause,
	Exit
};

//enum EntityType {
//	Player,
//	Enemy,
//	NPC
//};
#endif // !VARIABLES_H