#include "Player.hpp"

Player::Player() {

}

Player::Player(sf::Vector2f startingPosition) {
	Postition = startingPosition;
}

Player::~Player() {

}

void Player::Update(sf::RenderWindow &GameWindow, GameState &GameState) {

}

void Player::Draw(sf::RenderWindow &GameWindow) {
	GameWindow.draw(Sprite);
}