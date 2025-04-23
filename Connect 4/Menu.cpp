#include "Menu.hpp"

Menu::Menu() {
	this->_option = 0;
}
Menu::~Menu() {

}

int Menu::DisplayMenu(sf::RenderWindow& window) {

	const sf::Texture menuTex("Menu.jpg");
	sf::Sprite menuSprite(menuTex);

	sf::RectangleShape Button1({ 400.f, 140.f });
	Button1.setPosition({ 400.f, 250.f });
	sf::RectangleShape Button2({ 400.f, 140.f });
	Button2.setPosition({ 400.f, 395.f });
	sf::RectangleShape Button3({ 400.f, 140.f });
	Button3.setPosition({ 400.f, 545.f });

	window.draw(menuSprite);

	window.display();

	while (window.isOpen())
	{

		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();


			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) // if left mouse button is pressed
			{
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); // get mouse position

				// get position of buttons
				sf::FloatRect playButton = Button1.getGlobalBounds();
				sf::FloatRect helpButton = Button2.getGlobalBounds();
				sf::FloatRect exitButton = Button3.getGlobalBounds();

				 // if mouse is in local button area
				if (playButton.contains(mousePos))
				{
					return 1;
				}
				if (helpButton.contains(mousePos))
				{
					return 2;
				}
				// if mouse is in online button area
				if (exitButton.contains(mousePos))
				{
					window.close();
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