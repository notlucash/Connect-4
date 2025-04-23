#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

#define ROWS 6
#define COLS 7

class Ball;

class Board
{
public:
    Board();
    ~Board();

    void updateBoard(int row, int col, int player);


    int getFirstEmptyRow(int col);
    bool isColumnFull(int col);
    bool checkWin(int player);


    void runGame(); // handles game

    int gameBoard[ROWS][COLS];
private:

    bool checkLine(int player, int r1, int c1, int dr, int dc);

};
