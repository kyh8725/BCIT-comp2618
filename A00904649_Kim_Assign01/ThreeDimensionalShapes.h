// Declaration of class ThreeDimensionalShapes.
// Member functions are defined in ThreeDimensionalShapes.cpp.
// Author: Daniel (Yoonho) Kim
// Date: May 05, 2018

#ifndef THREEDIMENSIONALSHAPES_H
#define THREEDIMENSIONALSHAPES_H

#include "Shape.h"

class ThreeDimensionalShapes : public Shape
{
public:
	ThreeDimensionalShapes(void);  //constructor
	virtual ~ThreeDimensionalShapes(void); //destructor

	virtual double Volume() const = 0;   // calculate and return volume
};
#endif
