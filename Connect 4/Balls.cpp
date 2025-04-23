#include "Balls.hpp"
#include <SFML/Graphics.hpp>
#include <algorithm>


void Ball::dropBall(float targetY) 
{
    if (!isDrop) {
        this->targetLevel = targetY;
        this->isDrop = true;
    }
}

void Ball::updateBall(float time)
{
    if (!isDrop) 
    {
        return;
    }

    dropSpeed = 600.f;
    sf::Vector2f pos = this->getPosition();

    if (pos.y < targetLevel)
    {
        float Y = dropSpeed * time;
        float newY = pos.y + Y;

        if (newY >= targetLevel) {
            newY = targetLevel;
        }

        this->setPosition({ pos.x, newY });
    }
    else
    {
        this->setPosition({ pos.x, targetLevel });
        isDrop = false;
    }
}
