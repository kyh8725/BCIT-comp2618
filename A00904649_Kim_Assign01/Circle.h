// Declaration of class Circle.
// Member functions are defined in Circle.cpp.
// Author: Daniel (Yoonho) Kim
// Date: May 05, 2018

#ifndef CIRCLE_H
#define CIRCLE_H

#include "TwoDimensionalShapes.h"

class Circle :public TwoDimensionalShapes
{
public:
	Circle(void); // constructor

	void setRadius(const double &);  //set the radius
	double getRadius() const;  // get the radius

	virtual double Area() const override;  // overrides Area() method of Shape class

protected:
	const static double pi; // Static member used in calculations
							// Only one of these instantiated for the whole class!
	double mRadius;  // member used to represent radius
};

#endif