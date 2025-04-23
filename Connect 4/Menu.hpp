#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class Menu {
public:
	Menu();
	~Menu();
	int DisplayMenu(sf::RenderWindow& window); // returns option selected by user
	int OnlineMenu(sf::RenderWindow& window);

private:
	int _option;

};