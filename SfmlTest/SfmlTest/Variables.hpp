#pragma once
#ifndef VARIABLES_H
#define VARIABLES_H


#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <iostream>

#define WIDTH 1200
#define HEIGHT 900

#define TIME_POINT std::chrono::time_point<std::chrono::high_resolution_clock>
#define DURATION std::chrono::duration<double>

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