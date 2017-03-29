#pragma once
#include "Entity.hpp"

class Player : Entity {
public:
	Player();
	~Player();

	void Update(sf::RenderWindow &, GameState &) override;
	void Draw(sf::RenderWindow &) override;
private:
};

