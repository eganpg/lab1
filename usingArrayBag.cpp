#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;


void bagTester(ArrayBag<int>& bag);

int main()
{
	// Array bag to hold integers
	ArrayBag<int> bag;
	// Array to hold initial values to put into the bag
	int initialValues[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
	
	// Add the initial values to the bag - user notification
	cout << "Adding positive integers to the bag: " << endl;
	for (int i = 0; i < 20; i++)
	{
		// show each item being added to the user
		cout << "The value being added to the bag is: " << initialValues[i] << endl;
		// add the number to the bag
		bag.add(initialValues[i]);
	}  // end for
	
	// Call a funciton that exercises
	// some of the bag methods
	bagTester(bag);
	
	// Invoking the new method
	// added as an example
	cout << "before do something with the bag" << endl;
	bag.doSomething();

   return 0;
   
}  // end main



void bagTester(ArrayBag<int>& bag)
{
	// Show that the bag is not current empty - returns bool from isEmpty
	cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

	// Warms the user that the bag is about to be cleared
	cout << "About to clear the bag, ";
	// calls clear - this removes all items from the bag
	bag.clear();
   // show proof that the bag is empty - bool
	cout << "isEmpty: returns " << bag.isEmpty() << endl;
}  // end bagTester



