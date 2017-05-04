#include "Player.hpp"

Player::Player() {
	Velocity = 5.f;
}

Player::~Player() {

}

void Player::Draw(sf::RenderWindow &GameWindow) {
	GameWindow.draw(Sprite);
}

void Player::Move(sf::Vector2f &map_size) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && Position.y > 0)
		setPosition(sf::Vector2f(Position.x, Position.y - Velocity));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && Position.y <= map_size.y * TILE_SIZE - Size.y)
		setPosition(sf::Vector2f(Position.x, Position.y + Velocity));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && Position.x >= 0)
		setPosition(sf::Vector2f(Position.x - Velocity, Position.y));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && Position.x <= map_size.x * TILE_SIZE - Size.x)
		setPosition(sf::Vector2f(Position.x + Velocity, Position.y));
}