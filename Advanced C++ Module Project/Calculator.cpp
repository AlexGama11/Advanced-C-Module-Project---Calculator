#include <iostream>
#include "Calculator.h"


enum class CalculatorOptions
{
	Add = 1,
	Subtract,
	Multiply,
	Divide,
	Modulus,
	Power
};


bool Calculator::IsCalculatorRunning()
{
	return isCalcRunning;
}

void Calculator::DisplayMenu()
{
	menu.Display(menuOption, optionInput);

}

void Calculator::Calculate()
{
	switch (Menu::MenuOptions(optionInput))
	{

	case Menu::MenuOptions::Calculate:

		std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cout << "|What calculation do you wish to do? [Add = 1, Subtract = 2, Multiply = 3, Divide = 4, Modulus = 5, Power = 6]|" << std::endl;
		std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
		std::cin >> calculatorMenu;

		log.ConsoleLog(calculatorMenu, "Please input a number between 1 and 6!");

		calculatorInput = calculatorMenu;

		switch (CalculatorOptions(calculatorInput))
		{
		case CalculatorOptions::Add:
			Input(firstInput, secondInput, "add");

			Add(firstInput, secondInput, result);

			std::cout << "Result is: " << result << std::endl;
			break;

		case CalculatorOptions::Subtract:

			Input(firstInput, secondInput, "subtract");

			Subtract(firstInput, secondInput, result);

			std::cout << "Result is: " << result << std::endl;
			break;

		case CalculatorOptions::Multiply:

			Input(firstInput, secondInput, "multiply");

			Multiply(firstInput, secondInput, result);

			std::cout << "Result is: " << result << std::endl;
			break;

		case CalculatorOptions::Divide:

			Input(firstInput, secondInput, "divide");

			Divide(dividedZero, firstInput, secondInput, result);

			if (dividedZero == false)

			{
				std::cout << "Result is: " << result << std::endl;
				break;
			}

			else
			{
				break;
			}

		case CalculatorOptions::Modulus:

			Input(firstInput, secondInput, "use to get a remainder of a division");

			Modulus(dividedZero, firstInput, secondInput, result);

			if (dividedZero == false)

			{
				std::cout << "Result is: " << result << std::endl;
				break;
			}

			else
			{
				break;
			}

		case CalculatorOptions::Power:

			Input(firstInput, secondInput, "use to calculate a power");

			Power(firstInput, secondInput, result);

			std::cout << "Result is: " << result << std::endl;
			break;

		default:
			std::cout << "Please select an option!" << std::endl;
			break;

		}
		break;

	case Menu::MenuOptions::Options:

		options.Options(firstChar, secondChar);

		break;

	case Menu::MenuOptions::Quit:

		Quit(isCalcRunning, quitInput);

		break;

	default:

		std::cout << "Please select an option!" << std::endl;
		break;

	}
}

void Calculator::Input(int& inputOne, int& inputTwo, std::string operation)
{
	std::cout << "Enter the first number you wish to " << operation << std::endl;
	std::cin >> inputOne;

	log.ConsoleLog(inputOne, "Your number is either too big, too small or not an integer!\nPlease input your number again!");

	std::cout << "Enter the second number you wish to " << operation << std::endl;
	std::cin >> inputTwo;

	log.ConsoleLog(inputTwo, "Your number is either too big, too small or not an integer!\nPlease input your number again!");
}

void Calculator::Add(int firstInput, int secondInput, int& resultOutput)
{
	resultOutput = firstInput + secondInput;
}

void Calculator::Subtract(int firstInput, int secondInput, int& resultOutput)
{
	resultOutput = firstInput - secondInput;
}

void Calculator::Multiply(int firstInput, int secondInput, int& resultOutput)
{
	resultOutput = firstInput * secondInput;
}

void Calculator::Divide(bool& divideZero, int firstInput, int secondInput, int& resultOutput)
{

	if (firstInput == 0)
	{
		resultOutput = 0;
	}

	else if (secondInput == 0)
	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "|You can't divide by zero!|" << std::endl;
		std::cout << "---------------------------" << std::endl;

		divideZero = true;
	}

	else
	{
		resultOutput = firstInput / secondInput;
	}

}

void Calculator::Modulus(bool& divideZero, int firstInput, int secondInput, int& resultOutput)
{

	if (firstInput == 0)
	{
		resultOutput = 0;
	}

	else if (secondInput == 0)
	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "|You can't divide by zero!|" << std::endl;
		std::cout << "---------------------------" << std::endl;

		divideZero = true;
	}

	else
	{
		resultOutput = firstInput % secondInput;
	}

}

void Calculator::Power(int base, int exponent, int& resultOutput)
{

	resultOutput = base; //2

	if (exponent == 0)
	{
		resultOutput = 1;
	}

	else if (exponent == 1)
	{
		resultOutput = base;
	}

	else if (base == 0)
	{
		resultOutput = 0;
	}

	else
	{
		for (int i = 0; i < exponent - 1; i++)
		{
			resultOutput *= base; //8
		}
	}

}

void Calculator::Quit(bool& runningStatus, char& quitchar)
{
	std::cout << "Quit? Y/N" << std::endl;
	std::cin >> quitchar;

	if (quitchar == 'Y' || quitchar == 'y')
	{
		runningStatus = false;
	}

	else
	{
		std::cout << "\x1B[2J\x1B[H";
	}
}
