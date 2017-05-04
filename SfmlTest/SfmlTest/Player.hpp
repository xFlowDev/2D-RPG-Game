#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"

class Player : public Entity {
public:
	Player();
	~Player();

	void Draw(sf::RenderWindow &) override;

	//float &, float &, float &, float &
	void Move(sf::Vector2f &);
private:
	sf::Vector2f view_boundries_bottom_right;
	sf::Vector2f view_boundries_top_left;
};
#endif // !PLAYER_H