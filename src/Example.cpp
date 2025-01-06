//***************************************************************************
// File name:   Example.cpp
// Author:      
// Date:        1/6/2025
// Class:       CS 485
// Assignment:  
// Purpose:     Demonstrate special member functions
//***************************************************************************

#include "../include/Example.h"
#include <iostream>

int Example::counter = 0;

//***************************************************************************
// Constructor:  Example
//
// Description: Create object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Example::Example() {
	mpInt = nullptr;
	mID = counter++;
	std::cout << "ctor() : " << mID << "\n";
}

//***************************************************************************
// Constructor: Example
//
// Description: Create object
//
// Parameters:  value - value to store in object
//
// Returned:    None
//***************************************************************************
Example::Example(int value) {
	mpInt = new int;
	*mpInt = value;
	mID = counter++;
	std::cout << "ctor(int) : " << mID << "\n";
}

//***************************************************************************
// Constructor: Example
//
// Description: Copy Constructor
//
// Parameters:  rcObj - the object to copy
//
// Returned:    None
//***************************************************************************
Example::Example(const Example &rcObj) {
	mpInt = nullptr;
	if (nullptr != rcObj.mpInt) {
		mpInt = new int;
		*mpInt = *rcObj.mpInt;
	}
	mID = counter++;
	std::cout << "cctor() : " << mID << "\n";
}

//***************************************************************************
// Destructor: Example
//
// Description: Destroy object, free memory
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Example::~Example() {
	if (nullptr != mpInt) {
		delete mpInt;
		mpInt = nullptr;
	}
	std::cout << "dtor() : " << mID << "\n";
}

//***************************************************************************
// Method: 			operator=
//
// Description: Copy Assignment Operator
//
// Parameters:  rcObj - the object to copy
//
// Returned:    None
//***************************************************************************
Example& Example::operator=(const Example &rcObj) {
	mpInt = nullptr;
	if (nullptr != rcObj.mpInt) {
		mpInt = new int;
		*mpInt = *rcObj.mpInt;
	}
	std::cout << "op=() : " << mID << " = " << rcObj.mID << "\n";
	return *this;
}

//***************************************************************************
// Method: 			operator<<
//
// Description: insertion operator
//
// Parameters:  rcOut - the stream to write to
//							rcObj - the object to write
//
// Returned:    the stream that was written to
//***************************************************************************
std::ostream& operator<<(std::ostream& rcOut, const Example &rcObj)
{
	rcOut << "Example: ";
	if (nullptr != rcObj.mpInt) {
		rcOut << *rcObj.mpInt;
	} else {
		rcOut << "nullptr";
	}
	rcOut << std::endl;
	return rcOut;
}