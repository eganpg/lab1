#include <iostream>
#include <string>
#include "ArrayBag.h"

using namespace std;


void bagTester(ArrayBag<int>& bag);
void bubbleSort(ArrayBag<int>& bag);
void binarySearchIterative(ArrayBag<int>& bag);
void binarySearchRecursive(ArrayBag<int>& bag);

int main()
{
	// Array bag to hold integers
	ArrayBag<int> bag;
	// Array to hold initial values to put into the bag
	int initialValues[] = {1, 33, 6, 9, 2, 65, 4, 29, 5, 8, 39, 88, 7, 25, 51, 3, 99, 14, 11, 10};
	
	// // Add the initial values to the bag - user notification
	// // cout << "Adding positive integers to the bag: " << endl;
	for (int i = 0; i < 20; i++)
	{
		// show each item being added to the user
		// cout << "The value being added to the bag is: " << initialValues[i] << endl;
		// add the number to the bag
		bag.add(initialValues[i]);
	}  // end for

	int choice, value;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display the contents of the bag\n";
        std::cout << "2. Add a value to the bag\n";
        std::cout << "3. Remove a value from the bag\n";
        std::cout << "4. Sort the bag\n";
        std::cout << "5. Search for a value in the bag\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: { // Display contents
                auto vec = bag.toVector();
                std::cout << "Bag contents: ";
                for (int item : vec) {
                    std::cout << item << " ";
                }
                std::cout << "\n";
                break;
            }
            case 2: { // Add value
                std::cout << "Enter a value to add: ";
                if (std::cin >> value) {
                    // Input was successfully converted to an int
                    if (bag.contains(value))
                    {
                        std::cout << "This value already exists. Please choose another value.\n";
                    } else {
                        bag.add(value);
                        std::cout << "You added the integer: " << value << std::endl;
                    } 
                } else {
                    // Input could not be converted to an int
                    std::cout << "That's not an integer!" << std::endl;

                    // Clear the error state of cin
                    std::cin.clear();

                    // Ignore the rest of the input line to start fresh with the next input
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                // std::cin >> value;
                // std::cout << "The value is: " << value << "\n";
                // Add code to check for duplicates
                
                // add an else if statement that determines that the value is an int
                break;
            }
            case 3: { // Remove value
                std::cout << "Enter a value to remove: ";
                // std::cin >> value;
                if (std::cin >> value) {
                    // Input was confirmed as an int
                    if (bag.remove(value)) {
                        std::cout << "Value removed.\n";
                    } else {
                        std::cout << "Value not found.\n";
                    }
                } else {
                    // Input could not be converted to an int
                    std::cout << "That's not an integer!" << std::endl;

                    // Clear the error state of cin
                    std::cin.clear();

                    // Ignore the rest of the input line to start fresh with the next input
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                    
                break;
            }
            case 4: { // Sort bag
                bag.bubbleSort();
                std::cout << "Bag sorted.\n";
                break;
            }
            case 5: { // Search for a value
                std::cout << "Enter a value to search for: ";
                std::cin >> value;
                std::cout << "Choose search method (1-Iterative, 2-Recursive): ";
                int method;
                std::cin >> method;

                //determine if the array has been sorted
                // bool sorted = isSortedAscending(); 
                auto vec = bag.toVector();
                for (int i = 0; i < 20 - 1; ++i) {
                    if (vec[i] > vec[i + 1]) {

                        std::cout << "This array must be sorted prior to searching, please select option 4 and retry. \n";
                        break; // Found an element that is greater than the next one
                        
                    }
                }
                // return true; // No elements are out of order; the array is sorted in ascending order
                bool found = false;
                if (method == 1) {
                    
                    found = bag.binarySearchIterative(value);
                    
                    // bag.bubbleSort(); // Ensure the bag is sorted
                    
                } else if (method == 2) {
                    bag.bubbleSort(); // Ensure the bag is sorted for recursive search
                    found = bag.binarySearchRecursive(value);
                }
                if (found) {
                    std::cout << "Value found.\n";
                } else {
                    std::cout << "Value not found.\n";
                }
                break;
            }
            case 6: // Exit
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid number.\n";
        }
    } while (choice != 6);

    return 0;
	
	// Call a funciton that exercises
	// some of the bag methods
	// bagTester(bag);
	
	// Invoking the new method
	// added as an example

	
	// cout << "before do something with the bag" << endl;
	// bag.doSomething();

	// bubbleSort(bag); 

	// binarySearchIterative(bag);

	// binarySearchRecursive(bag);

   return 0;
   
}  // end main

// template <typename T, size_t N>
// bool isSortedAscending(const T(&array)[N]) {
    
// }


void bubbleSort(ArrayBag<int>& bag)
{
	int size = bag.getCurrentSize();
	cout << size << endl;

	cout << "Go to bubble sort method in arraybag.cpp" << endl;
	bag.bubbleSort();
	
	int sizeAfter = bag.getCurrentSize();
	cout << sizeAfter << endl;

    cout << "Here is the sorted version:" << endl;
    for(int i = 0; i < size; i++) {
        // Assuming bag[i] or a similar method is available to access elements
        // cout << bag[i] << " ";
    }
    cout << endl;
	// cout << "here is the sorted version" << endl;
}

void binarySearchIterative(ArrayBag<int>& bag)
{
	 if (bag.binarySearchIterative(4)) {
        cout << "4 found (iterative)." << endl;
    }
}

void binarySearchRecursive(ArrayBag<int>& bag)
{
	 if (bag.binarySearchRecursive(5)) {
        cout << "4 found (recursive)." << endl;
    }
}

void bagTester(ArrayBag<int>& bag)
{
	// Show that the bag is not current empty - returns bool from isEmpty
	cout << "The bag is not empty; isEmpty: returns " << bag.isEmpty() << endl;

	//Show the size of the bag
	cout << "Show the size of the bag " << bag.getCurrentSize() << endl;

	// Warms the user that the bag is about to be cleared
	cout << "About to clear the bag, ";
	// calls clear - this removes all items from the bag
	bag.clear();
   // show proof that the bag is empty - bool
	cout << "isEmpty: returns " << bag.isEmpty() << endl;
}  // end bagTester



