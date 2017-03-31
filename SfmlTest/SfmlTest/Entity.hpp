#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Enums.hpp"

class Entity {
public:
	Entity();
	Entity(sf::Vector2f);
	~Entity();

	virtual void Update(sf::RenderWindow &, GameState &);
	virtual void Draw(sf::RenderWindow &);

	virtual void setSprite(std::string);
	virtual sf::Sprite getSprite();

	virtual void setSize(sf::Vector2f);
	virtual sf::Vector2f getSize();

	virtual void setPosition(sf::Vector2f);
	virtual sf::Vector2f getPosition();

	virtual void setVelocity(float);
	virtual float getVelocity();

	virtual void setName(std::string);
	virtual std::string getName();

	virtual void setHealth(int);
	virtual int getHealth();
protected:
	sf::Texture Texture;
	sf::Sprite Sprite;

	//TODO Wie kann ich die Entities kennzeichnen?
	//EntityType EntityType;

	sf::Vector2f Size;
	sf::Vector2f Postition;
	float Velocity;

	std::string Name;
	int Health;

private:

};