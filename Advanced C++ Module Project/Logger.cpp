#include <iostream>
#include "Logger.h"

void Logger::ConsoleLog(int& input, std::string errormessage)
{

	std::cin.get();
	while (std::cin.fail())
	{
		std::cout << errormessage << std::endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> input;
	}

}
