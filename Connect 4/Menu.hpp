#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


class Menu {
public:
	Menu();
	~Menu();
	int DisplayMenu(); // returns option selected by user


private:
	int _option;
};