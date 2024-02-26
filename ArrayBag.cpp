#include "ArrayBag.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef>

// *** Add new method code to the ADT implementation file

// Bubble sort based on example model method
template<class ItemType>
void ArrayBag<ItemType>::bubbleSort()
{
   // For debugging purposes send notification to console that bubble sort has been successfully called
	// std::cout << "Bubble Sort\n";
   // set true
   bool swapped = true;
      // for as long as swapped is true
      while (swapped) {
         // temporarily set to false
         swapped = false;
         // iterate over the array - itemCount - 1 accounts for array beginning with 0 not 1
         for (int i = 0; i < itemCount - 1; i++) {
            // if the program looks at an item in the array then looks at the next and finds it to be smaller...
            if (items[i] > items[i + 1]) {
               // swap the two number
               std::swap(items[i], items[i + 1]);
               // continue the while loop until the array is ordered in ascending order
               // when the numbers are in ascending order swapped will remain false and the loop will end
               swapped = true;
            }
         }
      }
   
   
}  
template<class ItemType>
bool ArrayBag<ItemType>::binarySearchIterative(const ItemType& target)
{
   // debugging step: let the user know binary search has been called and present the search target
   // std::cout << "Binary Search Iterative " << target << "\n";
   // initialize low as 0
   int low = 0;
   // initialize high to the last index of the array
   int high = itemCount - 1;
   // continue to the loop as long as low is less or equal to high
   while (low <= high) {
      // calculate middle index
      int mid = low + (high - low) / 2;
      // if middle index is equal to the target it was found
      if (items[mid] == target) {
         std::cout << "Found it!!! \n";
            return true;
      } else if (items[mid] < target) { // if the item at middle index is less
            low = mid + 1; // adjust the low to search the upper half of the range
      } else { // if the item at the middle is greater than the target
            high = mid - 1; // adjust the high to search the lower half of the range
      }
   }
   return false;
}

template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursive(const ItemType& target) 
{
   // Calls a helper function to perform the binary search recursively
   // Passes the target item to find, the starting index (0), and the ending index (itemCount - 1) as parameters
   return binarySearchRecursiveHelper(target, 0, itemCount - 1);
}


template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursiveHelper(const ItemType& target, int low, int high) {
   // Base case: If the 'low' index is greater than the 'high' index, the target is not found within the range
   if (low > high) return false;

   // Calculate the middle index of the current search range to potentially divide the search area in half
   int mid = low + (high - low) / 2;
   
   // If the item at the middle index matches the target, return true to indicate the target has been found
   if (items[mid] == target) {
      return true;
   } else if (items[mid] < target) { // If the item at the middle index is less than the target
      
      // Recursively search the upper half of the current range by setting 'low' to 'mid + 1'
      return binarySearchRecursiveHelper(target, mid + 1, high);
   } else { // If the item at the middle index is greater than the target
      
      // Recursively search the lower half of the current range by setting 'high' to 'mid - 1'
      return binarySearchRecursiveHelper(target, low, mid - 1);
   }
}

// Stock Code do not adjust below


template<class ItemType>
ArrayBag<ItemType>::ArrayBag(): itemCount(0), maxItems(DEFAULT_CAPACITY)
{
}  // end default constructor

template<class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
bool ArrayBag<ItemType>::add(const ItemType& newEntry)
{
	bool hasRoomToAdd = (itemCount < maxItems);
	if (hasRoomToAdd)
	{
		items[itemCount] = newEntry;
		itemCount++;
	}  // end if
    
	return hasRoomToAdd;
}  // end add

template<class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType& anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
	bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
	if (canRemoveItem)
	{
		itemCount--;
		items[locatedIndex] = items[itemCount];
	}  // end if
    
	return canRemoveItem;
}  // end remove

template<class ItemType>
void ArrayBag<ItemType>::clear()
{
	itemCount = 0;
}  // end clear

template<class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
   int frequency = 0;
   int curIndex = 0;       // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      }  // end if
      
      curIndex++;          // Increment to next entry
   }  // end while
   
   return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
	return getIndexOf(anEntry) > -1;
}  // end contains

/* ALTERNATE 1: First version
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& target) const 
{
   return getFrequencyOf(target) > 0;
}  // end contains

// ALTERNATE 2: Second version 
template<class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   int curIndex = 0;        // Current array index
   while (!found && (curIndex < itemCount))
   {
      if (anEntry == items[curIndex])
      {
         found = true;
      } // end if
      
      curIndex++;           // Increment to next entry
   }  // end while   
   
   return found;
}  // end contains
*/

template<class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
	for (int i = 0; i < itemCount; i++)
		bagContents.push_back(items[i]);
      
   return bagContents;
}  // end toVector

// private
template<class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const
{
	bool found = false;
   int result = -1;
   int searchIndex = 0;
   
   // If the bag is empty, itemCount is zero, so loop is skipped
   while (!found && (searchIndex < itemCount))
   {
      if (items[searchIndex] == target)
      {
         found = true;
         result = searchIndex;
      } 
      else
      {
         searchIndex++;
      }  // end if
   }  // end while
   
   return result;
}  // end getIndexOf

