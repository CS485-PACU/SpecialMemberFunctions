//***************************************************************************
// File name:   Comp.h
// Author:      
// Date:        1/6/2025
// Class:       CS 485
// Assignment:  
// Purpose:     Demonstrate special member functions & composition
//***************************************************************************

#pragma once
#include <iostream>
#include "Example.h"

class Comp {
	public:

		// default ctor
		Comp();

		// overloaded ctor
		Comp(int value);

		// cctor (copy constructor)
		Comp(const Comp &rcObj);

		// dtor
		~Comp();

		// copy assignment operator
		Comp& operator=(const Comp &rcObj);

		friend std::ostream& operator<<(std::ostream& rcOut, const Comp &rcObj);

	private:
		Example mcEx;
		int mID;
		static int counter;
};