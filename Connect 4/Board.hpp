
#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Balls.hpp"

class Board {
public:
	Board(); //constructor
	~Board(); //destructor
	void dropBallG(sf::CircleShape ball, float velocity, float targetY, sf::Clock clock);



private:

};
