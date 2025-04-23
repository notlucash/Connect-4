#include "Menu.hpp"
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>

Menu::Menu() {
	this->_option = 0;
}
Menu::~Menu() {

}

int Menu::DisplayMenu() {
	sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Connect Andy");

	// Open a font
	const sf::Font font("JungleAdventurer.ttf");

	// Create a text
	sf::Text title1(font, "Connect");
	title1.setCharacterSize(75);
	title1.setStyle(sf::Text::Bold);
	title1.setFillColor(sf::Color::Red);
	title1.setPosition({ 380.f, 200.f }); // Set to somewhere visible

	sf::Text title2(font, "Andy");
	title2.setCharacterSize(75);
	title2.setStyle(sf::Text::Bold);
	title2.setFillColor(sf::Color::Yellow);
	title2.setPosition({ 660.f, 200.f }); // Set to somewhere visible

	sf::Text local(font, "Local Match");
	local.setCharacterSize(40);
	local.setStyle(sf::Text::Bold);
	local.setFillColor(sf::Color::Black);
	local.setPosition({ 490.f, 325.f }); // Set to somewhere visible

	sf::Text online(font, "Online Match");
	online.setCharacterSize(40);
	online.setStyle(sf::Text::Bold);
	online.setFillColor(sf::Color::Black);
	online.setPosition({ 483.f, 400.f }); // Set to somewhere visible

	window.clear(sf::Color(239, 223, 213));

	// Draw it
	window.draw(title1);
	window.draw(title2);
	window.draw(local);
	window.draw(online);

	// Display it
	window.display();


	while (window.isOpen())
	{

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();


			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

				sf::FloatRect localButton = local.getGlobalBounds();
				sf::FloatRect onlineButton = online.getGlobalBounds();

				if (localButton.contains(mousePos))
				{
					window.clear(sf::Color(239, 223, 213));
					return 1;
				}

				if (onlineButton.contains(mousePos))
				{
					window.clear(sf::Color(239, 223, 213));
					return 2;
				}
			}
		}

	}
}