#include "Player.hpp"
#include <iostream>

Player::Player() {
	Velocity = 5.f;

}

Player::Player(sf::Vector2f startingPosition) {
	Position = startingPosition;	
}

Player::~Player() {

}

void Player::Update(sf::RenderWindow &GameWindow, GameState &GameState) {
	if (Position.x > 0 && Position.x < 800 &&
		Position.y > 0 && Position.y < 600)
		Move();
	
}

void Player::Draw(sf::RenderWindow &GameWindow) {
	GameWindow.draw(Sprite);
}

void Player::Move() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		setPosition(sf::Vector2f(Position.x, Position.y - Velocity));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		setPosition(sf::Vector2f(Position.x, Position.y + Velocity));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		setPosition(sf::Vector2f(Position.x - Velocity, Position.y));
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		setPosition(sf::Vector2f(Position.x + Velocity, Position.y));
}