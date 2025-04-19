#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Balls.hpp"

int main() {

    sf::RenderWindow window(sf::VideoMode({ 2400, 1600}), "Connect 4");

    const sf::Texture texture("boardimage.jpg");
    sf::Sprite sprite(texture);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        window.draw(sprite);

        window.display();
    }

    //sf::RenderWindow window(sf::VideoMode({ 1500, 1500 }), "SFML works!");
    //sf::CircleShape shape(400.f);
    //shape.setFillColor(sf::Color::Green);
    //Paddle p1Paddle(sf::Vector2f(100, 400), sf::Vector2f(0.0, 0.0),
    //    sf::Color::Magenta),
    //    p2Paddle(sf::Vector2f(window.getSize().x / 20, window.getSize().y / 5),
    //        sf::Vector2f(window.getSize().x - window.getSize().x / 20, 0),
    //        sf::Color::Cyan);
    //Ball gameBall(p1Paddle.getSize().x / 2,
    //    sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2),
    //    sf::Color::Yellow);

    //int direction = 1;

    //// shape.

    //while (window.isOpen())
    //{
    //    while (const std::optional event = window.pollEvent())
    //    {
    //        if (event->is<sf::Event::Closed>())
    //            window.close();

    //        //if 
    //    }

    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    //    {
    //        p1Paddle.move({ 0, 0.5 });
    //    }

    //    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
    //    {
    //        p2Paddle.move({ 0, 0.5});
    //    }

    //    if (p2Paddle.getGlobalBounds().findIntersection(gameBall.getGlobalBounds()))
    //    {
    //        direction *= -1;
    //    }

    //    gameBall.move(sf::Vector2f(0.01 * direction, 0));

    //    window.clear();
    //    window.draw(p1Paddle);
    //    window.draw(p2Paddle);
    //    window.draw(gameBall);
    //    window.display();
    //}
}