#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <time.h>

#define ROWS 6
#define COLS 7

// inherits the circle shape
class Ball : public sf::CircleShape { // referenced from Andys class code with the pong ball logic
public:
    // Constructor
    Ball(const float& rad, const sf::Vector2f& pos, const sf::Color& color)
        : sf::CircleShape(rad), isDrop(false), targetLevel(pos.y)
    {
        this->setFillColor(color);
        this->setOrigin({ rad, rad });
        this->setPosition(pos);
    }


    bool isDrop;

    void dropBall(float targetY);
    void updateBall(float time);
private:
    //members
    float dropSpeed;
    float targetLevel;
};
