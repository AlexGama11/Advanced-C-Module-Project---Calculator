#include <iostream>
#include "Menu.h"

void Menu::Display(int& menuOption, int& optionInput)
{

	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cout << "|What do you wish to do? [Calculate = 1, Options = 2, Quit = 3]|" << std::endl;
	std::cout << "----------------------------------------------------------------" << std::endl;
	std::cin >> menuOption;

	log.ConsoleLog(menuOption, "Please input a number between 1 and 3!");

	optionInput = menuOption;
}
