#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;

void sampleProgramFunction(ArrayBag<int> &bag);
void menu(ArrayBag<int> &bag);
void displayMenu();

int main()
{
	// Array bag to hold integers
	ArrayBag<int> bag;

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


	menu(bag);
	// Invoking the new method
	// added as an example

	return 0;

} // end main

/* 
Function:   sampleProgramFunction
Inputs:     the array bag
Outputs:    none
Purpose:    This function exercises some of the bag methods
*/

void sampleProgramFunction(ArrayBag<int> &bag)
{
	cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

	cout << "About to clear the bag, ";
	bag.clear();

	cout << "isEmpty: returns " << bag.isEmpty() << endl;
} // end bagTester

void menu(ArrayBag<int> &bag)
{
	int selection;	//Integer to store selection

	do				//Loops through 
	{
		displayMenu();
		std::cin >> selection;
		switch (selection)
		{
		case 1:
			int addValue;
			cout << "Enter value: \n";
			cin >> addValue;
			bag.add(addValue);
			cout << "Adding value " << addValue << endl;
			break;
			
		case 2:
			int removeValue;
			cout << "Enter value to be removed: \n";
			cin >> removeValue;
			bag.remove(removeValue);
			cout << "Removing value " << removeValue << endl;
			break;
		case 3:
		{
			std::vector<int> bagContents = bag.toVector();
				for (std::size_t i = 0; i < bagContents.size(); i++) 
				{
        		std::cout << bagContents[i] << " ";
				}
		}
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
	<< "Enter your choice: \n";
}