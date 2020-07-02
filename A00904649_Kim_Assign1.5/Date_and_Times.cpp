// Date_and_Times.cpp
// Assignment 1.5
// Name: Daniel (Yoonho) Kim
// Date: May 12, 2018

#include<iostream>
#include<stdexcept>
#include "Date_and_Times.h"

using namespace std;

// default constructor for class Date_and_Times
Date_and_Times::Date_and_Times(Date &date, Time times[], size_t size)
	: _date(date),
	  _size(size > 0 ? size:
		throw invalid_argument("Array size must be greater than 0")),
	 _timePtr(new Time[size])
{
	for (size_t i = 0; i < this->_size; ++i)
	{
		_timePtr[i] = times[i];
	}
} // end defalut ctor

// copy ctor for class Date_and_Times
Date_and_Times::Date_and_Times(const Date_and_Times &dateTimes)
	:_date(dateTimes._date),
	 _size(dateTimes._size),
	_timePtr(new Time[dateTimes._size])
{
	for (size_t i = 0; i < this->_size; ++i)
	{
		_timePtr[i] = dateTimes._timePtr[i];
	}
} // end copy ctor

// dtor for class Date_and_Times
Date_and_Times::~Date_and_Times() 
{
	delete[] _timePtr;
	_timePtr = 0;
} // end dtor

Date_and_Times & Date_and_Times::operator=(const Date_and_Times &dateTimes)
{
	if (this == &dateTimes)
	{
		return *this;
	}
	else
	{
		_date = dateTimes._date;

		if (this->_size != dateTimes._size) 
		{
			delete[] _timePtr;
			_size = dateTimes._size;
			_timePtr = new Time[_size];
		}// end inner if

		for (size_t i = 0; i < this->_size; ++i)
		{
			_timePtr[i] = dateTimes._timePtr[i];
		}// end for

		return *this;
	} // end if- else
} // end operator = overload

// display function
void Date_and_Times::display() 
{
	cout << "The date is: ";
	this->_date.print();
	cout << endl;
	cout << "The times are:" << endl;
	for (size_t i = 0; i < this->_size; ++i)
	{
		this->_timePtr[i].printUniversal();
		cout << " ";
	}
	cout << "\n\n";
} // end display

// add FiveSec() add five seconds to all Time objects in array
void Date_and_Times::addFiveSecs() 
{
	for (size_t i = 0; i < this->_size; ++i)
	{
		unsigned int sec = this->_timePtr[i].getSecond();
		this->_timePtr[i].setSecond(sec + 5);
	}
}