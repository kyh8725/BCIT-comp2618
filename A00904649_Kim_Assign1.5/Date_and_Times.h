// Date_and_Times.h
// Assignment 1.5
// Name: Daniel (Yoonho) Kim
// Date: May 12, 2018

#ifndef DATE_AND_TIMES_H
#define DATE_AND_TIMES_H

#include "Date.h"
#include "Time.h"

// class Date_and_Times definition
class Date_and_Times
{
public:

	//default ctor
	Date_and_Times(Date &, Time[], size_t);

	//copy ctor
	Date_and_Times(const Date_and_Times &);

	// overload assignment operator
	Date_and_Times &operator = (const Date_and_Times &);

	//dtor
	~Date_and_Times();
   
	//display date and times
	void display();

   // For simplicity sake, you need not worry about seconds value becoming greater than 59.
   void addFiveSecs();  // adds 5 seconds to each Time object

private:
	size_t _size;  // # of Time objects to be created dynamically
	Date _date;    // Date object
	Time * _timePtr; //ptr to array of Time objects created dynamically

}; // end class Date_and_Times

#endif
