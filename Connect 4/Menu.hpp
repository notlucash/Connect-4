#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>


class Menu {
public:
	Menu();
	~Menu();
	int DisplayMenu(sf::RenderWindow& window); // returns option selected by user
	int displayRules(sf::RenderWindow& window);
	//int OnlineMenu(sf::RenderWindow& window);

private:
	int _option;
	sf::Texture menuTex;
};