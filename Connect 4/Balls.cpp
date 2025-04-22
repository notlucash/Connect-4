#pragma once
#include "Balls.hpp"
#include <SFML/Graphics.hpp>

#define COLS 7
#define ROWS 6

Ball::~Ball()
{
}

void Ball::dropBall(int gameBoard[ROWS][COLS], float targetY, int current_player)
{
    sf::Clock clock;
    float time = clock.restart().asSeconds();
    float velocity = 400.f;
    sf::Vector2f pos = this->getPosition();

    if (pos.y < targetY)
    {
        float newY = pos.y + velocity * time;
        if (newY > targetY)
        {
            newY = targetY;
        }
        this->setPosition({ pos.x, newY });
    }
}

void Ball::chooseColumn(sf::Event event, int gameBoard[ROWS][COLS], int current_player)
{
    if (auto* keyEvent = event.getIf<sf::Event::KeyPressed>())
    {
        while (keyEvent->code != sf::Keyboard::Key::Down)
        {
            if (keyEvent->code == sf::Keyboard::Key::Left)
            {
                selected_column = std::max(0, selected_column - 1);
            }
            else if (keyEvent->code == sf::Keyboard::Key::Right)
            {
                selected_column = std::min(ROWS, selected_column + 1);
            }
        }
        if (keyEvent->code == sf::Keyboard::Key::Down)
        {
            dropBall(gameBoard, selected_column, current_player);
        }

        this->setPosition({ selected_column * 39.3, 33.f });

    }
}
