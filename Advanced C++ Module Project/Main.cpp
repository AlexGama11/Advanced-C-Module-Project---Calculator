#include <iostream>
#include <string>
#include <vector>
#include <sstream>

enum class MenuOptions 
{ 
	Calculate = 1, 
	Options, 
	Quit 
};

enum class CalculatorOptions 
{ 
	Add = 1, 
	Subtract, 
	Multiply, 
	Divide, 
	Modulus, 
	Power 
};

//bool isCalcRunning = true;
//std::string quit;
//int result{ 0 };

void Check(int& input, std::string errormessage);

void Input(int& inputOne, int& inputTwo, std::string operation);

void Add(int firstInput, int secondInput, int& resultOutput);

void Subtract(int firstInput, int secondInput, int& resultOutput);

void Multiply(int firstInput, int secondInput, int& resultOutput);

void Divide(bool& divideZero, int firstInput, int secondInput, int& resultOutput);

void Modulus(bool& divideZero, int firstInput, int secondInput, int& resultOutput);

void Power(int base, int exponent, int& resultOutput);

void Options(char inputOne, char inputTwo);

void Quit(bool& runningStatus, char& quitchar);


int main()
{
	bool isCalcRunning = true;
	bool dividedZero = false;

	int firstInput{ 0 };
	int secondInput{ 0 };
	int result{ 0 };

	char firstChar{ };
	char secondChar{ };

	int menuOption{ 0 };
	int optionInput{ 0 };
	
	int calculatorMenu{ 0 };
	int calculatorInput{ 0 };

	char quitInput{ };

	while (isCalcRunning)
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << "|What do you wish to do? [Calculate = 1, Options = 2, Quit = 3]|" << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cin >> menuOption;

		Check(menuOption, "Please input a number between 1 and 3!");

		optionInput = menuOption;

		switch (MenuOptions(optionInput))
		{

		case MenuOptions::Calculate:

			std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cout << "|What calculation do you wish to do? [Add = 1, Subtract = 2, Multiply = 3, Divide = 4, Modulus = 5, Power = 6]|" << std::endl;
			std::cout << "---------------------------------------------------------------------------------------------------------------" << std::endl;
			std::cin >> calculatorMenu;

			Check(calculatorMenu, "Please input a number between 1 and 6!");

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

		case MenuOptions::Options:

			Options(firstChar, secondChar);

			break;

		case MenuOptions::Quit:

			Quit(isCalcRunning, quitInput);

			break;

		default:

			std::cout << "Please select an option!" << std::endl;
			break;

		}

		if (!isCalcRunning)
		{
			return 0;
		}
	}

}

void Check(int& input, std::string errormessage)
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

void Add(int firstInput, int secondInput, int& resultOutput)
{
	resultOutput = firstInput + secondInput;
}

void Subtract(int firstInput, int secondInput, int& resultOutput)
{
	resultOutput = firstInput - secondInput;
}

void Multiply(int firstInput, int secondInput, int& resultOutput)
{
	resultOutput = firstInput * secondInput;
}

void Divide(bool& divideZero, int firstInput, int secondInput, int& resultOutput)
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

void Modulus(bool& divideZero, int firstInput, int secondInput, int& resultOutput)
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

void Power(int base, int exponent, int& resultOutput)  //2 ^ 2 = 4
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

	/*std::vector<int> results;

	int multiplicationResult{ 0 };

	for (int i = 0; i < exponent - 1; i++)
	{
		multiplicationResult = base * base;

		results.push_back(multiplicationResult);

		if (i == exponent - 1)
		{
			result += results[i];
		}
	}*/
}

void Input(int& inputOne, int& inputTwo, std::string operation)
{
	std::cout << "Enter the first number you wish to " << operation << std::endl;
	std::cin >> inputOne;

	Check(inputOne, "Your number is either too big, too small or not an integer!");

	std::cout << "Enter the second number you wish to " << operation << std::endl;
	std::cin >> inputTwo;

	Check(inputTwo, "Your number is either too big, too small or not an integer!");
}

void Options(char inputOne, char inputTwo)
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

void Quit(bool& runningStatus, char& quitchar)
{
	std::cout << "Quit? Y/N" << std::endl;
	std::cin >> quitchar;

	if (quitchar == 'Y' || quitchar == 'y')
	{
		runningStatus = false;
	}
}