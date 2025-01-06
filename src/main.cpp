//***************************************************************************
// File name:   main.cpp
// Author:      chadd williams
// Date:        1/6/2025
// Class:       CS 485
// Assignment:  
// Purpose:     demonstrate special member functions
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include "../include/Example.h"

//***************************************************************************
// Function:    passByValue
//
// Description: demonstrate pass by value
//
// Parameters:  cExParam - pass by value object
//
// Returned:    None
//***************************************************************************
void passByValue(Example cExParam) {
	std::cout << "passByValue\n";
	std::cout << cExParam;
}

//***************************************************************************
// Function:    passByReference
//
// Description: demonstrate pass by reference
//
// Parameters:  rcExParam - pass by reference object
//
// Returned:    None
//***************************************************************************
void passByReference(Example &rcExParam) {
	std::cout << "passByReference\n";
	std::cout << rcExParam;
}

//***************************************************************************
// Function:    returnExample
//
// Description: demonstrate returning a copy
//
// Parameters:  None
//
// Returned:    a copy of local object
//***************************************************************************
Example returnExample() {
	Example cERetVal(485);
	std::cout << "returnExample\n";
	return cERetVal;
}

//***************************************************************************
// Function:    main
//
// Description: Explore special member functions!
//
// Parameters:  none
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main()
{
	Example cE1;
	std::cout << "--------------\n";

	Example cE2 (2);
	std::cout << "--------------\n";

	Example cE3 {cE2};
	std::cout << "--------------\n";
	Example cE4 = cE3;

	std::cout << "--------------\n";
	cE1 = cE4;
	std::cout << "--------------\n";
	
	passByValue(cE2);
  std::cout << "--------------\n";
	
	passByReference(cE3);
	std::cout << "--------------\n";
	
	cE1 = returnExample();
  std::cout << "--------------\n";

	cE2 = returnExample();
	passByValue(cE2);
	std::cout << "--------------\n";

	passByValue(returnExample());
	std::cout << "--------------\n";

}
