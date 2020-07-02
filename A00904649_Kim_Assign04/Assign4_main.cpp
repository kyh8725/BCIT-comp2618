// Assign4_main.cpp
// Comp 2618 Assignment 4
// name: Daniel (Yoonho) Kim
// Date: May 28, 2018

#include "PhoneNumber.h"
#include <iostream>
using namespace std;

int main()
{
	PhoneNumber phone; // instantiate PhoneNumber object

	int fail = 1; // condition for while loop

	while (fail == 1) // when failbit is set int fail will be set to 0 which will termintate the while loop
	{
		cout << "Enter a phone number in the form (123) 456-7890:" << endl;

		cin >> phone; // >> will validate the input and process it

		if (cin.fail())
		{
			cout << "\nInvalid phone number entered.\n" << endl;
			fail = 0;
		}
		else
		{
			cout << "\nThe phone number entered was: " << phone << "\n" << endl;
		}
	}
	
	system("pause");
	return 0;
}
