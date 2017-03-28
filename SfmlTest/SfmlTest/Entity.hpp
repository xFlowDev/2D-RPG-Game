#pragma once

#include <string>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Enums.hpp"

class Entity {
public:
	Entity();
	~Entity();

	virtual void Update(sf::RenderWindow &, GameState &);
	virtual void Draw(sf::RenderWindow &);
protected:
	sf::Vector2f Size;
	sf::Vector2f Postition;

	std::string TexturePath;
	sf::Texture Texture;
	sf::Sprite Sprite;

	virtual void setTexture();
	virtual void setSprite();
private:

};