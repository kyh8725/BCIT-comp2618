// Array.h
// Comp2618 Assignment 3
// Daniel (Yoonho) Kim
// May 22, 2018

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <stdexcept>
#include <iomanip>

template <typename elementType = int , int numberOfElements = 5>
class Array
{
public:

   Array(); // default constructor
   Array(const Array&); // copy ctor
   ~Array(); // destructor
   int getSize() const; // return size

   bool operator==( const Array & ) const; // equality operator

   // inequality operator; returns opposite of == operator
   bool operator!=( const Array &right ) const  
   { 
      return ! ( *this == right ); // invokes Array::operator==
   } // end function operator!=
   
   // subscript operator for non-const objects returns modifiable lvalue
   elementType &operator[]( int );

   // subscript operator for const objects returns rvalue
   elementType operator[]( int ) const;

   // returns the number of instantiated object
   static int getArrayCount();

   // input the array elements
   void inputArray();

   // output the array elements
   void outputArray() const;

private:

   static int arrayCount;// number of instantiated objects
   int size; // array size
   elementType myArray[numberOfElements]; // array template

}; // end class Array

// default constructor for class Array (default size 5)
template <typename elementType, int numberOfElements>
Array<elementType, numberOfElements>::Array()
	:size(numberOfElements)
{
	myArray[size];
	++arrayCount;
} // end Array default constructor

  // copy constructor for class Array;
template <typename elementType, int numberOfElements>
Array<elementType, numberOfElements>::Array(const Array &arrayToCopy)
	: size(arrayToCopy.size)
{
	for (int i = 0; i < size; ++i) {
		myArray[i] = arrayToCopy.myArray[i]; // copy into object
	}
	++arrayCount;
} // end Array copy constructor

  // destructor for class Array
template <typename elementType, int numberOfElements>
Array<elementType, numberOfElements>::~Array()
{
	--arrayCount;
} // end destructor

  // return number of elements of Array
template <typename elementType, int numberOfElements>
int Array<elementType, numberOfElements>::getSize() const
{
	return size;
} // end function getSize


  // determine if two Arrays are equal and
  // return true, otherwise return false
template <typename elementType, int numberOfElements>
bool Array<elementType, numberOfElements>::operator==(const Array &right) const
{
	if (this->size != right.size) {
		return false; // arrays of different number of elements
	}

	for (int i = 0; i < this->size; ++i) {
		if (this->myArray[i] != right.myArray[i])
		{
			return false; // Array contents are not equal
		}
	}
	return true; // Arrays are equal
} // end function operator==

  // overloaded subscript operator for non-const Arrays;
  // reference return creates a modifiable lvalue
template <typename elementType, int numberOfElements>
elementType &Array<elementType, numberOfElements>::operator[](int subscript)
{
	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= this->size) {
		throw std::out_of_range("Subscript out of range");
	}

	return this->myArray[subscript]; // reference return
} // end function operator[]

  // overloaded subscript operator for const Arrays
  // const reference return creates an rvalue
template <typename elementType, int numberOfElements>
elementType Array<elementType, numberOfElements>::operator[](int subscript) const
{
	// check for subscript out-of-range error
	if (subscript < 0 || subscript >= this->size) {
		throw std::out_of_range("Subscript out of range");
	}

	return myArray[subscript]; // returns copy of this element
} // end function operator[]

// initialize arrayCount value
template <typename elementType, int numberOfElements>
int Array<elementType, numberOfElements>::arrayCount = 0;

// returns arrayCount - the number of instantiated object
template <typename elementType, int numberOfElements>
int Array<elementType, numberOfElements>::getArrayCount()
{
	return arrayCount;
}

// takes user input and create array elements
template <typename elementType, int numberOfElements>
void Array<elementType, numberOfElements>::inputArray() 
{
	int i;
	elementType in;

	for (i = 0; i < size && cin >> in; i++)
	{
		myArray[i] = in;
	}
}
// output the array elements
template <typename elementType, int numberOfElements>
void Array<elementType, numberOfElements>::outputArray() const
{
	for (int i = 0; i < size; i++)
	{
		cout << myArray[i];

		if (i + 1 != size)
		{
			cout << " ";
		}
	}
	cout << endl;
}

#endif

