#include <iostream>
#include <fstream>
#include <time.h>
#include <SFML/Graphics.hpp>


// inherits the CircleShape
class Ball : public sf::CircleShape {
public:
	//constructor
	Ball (const float& rad, const sf::Vector2f& pos, 
		const sf::Color& color) : sf::CircleShape(rad)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}
};