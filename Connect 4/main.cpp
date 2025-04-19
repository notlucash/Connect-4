#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Balls.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode({ 1200, 800}), "Connect Andy");

    const sf::Texture boardtex("boardimagesmall.jpg");
    sf::Sprite boardsprite(boardtex);

    // Create a circle shape to represent the ball
    sf::CircleShape ball(39.3); // Radius of 39.3 pixels
    ball.setFillColor(sf::Color::Green); // Set the color of the ball
    ball.setPosition({ 876.f, 637.f }); // Position the ball in the center of the window

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        // draws sprites in window
        window.draw(boardsprite);
        window.draw(ball);

        window.display();
    }
}