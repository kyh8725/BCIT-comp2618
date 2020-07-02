// Declaration of class Cylinder.
// Member functions are defined in Cylinder.cpp.
// Author: Daniel (Yoonho) Kim
// Date: May 05, 2018

#ifndef CYLINDER_H
#define CYLINDER_H

#include "ThreeDimensionalShapes.h"

class Cylinder :public ThreeDimensionalShapes
{
public:
	Cylinder(void); // constructor

	void setRadius(const double &);  //set the radius
	double getRadius() const;  // get the radius

	void setHeight(const double &); // set the height
	double getHeight() const; // get the height

	virtual double Area() const override;    // overrides Area()   method of Shape class
	virtual double Volume() const override;  // overrides Volume() method of ThreeDimensionalShapes class

protected:
	double mHeight;  // member used to represent height
	double mRadius;  // member used to represent radius

	const static double pi; // Static member used in calculations
							// Only one of these instantiated for the whole class!
};
#endif