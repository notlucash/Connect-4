#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <SFML/Graphics.hpp>

#define ROWS 6
#define COLS 7

class Board;

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

	void dropBall(Board &gameBoard, float targetY, int current_player);
	void chooseColumn(Board &gameBoard, int current_player);
	void updateBall(float time);
private:
	float radius;
	sf::Vector2f position;
	sf::Color color;
	int selected_column;
	float targetLevel = 0.1f;
	bool isDrop = false;
};
