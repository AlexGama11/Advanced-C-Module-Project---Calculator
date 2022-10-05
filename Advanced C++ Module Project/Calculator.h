#pragma once
#include "Menu.h"
#include "Logger.h"
#include "Settings.h"

class Calculator
{

public:

	bool IsCalculatorRunning();

	void DisplayMenu();

	void Calculate();

	void Input(int& inputOne, int& inputTwo, std::string operation);

	void Add(int firstInput, int secondInput, int& resultOutput);

	void Subtract(int firstInput, int secondInput, int& resultOutput);

	void Multiply(int firstInput, int secondInput, int& resultOutput);

	void Divide(bool& divideZero, int firstInput, int secondInput, int& resultOutput);

	void Modulus(bool& divideZero, int firstInput, int secondInput, int& resultOutput);

	void Power(int base, int exponent, int& resultOutput);

	void Quit(bool& runningStatus, char& quitchar);

private:

	bool isCalcRunning{ true };

	int menuOption{ 0 };
	int optionInput{ 0 };

	int calculatorMenu{ 0 };
	int calculatorInput{ 0 };

	int firstInput{ 0 };
	int secondInput{ 0 };
	int result{ 0 };

	char firstChar{ };
	char secondChar{ };

	bool dividedZero = false;

	char quitInput{ };

	Menu menu;
	Logger log;
	Settings options;

};

