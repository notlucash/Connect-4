#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Balls.hpp"
#include "Menu.hpp"

#define ROWS 6
#define COLS 7

int main()
{
    Menu game;

    game.DisplayMenu();


    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Connect Andy");

    int gameBoard[ROWS][COLS];
    int current_player = 1;

    const sf::Texture boardtex("boardimagesmall.jpg");
    sf::Sprite boardsprite(boardtex);

    // Create a circle shape to represent the ball

    Ball ball(39.3, { 875.f, 33.f }, sf::Color::Red);
    //Ball ball2(39.3, { 770.f, 538.f }, sf::Color::Red);
    //Ball ball3(39.3, { 665.f, 439.f }, sf::Color::Red);
    //Ball ball4(39.3, { 561.f, 340.f }, sf::Color::Red);
    //Ball ball5(39.3, { 456.f, 242.f }, sf::Color::Red);
    //Ball ball6(39.3, { 351.f, 143.f }, sf::Color::Red);
    //Ball ball7(39.3, { 246.f, 637.f }, sf::Color::Red);

    float velocity = 450.f;
    float targetY = 637.f; //position of bottom right spot in board

    sf::Clock clock;

    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            ball.chooseColumn(event, gameBoard, current_player);
        }

        //float time = clock.restart().asSeconds(); //convert this into the dropBall function for any ball. must also add loop that continues the function while it does not overtake 
        //

        //sf::Vector2f pos = ball.getPosition();

        //    if (pos.y < targetY)
        //{
        //    pos.y += velocity * time;
        //    if (pos.y > targetY)
        //    {
        //        pos.y = 637.f;
        //    }
        //    ball.setPosition({ pos.x, pos.y });
        //}



        window.clear();

        // draws sprites in window
        window.draw(boardsprite);
        window.draw(ball);
        /*     window.draw(ball2);
             window.draw(ball3);
             window.draw(ball4);
             window.draw(ball5);
             window.draw(ball6);
             window.draw(ball7);*/


        window.display();
    }
    return 0;
}


