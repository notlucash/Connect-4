#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Balls.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode({ 2400, 1600}), "Connect 4");

    const sf::Texture texture("boardimage.jpg");
    sf::Sprite sprite(texture);

    // Create a circle shape to represent the ball
    sf::CircleShape ball(78); // Radius of 80 pixels
    ball.setFillColor(sf::Color::Green); // Set the color of the ball
    ball.setPosition({ 703.f, 1077.f }); // Position the ball in the center of the window

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        window.draw(sprite);
        window.draw(ball);

        window.display();
    }
}