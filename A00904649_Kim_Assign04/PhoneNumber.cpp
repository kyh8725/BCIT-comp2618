// PhoneNumber.cpp
// Comp 2618 Assignment 4
// name: Daniel (Yoonho) Kim
// Date: May 28, 2018

#include <iomanip>
#include "PhoneNumber.h"
using namespace std;

// default constructor
PhoneNumber::PhoneNumber()
	:phone{}, areaCode{}, exchange{}, line{}
{}

// overloaded stream insertion operator;
ostream &operator<<( ostream &output, const PhoneNumber &number ) 
{ 
	output << "(" << number.areaCode << ") " << number.exchange << "-" << number.line; 
	return output; // enables cout << a << b << c; 
} // end function operator<<


  // overloaded stream extraction operator
istream &operator>>( istream &input, PhoneNumber &number )
{ 
	input.getline(number.phone, 15);

	if (input.gcount() != 14 &&
		// input should be 14 characters long
		(number.phone[2] == '0' || number.phone[2] == '1') &&
		// the middle digit of an area code should be 0 or 1.
		(number.phone[1] != '0' && number.phone[1] != '1') &&
		// first digit of area code should not be 0 or 1 
		(number.phone[6] != '0' && number.phone[6] != '1') &&
		// first digit of exchange portion of the phone number should not be 0 or 1.		
		(number.phone[0] == '(' && number.phone[4] == ')') &&
		// area code should be wrapped with ().
		(number.phone[9] == '-') &&
		// '-' should not be a different sign

		(isdigit(number.phone[1]) && isdigit(number.phone[2]) && isdigit(number.phone[3]) &&
		isdigit(number.phone[6]) && isdigit(number.phone[7]) && isdigit(number.phone[8]) &&
		isdigit(number.phone[10]) && isdigit(number.phone[11]) && isdigit(number.phone[12]) && isdigit(number.phone[13]))
		// phone numbers are digits. not letters
		) 
	{
		// set area code and exchange numbers
		for(int i = 0; i < 3; i++) 
		{
			number.areaCode[i] = number.phone[i + 1];
			number.exchange[i] = number.phone[i + 6];
		}
		// set line numbers
		for (int i = 0; i < 4; i++)
		{
			number.line[i] = number.phone[i + 10];
		}
	} 
	else
	{
	input.clear(ios::failbit); // set failbit if the input does not pass the validation
	}

	return input;

} // end function operator>>
