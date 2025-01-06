//***************************************************************************
// File name:   Comp.cpp
// Author:      
// Date:        1/6/2025
// Class:       CS 485
// Assignment:  
// Purpose:     Demonstrate special member functions
//***************************************************************************

#include "../include/Comp.h"
#include <iostream>

int Comp::counter = 0;

//***************************************************************************
// Constructor:  Comp
//
// Description: Create object
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Comp::Comp() {
	mID = counter++;
	std::cout << "Comp::ctor() : " << mID << "\n";
}

//***************************************************************************
// Constructor: Comp
//
// Description: Create object
//
// Parameters:  value - value to store in object
//
// Returned:    None
//***************************************************************************
Comp::Comp(int value) : mcEx(value) {
	mID = counter++;
	std::cout << "Comp::ctor(int) : " << mID << "\n";
}

//***************************************************************************
// Constructor: Comp
//
// Description: Copy Constructor
//
// Parameters:  rcObj - the object to copy
//
// Returned:    None
//***************************************************************************
Comp::Comp(const Comp &rcObj) : mcEx(rcObj.mcEx) {
	mID = counter++;
	std::cout << "Comp::cctor() : " << mID << "\n";
}

//***************************************************************************
// Destructor: Comp
//
// Description: Destroy object, free memory
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
Comp::~Comp() {
	std::cout << "Comp::dtor() : " << mID << "\n";
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
Comp& Comp::operator=(const Comp &rcObj) {
	mcEx = rcObj.mcEx;
	std::cout << "Comp::op=() : " << mID << " = " << rcObj.mID << "\n";
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
std::ostream& operator<<(std::ostream& rcOut, const Comp &rcObj)
{
	rcOut << "Comp: ";
	rcOut << rcObj.mcEx;
	rcOut << std::endl;
	return rcOut;
}