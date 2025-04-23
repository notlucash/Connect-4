
#pragma once
#include <iostream>
#include <fstream>
#include <time.h>
#include <SFML/Graphics.hpp>
#include "Balls.hpp"

class Board {
public:
	Board(); //constructor
	~Board(); //destructor

	int gameBoard[ROWS][COLS];
	
	void updateBoard(int row, int col, int current_player);
	int getFirstRow(int col);
	bool isColFull(int col);


private:
	
};
