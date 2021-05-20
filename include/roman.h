#pragma once
#include <string>
#include <vector>
#include <exception>
#include <iostream>

class Roma
{
	int number;
	std::string roma;

public:

	Roma(int n, std::string r);
	Roma(const Roma& roma);

	bool itsRoma(std::string _roma);
	int  ToNumber();
	std::string ToRoma();
	int  ValueOfChar(char symbol);

	std::string ToRoma(int a);
};

Roma::Roma(int n, std::string r)
{
	number = n;
	roma = r;
}

Roma::Roma(const Roma& _roma)
{
	number = _roma.number;
	roma = _roma.roma;
}

bool Roma::itsRoma(std::string _roma)
{
	for (int i = 0; i < _roma.length(); i++)
		if (_roma[i] != 'I' && _roma[i] != 'M' && _roma[i] != 'X' && _roma[i] != 'V' && _roma[i] != 'L' && _roma[i] != 'C') return false;
	return true;
}

int Roma::ValueOfChar(char symbol)
{
	if (symbol == 'I')
		return 1;
	if (symbol == 'V')
		return 5;
	if (symbol == 'X')
		return 10;
	if (symbol == 'L')
		return 50;
	if (symbol == 'C')
		return 100;
	if (symbol == 'D')
		return 500;
	if (symbol == 'M')
		return 1000;

	throw std::logic_error("unknown symbol");
}

int Roma::ToNumber()
{


	int result = 0;

	for (int i = 0; i < roma.length(); i++)
	{
		int symbol_1 = ValueOfChar(roma[i]);

		if (i + 1 < roma.length())
		{

			int symbol_2 = ValueOfChar(roma[i + 1]);
			if (symbol_1 >= symbol_2)
				result += symbol_1;
			else
			{
				result += (symbol_2 - symbol_1);
				i++;
			}
		}
		else
			result += symbol_1;
	}
	return result;
}

std::string Roma::ToRoma()
{
	int num[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
	std::string str[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };
	std::string result;
	int i = 12;
	while (number > 0)
	{
		int div = number/ num[i];
		number = number % num[i];
		while (div--)
		{
			result+=str[i];
		}
		i--;
	}
	return result;
}