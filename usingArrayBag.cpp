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
	
    // Loop to add each item to the bag
    for (int i = 0; i < 20; i++)
	{
		// show each item being added to the user
		// cout << "The value being added to the bag is: " << initialValues[i] << endl;
		// add the number to the bag
		bag.add(initialValues[i]);
	}  // end for

    // Define menu choice and the associated input value
	int choice, value;

    // Present the menu and take an input
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


        // Process the input via switch
        switch (choice) {
            // Show the bag contents as a vector
            case 1: { 
                auto vec = bag.toVector();
                std::cout << "Bag contents: ";
                for (int item : vec) {
                    std::cout << item << " ";
                }
                std::cout << "\n";
                break;
            }
            // Allow the user to add a value; check each input to ensure it is not a duplicate
            case 2: {
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
                    // if the input is not an int
                    std::cout << "That's not an integer!" << std::endl;

                    // Clear the error state of cin
                    std::cin.clear();

                    // Ignore the rest of the input line to start fresh with the next input
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                // std::cin >> value;
                // std::cout << "The value is: " << value << "\n";
               
                break;
            }

            // User can enter a value to remove
            case 3: { 
                std::cout << "Enter a value to remove: ";
                // confirm value is an int
                if (std::cin >> value) {
                    // Input was confirmed as an int
                    if (bag.remove(value)) {
                        std::cout << "Value removed.\n";
                    } else {
                        std::cout << "Value not found.\n";
                    }
                } else {
                    // Message if input is not an int; do nothing 
                    std::cout << "That's not an integer!" << std::endl;

                    // Clear the error state of cin
                    std::cin.clear();

                    // Ignore the rest of the input line to start fresh with the next input
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                    
                break;
            }

            // call bubble sort and present confirmation message upon sorting
            case 4: { 
                bag.bubbleSort();
                std::cout << "Bag sorted.\n";
                break;
            }

            // User can search by iterative or recursive depending on selection
            case 5: { 
                std::cout << "Enter a value to search for: ";
                std::cin >> value;
                std::cout << "Choose search method (1-Iterative, 2-Recursive): ";
                int method;
                bool needSort;
                std::cin >> method;

                //determine if the array has been sorted
                
                needSort = false;

                // Convert the bag to a vector
                auto vec = bag.toVector();
                // Check if it is in order
                for (int i = 0; i < 20 - 1; ++i) {
                    if (vec[i] > vec[i + 1]) {
                        // if program finds any int not in ascending order, prompt user to sort then retry
                        std::cout << "This array must be sorted prior to searching, please select option 4 and retry. \n";
                        needSort = true;
                        break; // Found an element that is greater than the next one
                        
                    }
                }
                // return true; // No elements are out of order; the array is sorted in ascending order
                bool found = false;

                // if the user chooses iterative and the vector does not need to be sorted
                if (method == 1 && needSort == false) {
                    
                    // call iterative search and sent the variable found to the result
                    found = bag.binarySearchIterative(value);
                    
                } else if (method == 2 && needSort == false) { // if the user chooses 2 and vector does not need to be sorted
                    
                    // call recursive search and set found to the result
                    found = bag.binarySearchRecursive(value);
                }
                // if the value was found notify the user
                if (found) {
                    std::cout << "Value has been found.\n";
                } else { // otherwise tell the user the value cannot be found
                    std::cout << "Value cannot be found.\n";
                }
                break;
            }

            // allow user to exit
            case 6: // Exit
                std::cout << "Exiting...\n";
                break;

            // User cannot select other value notify them
            default:
                std::cout << "Invalid choice. Please enter a valid number.\n";
        }
    } while (choice != 6);

    return 0;
	
	
	
	// Invoking the new method
	// added as an example

	
	// cout << "before do something with the bag" << endl;

    // Call a funciton that exercises
	// some of the bag methods
	// bagTester(bag);


	// bubbleSort(bag); 

	// binarySearchIterative(bag);

	// binarySearchRecursive(bag);

   return 0;
   
}  // end main 



// This is stock code provided in the file
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



