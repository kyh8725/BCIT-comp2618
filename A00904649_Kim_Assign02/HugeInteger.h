// Exercise 9.14 Solution: HugeInteger.h
// HugeInteger class declaration.

// Assignment 2
// Daniel (Yoonho) Kim A00904649
// May 12, 2018

#include <array>

class HugeInteger
{
	// offer friendship to opertor << and >>
	friend std::istream & operator >> (std::istream & src, HugeInteger & value);
	friend std::ostream & operator << (std::ostream & dest, const HugeInteger & value);

public:
	//ctor that converts a "long long" into a HugeInteger
	HugeInteger( long long value = 0LL ); //0LL is constant literal value 0
	                                      //   of type long long
	//ctor that converts a string into a HugeInteger
	HugeInteger( const char *str );

	//adds RHS into LHS (the object pointed to by the "this" pointer) and returns result
    HugeInteger & operator +=( const HugeInteger & RHS);

	//adds a "long long" (RHS) and LHS and puts result into a temp HugeInteger
	//   and returns result
	HugeInteger operator +( long long RHS) const; 

	//adds a string (which will be converted into a HugeInteger) with LHS into a temp 
	//       HugeInteger and returns result
	HugeInteger operator +( const char * RHS) const;

	//subtracts RHS from LHS (the object pointed to by the "this" pointer) and returns result
	HugeInteger & operator -=( const HugeInteger & RHS); 

	//subtracts a "long long" (RHS) from LHS and puts result into a temp HugeInteger 
	//    and returns result
	HugeInteger operator -( long long RHS) const; 

	//subtracts a string (which will be converted into a HugeInteger) from LHS 
	//    and puts result into a temp HugeInteger and returns result
	HugeInteger operator -( const char * RHS) const; 

	//calculates the negation of the object pointed to by the this pointer and returns result
	HugeInteger operator -(void)const;

	//calculates the absolute value of the object pointed to by the this pointer and returns result
	HugeInteger operator ~ (void)const; 

	//Is LHS (the object pointed to by the "this" pointer) equal to RHS
	bool operator ==( const HugeInteger & RHS)const;

	//Is LHS (the object pointed to by the "this" pointer) less than RHS
	bool operator < ( const HugeInteger & RHS)const;

	//Is the object pointed to by the "this" pointer equal to zero
	bool operator ! (void)const;

	//Convert a string into a HugeInteger
	void input( const char *str );

	// overload typecast to double
	operator double(void) const;

	// overload preincrement operator for the HugeInteger class
	HugeInteger & operator ++ (void);
	// overload postincrement operator for the HugeInteger class
	HugeInteger operator ++ (int);

	// overload predecrement operator for the HugeInteger class
	HugeInteger & operator -- (void);
	// overload postdecrement operator for the HugeInteger class
	HugeInteger operator -- (int);

private:
	bool negative;  // will be true if number is negative
	std::array<unsigned short,40> hugeInt; // each element in the array represents 
	                           //    one digit of the number
};

// overloads the binary "!=" operator through inline global function
inline bool operator != (const HugeInteger & LHS, const HugeInteger & RHS)
{
	return !(LHS==RHS);
}

// overloads the binary ">" operator through inline global function
inline bool operator > (const HugeInteger & LHS, const HugeInteger & RHS)
{
	return !((LHS < RHS) || (LHS==RHS));
}

// overloads the binary ">=" operator through inline global function
inline bool operator >= (const HugeInteger & LHS, const HugeInteger & RHS)
{
	return !(LHS < RHS);
}

// overloads the binary "<=" operator through inline global function
inline bool operator <= (const HugeInteger & LHS, const HugeInteger & RHS)
{
	return ((LHS < RHS) || (LHS ==RHS));
}

// overloads the unary "+" operator through inline global function
// will return true if operand is != zero
inline bool operator + (const HugeInteger & hugeInt)
{
	return !(!hugeInt);
}

//overloads the << and >> operators for the HugeInteger class
std::istream & operator >> (std::istream & src, HugeInteger & value);
std::ostream & operator << (std::ostream & dest, const HugeInteger & value);
