#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"


Board::Board()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			this->gameBoard[i][j] = 0;
		}
	}
	
}

Board::~Board()
{
}

void Board::updateBoard(int row, int col, int current_player)
{
	if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
	{
		gameBoard[row][col] = current_player;
	}
}

int Board::getFirstRow(int col)
{
	if (col < 0 || col >= COLS)
	{
		return -1;
	}

	for (int row = ROWS - 1; row >= 0; row--)
	{
		if (gameBoard[row][col] == 0)
		{
			return row;
		}
	}
	return -1;
}

bool Board::isColFull(int col)
{
	if (gameBoard[0][col] != 0)
	{
		return true;
	}
	
}


