// Assignment 5 Starting Point: Complex.cpp
// Member-function definitions for class Complex.
// Author: Bob Langelaan 
// Date: Feb 19, 2014
// Daniel (Yoonho) Kim  A00904649
// June 10, 2018

#include "Complex.h"
#include <iomanip>
using namespace std;

//ctor
Complex::Complex ( double real, double imag )
{
	this->real_part = real;
	this->imaginary_part = imag;
}

// overload the "+=" operator
Complex & Complex::operator += (const Complex & op )
{
	this->real_part += op.real_part;
	this->imaginary_part += op.imaginary_part;

	return (*this);
}

// overload the "-=" operator
Complex & Complex::operator -= (const Complex & op )
{
	this->real_part -= op.real_part;
	this->imaginary_part -= op.imaginary_part;

	return (*this);
}

// overload the "==" operator
bool Complex::operator == (const Complex & RHS) const
{
	if (this->real_part != RHS.real_part)
	{
		return false;
	}
	else if (this->imaginary_part != RHS.imaginary_part)
	{
		return false;
	}
	else
	{
		return true;
	}
}

// return the real part of the complex #
double Complex::getReal(void)
{
	return this->real_part;
}

// return the imaginary part of the complex #
double Complex::getImaginary(void)
{
	return this->imaginary_part;
}

// display the complex #
void Complex::display (void)
{
   // set floating-point number format
   cout << fixed << setprecision(3);

   cout << "( " << this->getReal() << " , " << this->getImaginary() << " )";
}

// overloads the binary '+' operator through a global function
Complex operator + (const Complex & LHS, const Complex & RHS )
{
	Complex temp = LHS;
	temp += RHS; // uses the overloaded "+=" operator
	return temp;
}

// overloads the binary '-' operator through a global function
Complex operator - (const Complex & LHS, const Complex & RHS )
{
	Complex temp = LHS;
	temp -= RHS; // uses the overloaded "-=" operator
	return temp;
}

// overloads the binary "!=" operator through a global function
bool operator != (const Complex & LHS, const Complex & RHS)
{
	return !(LHS == RHS); // uses overloaded "==" operator
}

// overloads the binary "<<" operator through a global friend function
//   Complex object will be formatted in the following format:
//   ( -125.00, 23.44 )
ostream & operator << (ostream & dest, const Complex & obj)
{
	ios_base::fmtflags origFormat, octFormat;
	origFormat = cout.flags();
	octFormat = origFormat | ios::oct;
	
	if (origFormat == octFormat) 
	{
		dest << internal << showpos << setprecision(2) << fixed;
		dest << "(" << setw(10)<<obj.real_part << "," << setw(10) << obj.imaginary_part << ")";
		cout.flags(origFormat);
		return dest; // enables  cout << a << b << c
	}
	else 
	{
		dest << noshowpos << fixed << setprecision(4);
		dest << obj.real_part << " " << obj.imaginary_part << "i";
		cout.flags(origFormat);
		return dest; // enables  cout << a << b << c
	}
}

// overloads the binary ">>" operator through a global friend function
//   Complex obj will be input by the user in the following format:
//   ( -125.00, 23.44 )
istream & operator >> (istream & input, Complex & obj)
{
	ios_base::fmtflags origFormat, octFormat;
	origFormat = cin.flags();
	octFormat = origFormat & ~ios::oct; 

	if (origFormat != octFormat) 
	{
		input.ignore(2, '('); // skip over '('
		input >> obj.real_part; // read the real component of the Complex #

		if (input.peek() != ',')
		{
			input.clear(ios::failbit);
			return input;
		}
		input.ignore(2, ','); // skip over ','
		input >> obj.imaginary_part; // read the real component of the Complex #

		if (input.peek() != ')') 
		{
			input.clear(ios::failbit);
			return input;
		}

		input.ignore(2, ')'); // skip over ')'
		cin.flags(origFormat);
		return input; // enables  cin >> a >> b >> c
	}
	else
	{
		input >> obj.real_part;

		if (input.peek() == 'i')
		{
			obj.imaginary_part = obj.real_part;
			obj.real_part = 0;
			input.ignore();
			return input;
		}

		input.ignore();//ignore space
		input >> obj.imaginary_part;

		if (input.peek() != 'i') 
		{
			input.clear(ios::failbit);
			return input;
		}

		input.ignore();

		cin.flags(origFormat);
		return input; // enables  cin >> a >> b >> c
	}
}
