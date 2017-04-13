#include "Entity.hpp"

Entity::Entity() {
}
Entity::Entity(sf::Vector2f startingPosition) {
	Position = startingPosition;
}
Entity::~Entity() {
}

void Entity::Update(sf::RenderWindow &GameWindow, GameState &GameState) {
	//Leer da das nur die Super-Klasse ist
	Sprite.setPosition(Position);
}
void Entity::Draw(sf::RenderWindow &GameWindow) {
	//Leer da das nur die Super-Klasse ist
	GameWindow.draw(Sprite);
}

//Erstelle Sprite basierend auf Texture
//Braucht keinen Parameter da Texture in Variable vorhanden ist
void Entity::setSprite(std::string path) {
	//Wenn das Bild nicht geladen wird crashed das Programm
	//Dafür sollte ich mir vielleicht was anderes ausdenken
	//Error Handling und so
	if (!Texture.loadFromFile(path))
		std::cerr << "Error Loading File: " << path << std::endl;
	else
		Sprite.setTexture(Texture);
}

sf::Sprite Entity::getSprite() {
	return Sprite;
}

void Entity::setSize(sf::Vector2f size) {
	Size = size;
}

sf::Vector2f Entity::getSize() {
	return Size;
}

void Entity::setPosition(sf::Vector2f position) {
	Position = position;
	Sprite.setPosition(position);
}

sf::Vector2f Entity::getPosition() {
	return Position;
}

void Entity::setVelocity(float velocity) {
	Velocity = velocity;
}

float Entity::getVelocity() {
	return Velocity;
}

void Entity::setName(std::string name) {
	Name = name;
}

std::string Entity::getName() {
	return Name;
}

void Entity::setHealth(int health) {
	Health = health;
}

int Entity::getHealth() {
	return Health;
}
