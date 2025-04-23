#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <SFML/Graphics.hpp>

#define ROWS 6
#define COLS 7

// inherits the CircleShape
class Ball : public sf::CircleShape {
public:
	//constructor
	Ball(const float& rad, const sf::Vector2f& pos,
		const sf::Color& color) : sf::CircleShape(rad)
	{
		this->setFillColor(color);
		this->setPosition(pos);
	}
	~Ball();

	void dropBall(int gameBoard[ROWS][COLS], float targetY, int current_player);
	void chooseColumn(int gameBoard[ROWS][COLS], int current_player);
private:
	float radius;
	sf::Vector2f position;
	sf::Color color;
	int selected_column;
};
