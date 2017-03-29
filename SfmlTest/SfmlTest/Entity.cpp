#include "Entity.hpp"



Entity::Entity() {
}
Entity::~Entity() {
}

void Entity::Update(sf::RenderWindow &GameWindow, GameState &GameState) {
	//Leer da das nur die Super-Klasse ist
}
void Entity::Draw(sf::RenderWindow &GameWindow) {
	//Leer da das nur die Super-Klasse ist
}

//Erstelle Sprite basierend auf Texture
//Braucht keinen Parameter da Texture in Variable vorhanden ist
void Entity::setSprite(std::string path) {
	if (!Texture.loadFromFile(path))
	{
		//Error Handling hier einbauen
	}
	else
	{
		Sprite.setTexture(Texture);
	}
}

void Entity::setSize(sf::Vector2f size) {
	Size = size;
}

sf::Vector2f Entity::getSize() {
	return Size;
}

void Entity::setPosition(sf::Vector2f position) {
	Postition = position;
}

sf::Vector2f Entity::getPosition() {
	return Postition;
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
