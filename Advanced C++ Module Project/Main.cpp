#include <iostream>
#include <string>
#include <sstream>
#include "Calculator.h"

Calculator calc;

int main()
{

	while (calc.IsCalculatorRunning())
	{

		calc.DisplayMenu();

		calc.Calculate();
	}

}