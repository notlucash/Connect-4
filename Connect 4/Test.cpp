#include "Board.hpp"
#include <iostream>

void testVerticalWin();
void testHorizontalWin();
void testDiagonalWin();
void testDraw();
void testColumnFull();

void testVerticalWin()
{
	Board gameBoard;
	int row = 5;
	gameBoard.updateBoard(row, 1, 0);
	gameBoard.updateBoard(row, 1, 1);
	gameBoard.updateBoard(row, 1, 2);
	gameBoard.updateBoard(row, 1, 3);

	if (gameBoard.checkWin(1))
	{
		std::cout << "Vertical win works!" << std::endl;
	}
	else
	{
		std::cout << "Vertical win does not work!" << std::endl;
	}
}

void testHorizontalWin()
{
	Board gameBoard;
	int row = 5;
	gameBoard.updateBoard(row, 0, 4);
	gameBoard.updateBoard(row, 1, 4);
	gameBoard.updateBoard(row, 2, 4);
	gameBoard.updateBoard(row, 3, 4);
	
	if (gameBoard.checkWin(1))
	{
		std::cout << "Horizontal win works!" << std::endl;
	}
	else
	{
		std::cout << "Horizontal win does not work!" << std::endl;
	}
}

void testDiagonalWin()
{
	Board gameBoard;

	gameBoard.updateBoard(2, 3, 1);
	gameBoard.updateBoard(3, 2, 1);
	gameBoard.updateBoard(4, 1, 1);
	gameBoard.updateBoard(5, 0, 1);

	if (gameBoard.checkWin(1))
	{
		std::cout << "Diagonal win works!" << std::endl;
	}
	else
	{
		std::cout << "Diagonal win does not work!" << std::endl;
	}
}

void testDraw()
{

}

void testColumnFull()
{
	Board gameBoard;

	int col = 0;

	for (int row = 5; row >= 0; row--)
	{
		if (row % 2 == 0)
		{
			gameBoard.updateBoard(row, col, 1);
		}
		else
		{
			gameBoard.updateBoard(row, col, 2);
		}
	}
}
