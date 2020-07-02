// Declaration of class Shape.
// Member functions are defined in Shape.cpp.
// Author: Daniel (Yoonho) Kim
// Date: May 05, 2018

#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
public:

	Shape(void);  //constructor
	virtual ~Shape(void); //destructor

	void setNoOfSides(const int &);  // set the # of sides
	int getNoOfSides() const;        // get the # of sides

	static int getObjectCount();     // get the object count
	virtual double Area() const = 0;     // calculate and return area 

protected:
	int mNoOfSides; // represents # of sides in Shape object
	static int mObjectCount; // a static member - counts the # of Shape 
							 //          objects currently instantiated
							 // Only one of these instantiated for the whole class!
};

#endif