#pragma once
#include "Board.hpp"
#include "Balls.hpp"
#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <optional>
#include <iostream>

#define ROWS 6
#define COLS 7

// constructor
Board::Board()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            gameBoard[i][j] = 0;
        }
    }
}

//destructor
Board::~Board()
{
}


void Board::updateBoard(int row, int col, int player)
{
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        gameBoard[row][col] = player;
    }
}


int Board::getFirstEmptyRow(int col)
{
    if (col < 0 || col >= COLS)
    {
        return -1;
    }
    for (int row = ROWS - 1; row >= 0; row--)
    {
        if (gameBoard[row][col] == 0) return row;
    }
    return -1;
}


bool Board::isColumnFull(int col)
{
    if (col < 0 || col >= COLS)
    {
        return true;
    }
    return gameBoard[0][col] != 0;
}


void Board::clearBoard()
{
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            gameBoard[i][j] = 0;
        }
    }
}

bool Board::checkLine(int player, int r1, int c1, int dr, int dc)
{
    for (int i = 0; i < 4; i++)
    {
        int r = r1 + i * dr;
        int c = c1 + i * dc;

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || gameBoard[r][c] != player)
        {
            return false;
        }
    }
    return true;
}

// win checker
bool Board::checkWin(int player)
{
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c <= COLS - 4; c++)
        {
            if (checkLine(player, r, c, 0, 1))
            {
                return true;
            }
        }
    }
    for (int r = 0; r <= ROWS - 4; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            if (checkLine(player, r, c, 1, 0))
            {
                return true;
            }
        }
    }
    for (int r = 3; r < ROWS; r++)
    {
        for (int c = 0; c <= COLS - 4; c++)
        {
            if (checkLine(player, r, c, -1, 1))
            {
                return true;
            }
        }
    }
    for (int r = 0; r <= ROWS - 4; r++)
    {
        for (int c = 0; c <= COLS - 4; c++)
        {
            if (checkLine(player, r, c, 1, 1))
            {
                return true;
            }
        }
    }

    return false;
}



void Board::runGame()
{
    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "Connect Andy", sf::Style::Default);
    window.setFramerateLimit(60);

    Menu gameMenu;
    int menuOption = 0;

    do
    {
        while (menuOption != 1)
        {
            menuOption = gameMenu.DisplayMenu(window);
            if (menuOption == 2)
            {
                menuOption = gameMenu.displayRules(window);
            }
            if (menuOption == 3)
            {
                break;
            }
        }

        int current_player = 1;
        int selected_column = COLS / 2;
        bool pieceDropping = false;
        bool gameOver = false;
        int winner = 0;
        clearBoard();

        sf::Texture boardTexture;
        if (!boardTexture.loadFromFile("boardimagesmall.jpg"))
        {
            std::cout << "Error loading board texture!" << std::endl;
            return;
        }
        sf::Sprite boardSprite(boardTexture);

        sf::Texture transparentTex;
        if (!transparentTex.loadFromFile("board.png"))
        {
            std::cout << "Error loading board texture!" << std::endl;
            return;
        }
        sf::Sprite transparentSprite(transparentTex);

        sf::Font font;
        if (!font.openFromFile("JungleAdventurer.ttf"))
        {
            std::cerr << "Error loading font: JungleAdventurer.ttf" << std::endl;

            if (!font.openFromFile("arial.ttf"))
            {
                std::cout << "Error loading fallback font: arial.ttf" << std::endl;
                return;
            }
        }

        sf::Text winText(font, "");
        winText.setCharacterSize(60);
        winText.setStyle(sf::Text::Bold);

        std::vector<Ball> placedBalls;
        placedBalls.reserve(ROWS * COLS);
        Ball previewBall(39.3f, { 285.f + selected_column * 105.f, 21.f }, sf::Color::Red);

        sf::Clock clock;

        while (window.isOpen())
        {
            float deltaTime = clock.restart().asSeconds();

            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }

                if (!pieceDropping && !gameOver)
                {
                    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                    {
                        if (keyPressed->code == sf::Keyboard::Key::Left)
                        {
                            selected_column = std::max(0, selected_column - 1);
                        }
                        else if (keyPressed->code == sf::Keyboard::Key::Right)
                        {
                            selected_column = std::min(COLS - 1, selected_column + 1);
                        }
                        else if (keyPressed->code == sf::Keyboard::Key::Down ||
                            keyPressed->code == sf::Keyboard::Key::Enter ||
                            keyPressed->code == sf::Keyboard::Key::Space)
                        {

                            if (!isColumnFull(selected_column))
                            {
                                int row = getFirstEmptyRow(selected_column);
                                updateBoard(row, selected_column, current_player);

                                float targetX = 285.f + selected_column * 105.f;
                                float targetY = 181.5 + row * 99;
                                sf::Color currentPlayerColor;

                                if (current_player == 1)
                                {
                                    currentPlayerColor = sf::Color::Red;
                                }
                                else
                                {
                                    currentPlayerColor = sf::Color::Yellow;
                                }


                                placedBalls.emplace_back(39.6f, sf::Vector2f{ targetX, 21.f }, currentPlayerColor);
                                placedBalls.back().dropBall(targetY);
                                pieceDropping = true;

                                if (checkWin(current_player))
                                {
                                    gameOver = true;
                                    winner = current_player;
                                }
                                else
                                {
                                    bool boardFull = true;
                                    for (int c = 0; c < COLS; c++)
                                    {
                                        if (!isColumnFull(c))
                                        {
                                            boardFull = false;
                                            break;
                                        }
                                    }
                                    if (boardFull)
                                    {
                                        gameOver = true;
                                        winner = 3;
                                    }
                                }

                                if (!gameOver)
                                {
                                    if (current_player == 1)
                                    {
                                        previewBall.setFillColor(sf::Color::Yellow);
                                        current_player = 2;
                                    }
                                    else
                                    {
                                        previewBall.setFillColor(sf::Color::Red);
                                        current_player = 1;
                                    }
                                }

                            }
                            else
                            {
                                std::cout << "Column " << selected_column << " is full!" << std::endl;
                            }
                        }
                    }
                }
            }


            if (!gameOver)
            {
                previewBall.setPosition({ 285.f + selected_column * 105.f, 21.f });
            }
            bool stillDropping = false;
            for (Ball& ball : placedBalls)
            {
                ball.updateBall(deltaTime);
                if (ball.isDrop)
                {
                    stillDropping = true;
                }
            }
            if (pieceDropping && !stillDropping)
            {
                pieceDropping = false;
            }

            window.clear(sf::Color(239, 223, 213));
            window.draw(boardSprite);
            for (const Ball& ball : placedBalls)
            {
                window.draw(ball);
            }
            if (!gameOver)
            {
                window.draw(previewBall);
            }
            window.draw(transparentSprite);
            if (gameOver)
            {
                // Set text based on winner
                if (winner == 1)
                {
                    winText.setString("Player 1 (Red) Wins!");
                    winText.setFillColor(sf::Color::Red);
                }
                else if (winner == 2)
                {
                    winText.setString("Player 2 (Yellow) Wins!");
                    winText.setFillColor(sf::Color::Yellow);
                }
                else if (winner == 3)
                {
                    winText.setString("It's a Draw!");
                    winText.setFillColor(sf::Color::Black);
                }
                // put win text in the center
                sf::FloatRect textRect = winText.getLocalBounds();
                winText.setOrigin(textRect.getCenter());
                winText.setPosition({ 600.f, 50.f });

                sf::RectangleShape playAgain({ 400.f, 130.f });
                playAgain.setOrigin(playAgain.getGeometricCenter());
                playAgain.setFillColor(sf::Color(100, 100, 100));
                playAgain.setPosition({ 600.f, 300.f });

                sf::Text play(font, "Play Again");
                play.setCharacterSize(50);
                play.setStyle(sf::Text::Bold);
                play.setFillColor(sf::Color::Black);
                textRect = play.getLocalBounds();
                play.setOrigin(textRect.getCenter());
                play.setPosition({ 600.f, 300.f });


                sf::RectangleShape endMenu({ 400.f, 130.f });
                endMenu.setOrigin(endMenu.getGeometricCenter());
                endMenu.setFillColor(sf::Color(100, 100, 100));
                endMenu.setPosition({ 600.f, 500.f });

                sf::Text menu(font, "Return to Menu");
                menu.setCharacterSize(50);
                menu.setStyle(sf::Text::Bold);
                menu.setFillColor(sf::Color::Black);
                textRect = menu.getLocalBounds();
                menu.setOrigin(textRect.getCenter());
                menu.setPosition({ 600.f, 500.f });

                window.draw(winText);
                window.draw(playAgain);
                window.draw(endMenu);
                window.draw(play);
                window.draw(menu);

                sf::FloatRect playButton = playAgain.getGlobalBounds();
                sf::FloatRect menuButton = endMenu.getGlobalBounds();

                sf::Clock menuCooldown;

                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                    if (playButton.contains(mousePos))
                    {
                        menuOption = 1;
                        break;
                    }
                    if (menuButton.contains(mousePos))
                    {
                        menuOption = 0;
                        break;
                    }
                }
            }
            window.display();
        } // End main game loop
    } while (menuOption != 3);
}


