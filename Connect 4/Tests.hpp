#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board.hpp"
#include "Balls.hpp"
#include "Menu.hpp"

class Tests {
public:

	// 5 test cases, returns success
	bool TestColumnFull(); 
	bool TestFullBoard(); // tie basically
	bool TestHorizontalWin();
	bool TestDiagonalWin();
	bool TestVerticalWin();




};