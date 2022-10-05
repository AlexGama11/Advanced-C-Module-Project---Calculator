#pragma once
#include "Logger.h"


class Menu
{

public:

	enum class MenuOptions
	{
		Calculate = 1,
		Options,
		Quit
	};

	void Display(int&menuOption, int&optionInput);

private:

	Logger log;

};

