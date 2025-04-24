#include "Menu.hpp"

#include <Windows.h>;

Menu::Menu() {
	this->_option = 0;
	menuTex.loadFromFile("Menu.jpg");
}
Menu::~Menu() {

}

int Menu::DisplayMenu(sf::RenderWindow& window) {

	sf::Sprite menuSprite(menuTex);

	sf::RectangleShape Button1({ 400.f, 140.f });
	Button1.setPosition({ 400.f, 250.f });
	sf::RectangleShape Button2({ 400.f, 140.f });
	Button2.setPosition({ 400.f, 395.f });
	sf::RectangleShape Button3({ 400.f, 140.f });
	Button3.setPosition({ 400.f, 545.f });

	window.clear();

	window.draw(menuSprite);

	window.display();

	while (window.isOpen())
	{
		Sleep(200);
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) // if left mouse button is pressed
			{
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); // get mouse position

				// get position of buttons
				sf::FloatRect playButton = Button1.getGlobalBounds();
				sf::FloatRect rulesButton = Button2.getGlobalBounds();
				sf::FloatRect exitButton = Button3.getGlobalBounds();

				if (playButton.contains(mousePos))
				{
					return 1;
				}
				if (rulesButton.contains(mousePos))
				{
					return 2;
				}
				if (exitButton.contains(mousePos))
				{
					window.close();
					return 3;
				}
			}
		}
	}
}

int Menu::displayRules(sf::RenderWindow& window)
{
	const sf::Font font("JungleAdventurer.ttf");

	sf::Text title(font, "Rules");
	title.setCharacterSize(75);
	title.setStyle(sf::Text::Bold);
	title.setFillColor(sf::Color::White);

	sf::FloatRect textRect = title.getLocalBounds(); // get bounds of text to center
	title.setOrigin(textRect.getCenter()); // set origin to center
	title.setPosition({ 600.f, 200.f });

	sf::Text menu(font, "Return to Menu");
	menu.setCharacterSize(40);
	menu.setStyle(sf::Text::Bold);
	menu.setFillColor(sf::Color::White);
	textRect = menu.getLocalBounds();
	menu.setOrigin(textRect.getCenter());
	menu.setPosition({ 600.f, 700.f });

	sf::Text rules(font, "- Players take turns dropping one ball into a column\n- The goal is to get four in a row - vertically, horizontally, or diagonally\n- If the board fills up with no winner, it's a draw\n\n\n\n\n- Use arrow keys to move ball\n- Use down arrow, space, or enter to drop");
	rules.setCharacterSize(30);
	rules.setStyle(sf::Text::Bold);
	rules.setFillColor(sf::Color::White);
	textRect = rules.getLocalBounds();
	rules.setOrigin(textRect.getCenter());
	rules.setPosition({ 600.f, 450.f });

	window.clear();

	window.draw(title);
    window.draw(menu);
	window.draw(rules);

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

				sf::FloatRect menuButton = menu.getGlobalBounds(); // get position of text


				if (menuButton.contains(mousePos))
				{
					return 0;
				}
			}
		}
	}
}

// networking was hard

//int Menu::OnlineMenu(sf::RenderWindow& window)
//{
//	const sf::Font font("JungleAdventurer.ttf");
//
//	sf::Text title(font, "Online");
//	title.setCharacterSize(75);
//	title.setStyle(sf::Text::Bold);
//	title.setFillColor(sf::Color::Black);
//	title.setPosition({ 505.f, 200.f });
//
//	sf::Text join(font, "Join");
//	join.setCharacterSize(40);
//	join.setStyle(sf::Text::Bold);
//	join.setFillColor(sf::Color::Black);
//	join.setPosition({ 575.f, 325.f });
//
//	sf::Text host(font, "Host");
//	host.setCharacterSize(40);
//	host.setStyle(sf::Text::Bold);
//	host.setFillColor(sf::Color::Black);
//	host.setPosition({ 570.f, 400.f });
//
//	sf::Text menu(font, "Return to Menu");
//	menu.setCharacterSize(40);
//	menu.setStyle(sf::Text::Bold);
//	menu.setFillColor(sf::Color::Black);
//	menu.setPosition({ 480.f, 700.f });
//
//	window.clear(sf::Color(239, 223, 213));
//
//	window.draw(title);
//	window.draw(join);
//	window.draw(host);
//	window.draw(menu);
//
//	window.display();
//
//	int i = 0;
//
//	while (window.isOpen())
//	{
//		while (const std::optional event = window.pollEvent())
//		{
//			if (event->is<sf::Event::Closed>())
//				window.close();
//
//			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) // if left mouse button is pressed
//			{
//				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); // get mouse position
//
//				// get position of buttons
//				sf::FloatRect joinButton = join.getGlobalBounds();
//				sf::FloatRect hostButton = host.getGlobalBounds();
//				sf::FloatRect menuButton = menu.getGlobalBounds();
//
//				if (joinButton.contains(mousePos))
//				{
//					sf::TcpSocket      socket;
//					sf::Socket::Status status = socket.connect(sf::IpAddress::getPublicAddress().value(), 53000);
//				}
//
//				if (hostButton.contains(mousePos))
//				{
//					sf::TcpListener listener;
//					if (listener.listen(53000) != sf::Socket::Status::Done)
//					{
//					}
//					sf::TcpSocket client;
//					if (listener.accept(client) != sf::Socket::Status::Done)
//					{
//					}
//				}
//				if (menuButton.contains(mousePos))
//				{
//					return 3;
//				}
//			}
//		}
//	}
//}