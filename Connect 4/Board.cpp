Board.cpp


#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"


Board::Board()
{
}

Board::~Board()
{
}

void Board::dropBallG(sf::CircleShape ball, float velocity, float targetY, sf::Clock clock)
{

    float time = clock.restart().asSeconds();

    sf::Vector2f pos = ball.getPosition();

    if (pos.y < targetY)
    {
        float newY = pos.y + velocity * time;
        if (newY > targetY)
        {
            newY = 637.f;
        }
        ball.setPosition({ pos.x, newY });
    }
}
