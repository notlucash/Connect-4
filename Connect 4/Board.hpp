#pragma once

#include <iostream>
#include <fstream>
#include <time.h>
#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
public:
	Paddle(const sf::Vector2f& size, const sf::Vector2f& pos, const sf::Color& color) :
		sf::RectangleShape(size)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}

private:
};