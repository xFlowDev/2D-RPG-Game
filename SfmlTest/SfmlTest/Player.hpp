#pragma once
#include "Entity.hpp"

class Player : public Entity {
public:
	Player();
	Player(sf::Vector2f);
	~Player();

	void Update(sf::RenderWindow &, GameState &) override;
	void Draw(sf::RenderWindow &) override;
private:
};

