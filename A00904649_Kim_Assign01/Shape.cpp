// Member-function definitions for class Shape.
// Author: Daniel (Yoonho) Kim 
// Date: May 05, 2018

#include "Shape.h"

int Shape::mObjectCount = 0;

// constructor
Shape::Shape(void)
	:mNoOfSides(1)
{
	++Shape::mObjectCount;
}

// desstructor
Shape::~Shape(void)
{
	--Shape::mObjectCount;
}

// used to set mNoOfSides member
void Shape::setNoOfSides(const int & setVal)
{
	if (setVal > 0)
	{
		this->mNoOfSides = setVal;
	}

	// otherwise just leave set to original value
}

// used to return current value of mNoOfSides member
int Shape::getNoOfSides() const
{
	return this->mNoOfSides;
}

// used to return current value of mObjectCount static member
int Shape::getObjectCount()
{
	return Shape::mObjectCount;
}

// used to calculate and return area 
double Shape::Area(void) const
{
	return 0.0;
}