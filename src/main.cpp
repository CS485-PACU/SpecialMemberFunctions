//***************************************************************************
// File name:   main.cpp
// Author:      
// Date:        
// Class:       
// Assignment:  
// Purpose:     
//***************************************************************************

#include <iostream>
#include <vector> 
#include <string>
#include <sstream>
#include "../include/Example.h"


void passByValue(Example cExParam) {
	std::cout << "passByValue\n";
	std::cout << cExParam;
}

void passByReference(Example &rcExParam) {
	std::cout << "passByReference\n";
	std::cout << rcExParam;
}

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
