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
	const sf::Font font("arial.ttf");

	// Create a text
	sf::Text text(font, "hello");
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);

	// Draw it
	window.draw(text);
}