#ifndef ARRAY_BAG_
#define ARRAY_BAG_

#include "BagInterface.h"

template<class ItemType>
class ArrayBag : public BagInterface<ItemType>
{
private:
	static const int DEFAULT_CAPACITY = 30; // Small size to test for a full bag
	ItemType items[DEFAULT_CAPACITY];      // Array of bag items
	int itemCount;                         // Current count of bag items 
	int maxItems;                          // Max capacity of the bag
   
	// Returns either the index of the element in the array items that
	// contains the given target or -1, if the array does not contain 
	// the target.
	int getIndexOf(const ItemType& target) const;   
	// Helper method to support binarySearchRecur
	bool binarySearchRecursiveHelper(const ItemType& target, int low, int high);

public:
	ArrayBag();

	// Instructions from Blackboard as comments for readability

	// bubbleSort - a method to sort the array in ascending order using the bubble sort
	void bubbleSort(); 
	// a repetitive version of the binary search
	bool binarySearchIterative(const ItemType& target); 
	// a recursive version of the binary search (You should use a helper method that calls 
	//the recursive method so the client code does not have to provide the extra parameters. 
	// Client calls to both of the search methods should be identical other than the method name.)
	bool binarySearchRecursive(const ItemType& target); 
	 

	int getCurrentSize() const;
	bool isEmpty() const;
	bool add(const ItemType& newEntry);
	bool remove(const ItemType& anEntry);
	void clear();
	bool contains(const ItemType& anEntry) const;
	int getFrequencyOf(const ItemType& anEntry) const;
   std::vector<ItemType> toVector() const;
}; // end ArrayBag

#include "ArrayBag.cpp"
#endif
