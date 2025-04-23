#include "Menu.hpp"

Menu::Menu() {
	this->_option = 0;
}
Menu::~Menu() {

}

int Menu::DisplayMenu(sf::RenderWindow& window) {
	//sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Connect Andy");

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
	title2.setPosition({ 660.f, 200.f });

	sf::Text local(font, "Local Match");
	local.setCharacterSize(40);
	local.setStyle(sf::Text::Bold);
	local.setFillColor(sf::Color::Black);
	local.setPosition({ 490.f, 325.f });

	sf::Text online(font, "Online Match");
	online.setCharacterSize(40);
	online.setStyle(sf::Text::Bold);
	online.setFillColor(sf::Color::Black);
	online.setPosition({ 483.f, 400.f });

	window.clear(sf::Color(239, 223, 213)); // set background color to match board background color

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


			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) // if left mouse button is pressed
			{
				sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window)); // get mouse position

				// get position of buttons
				sf::FloatRect localButton = local.getGlobalBounds();
				sf::FloatRect onlineButton = online.getGlobalBounds();

				// if mouse is in local button area
				if (localButton.contains(mousePos))
				{
					return 1;
				}

				// if mouse is in online button area
				if (onlineButton.contains(mousePos))
				{
					return 2;
				}
			}
		}
	}
}

int Menu::OnlineMenu(sf::RenderWindow& window)
{
	const sf::Font font("JungleAdventurer.ttf");

	sf::Text title(font, "Online");
	title.setCharacterSize(75);
	title.setStyle(sf::Text::Bold);
	title.setFillColor(sf::Color::Black);
	title.setPosition({ 505.f, 200.f });

	sf::Text join(font, "Join");
	join.setCharacterSize(40);
	join.setStyle(sf::Text::Bold);
	join.setFillColor(sf::Color::Black);
	join.setPosition({ 575.f, 325.f });

	sf::Text host(font, "Host");
	host.setCharacterSize(40);
	host.setStyle(sf::Text::Bold);
	host.setFillColor(sf::Color::Black);
	host.setPosition({ 570.f, 400.f });

	sf::Text menu(font, "Return to Menu");
	menu.setCharacterSize(40);
	menu.setStyle(sf::Text::Bold);
	menu.setFillColor(sf::Color::Black);
	menu.setPosition({ 480.f, 700.f });

	window.clear(sf::Color(239, 223, 213));

	window.draw(title);
	window.draw(join);
	window.draw(host);
	window.draw(menu);

	window.display();

	int i = 0;

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
				sf::FloatRect joinButton = join.getGlobalBounds();
				sf::FloatRect hostButton = host.getGlobalBounds();
				sf::FloatRect menuButton = menu.getGlobalBounds();

				if (joinButton.contains(mousePos))
				{
					sf::TcpSocket      socket;
					sf::Socket::Status status = socket.connect({ 192, 168, 0, 5 }, 53000);
				}

				if (hostButton.contains(mousePos))
				{
					sf::TcpListener listener;
					if (listener.listen(53000) != sf::Socket::Status::Done)
					{
					}
					sf::TcpSocket client;
					if (listener.accept(client) != sf::Socket::Status::Done)
					{
					}
				}
				if (menuButton.contains(mousePos))
				{
					return 3;
				}
			}
		}
	}
}
