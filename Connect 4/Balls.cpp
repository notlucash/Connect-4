#pragma once
#include "Balls.hpp"
#include <SFML/Graphics.hpp>
#include "Board.hpp"

#define COLS 7
#define ROWS 6

Ball::~Ball()
{
}

void Ball::dropBall(Board &gameBoard, float targetY, int current_player)
{
    this->targetLevel = targetY;
    this->isDrop = true;
}

void Ball::chooseColumn(Board &gameBoard, int current_player)
{
    if (!isDrop)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            selected_column = std::max(0, this->selected_column - 1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            selected_column = std::min(COLS - 1, this->selected_column + 1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        {
            int row = gameBoard.getFirstRow(selected_column);

            if (row != -1)
            {
                float targetY = 143.f;
                float rowH = 105.f;
                float dropY = targetY + row * rowH - 33.f;
                dropBall(gameBoard, dropY, current_player);
                gameBoard.updateBoard(row, selected_column, current_player);
            }

        }

        const float colWidth = 105.f;
        const float offset = 246.f;
        float x = offset + this->selected_column * colWidth;

        this->setPosition({ x, this->getPosition().y });

    }
    
}

void Ball::updateBall(float time)
{
    if (!isDrop)
    {
        return;
    }
    float velocity = 400.f;
    sf::Vector2f pos = this->getPosition();

    if (pos.y < targetLevel)
    {
        float newY = pos.y + velocity * time;
        if (newY > targetLevel)
        {

            newY = targetLevel;


        }
        this->setPosition({ pos.x, newY });
    }
}


