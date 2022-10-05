#include <iostream>
#include <sstream>
#include "Settings.h"

void Settings::Options(char inputOne, char inputTwo)
{

	std::cout << "The colour options are:" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	std::cout << "|1 = Blue | 2 = Green | 3 = Aqua | 4 = Red|_____" << std::endl;
	std::cout << "|5 = Purple | 6 = Yellow | 7 = White | 8 = Gray|_______________" << std::endl;
	std::cout << "|9 = Light Blue | 0 = Black | A = Light Green | B = Light Aqua|_________" << std::endl;
	std::cout << "|C = Light Red | D = Light Purple | E = Light Yellow | F = Bright White|" << std::endl;
	std::cout << "------------------------------------------------------------------------" << std::endl;


	std::cout << "Choose your background colour for the calculator." << std::endl;
	std::cin >> inputOne;

	std::cout << "Choose the letter colour for the calculator." << std::endl;
	std::cin >> inputTwo;

	std::stringstream colour;

	colour << "Color " << inputOne << inputTwo;

	std::string colourString = colour.str();

	const char* colourChar = colourString.c_str();

	system(colourChar);

}
