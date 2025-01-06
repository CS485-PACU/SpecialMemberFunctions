//***************************************************************************
// File name:   compMain.cpp
// Author:      chadd williams
// Date:        1/6/2025
// Class:       CS 485
// Assignment:  
// Purpose:     demonstrate special member functions & composition
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include "../include/Comp.h"

//***************************************************************************
// Function:    passByValue
//
// Description: demonstrate pass by value
//
// Parameters:  cExParam - pass by value object
//
// Returned:    None
//***************************************************************************
void passByValue(Comp cExParam) {
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
void passByReference(Comp &rcExParam) {
	std::cout << "passByReference\n";
	std::cout << rcExParam;
}

//***************************************************************************
// Function:    returnComp
//
// Description: demonstrate returning a copy
//
// Parameters:  None
//
// Returned:    a copy of local object
//***************************************************************************
Comp returnComp() {
	Comp cERetVal(485);
	std::cout << "returnComp\n";
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
	Comp cE1;
	std::cout << "--------------\n";

	Comp cE2 (2);
	std::cout << "--------------\n";

	Comp cE3 {cE2};
	std::cout << "--------------\n";
	Comp cE4 = cE3;

	std::cout << "--------------\n";
	cE1 = cE4;
	std::cout << "--------------\n";
	
	passByValue(cE2);
  std::cout << "--------------\n";
	
	passByReference(cE3);
	std::cout << "--------------\n";
	
	cE1 = returnComp();
  std::cout << "--------------\n";

	cE2 = returnComp();
	passByValue(cE2);
	std::cout << "--------------\n";

	passByValue(returnComp());
	std::cout << "--------------\n";

}
