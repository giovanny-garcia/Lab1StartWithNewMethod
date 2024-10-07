/*	Giovanny Garcia
	10/06/2024
	Lab 1

	This program uses the ArrayBag class and stored a collection of entries.
	
	This program will accept user input and will execute a few actions on the stored
	data variables.

	A few options include: Add, Remove, Display, Find Smallest, and Find Largest.


*/
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

	//Calls a function that handles the menu
	menu(bag);

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
	int selection; // Integer to store selection.
	do // Loops through switch case.
	{
		displayMenu(); //A function to handle the display menu graphics.
		std::cin >> selection;
		switch (selection)
		{
		case 1: //Add a value
			int addValue;	//Stores potential value.
			std::cout << "\nEnter value to be added: ";
			std::cin >> addValue;
			if (bag.contains(addValue))	//checks if value already exists
			{
				std::cout << "Value already exists! Try adding different value.\n\n";
				break;
			}
			bag.add(addValue);
			cout << "\nAdding value... " << addValue << "\n\n";
			break;

		case 2: // Remove a value
			int removeValue;	//Stores potential value.
			cout << "\nEnter value to be removed: ";
			cin >> removeValue;
			if (!bag.contains(removeValue))
			{
				std::cout << "Value does not exist here.\n\n";
			}
			bag.remove(removeValue);
			cout << "Removing value... " << removeValue << endl;
			break;
		case 3: // displays bag contents
		{
			std::vector<int> bagContents = bag.toVector();
			for (std::size_t i = 0; i < bagContents.size(); i++)
			{
				std::cout << "[" << bagContents[i] << "] ";
			}
			cout << endl;
		}
		break;
		case 4: // finds smallest value.
			std::cout << "Smallest entry is: " << bag.findSmallest() << endl;
			break;
		case 5: // finds largest value.
			std::cout << "Largest entry is: " << bag.findLargest() << endl;
			break;
		case 6: //Quits program.
			std::cout << "Thank you for using my program!";
			break;
		default:
			std::cout << "Invalid Entry. Please try again";
			break;
		}
	} while (selection != 6);
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
		 << "=====================\n"
		 << "Enter your choice: ";
}