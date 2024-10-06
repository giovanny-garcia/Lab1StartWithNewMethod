#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

void sampleProgramFunction(ArrayBag<int> &bag);
void menu();
void displayMenu();

int main()
{
	// Array bag to hold integers
	ArrayBag<int> bag;

	//Integer to store selection
	int selection;

	// Array to hold initial values to put into the bag
	int initialValues[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};

	// Add the initial values to the bag
	cout << "Adding positive integers to the bag: " << endl;
	for (int i = 0; i < 20; i++)
	{
		bag.add(initialValues[i]);
	} // end for

	// Call a funciton that exercises
	// some of the bag methods
	sampleProgramFunction(bag);

	
	displayMenu();
	do
	{
		switch (selection)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			break;
		}
	}while(selection != 6);

	menu();
	// Invoking the new method
	// added as an example

	return 0;

} // end main

/****************************************************************/
/* Function:   sampleProgramFunction
/* Inputs:     the array bag
/* Outputs:    none
/* Purpose:    This function exercises some of the bag methods
/****************************************************************/

void sampleProgramFunction(ArrayBag<int> &bag)
{
	cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

	cout << "About to clear the bag, ";
	bag.clear();

	cout << "isEmpty: returns " << bag.isEmpty() << endl;
} // end bagTester

void menu()
{

}

void displayMenu()
{
	cout << "=====================\n"
	<< "1.) Add a value\n"
	<< "2.) Remove a value\n"
	<< "3.) Display bag contents\n"
	<< "4.) Find smallest value\n"
	<< "5.) Find largest value\n"
	<< "6.) Quit\n"
	<< "Enter your choice: ";
}