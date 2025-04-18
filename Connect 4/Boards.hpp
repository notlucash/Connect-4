#pragma once

#include <iostream>
#include <fstream>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Boards {
public:
	Boards();
	~Boards();
	
	int ConnectFourWrapper();

	int columns;
};