#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Balls.hpp"
#include "Menu.hpp"

#define ROWS 6
#define COLS 7

int main()
{
	Board game;
	game.runGame();
}


