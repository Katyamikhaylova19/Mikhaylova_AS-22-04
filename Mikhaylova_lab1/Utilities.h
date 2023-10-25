#pragma once
#include <iostream>

using namespace std;

template <typename T>
void InputCorrectNumber(T& var, bool canEqualToZero = false)
{
	cin >> var;
	while (cin.fail() || cin.peek() != '\n' || (canEqualToZero ? var < 0 : var <= 0))
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Error! Please enter correct data: ";
		cin >> var;
	}
}