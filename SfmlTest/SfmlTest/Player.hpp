#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"

class Player : public Entity {
public:
	Player();
	~Player();

	void Update(sf::RenderWindow &, GameState &) override;
	void Draw(sf::RenderWindow &) override;
private:
	void Move();
};
#endif // !PLAYER_H