#include "ArrayBag.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstddef>

// *** Add new method code to the ADT implementation file

// Model method to base other lab implementations
template<class ItemType>
void ArrayBag<ItemType>::doSomething()
{
	std::cout << "This is the demo - code to come to follow lab instructions. Leave this for demo purposes - remove before submission\n";
   std::cout << "doing something again here\n";
}  // end doSomething

// Model method to base other lab implementations
template<class ItemType>
void ArrayBag<ItemType>::bubbleSort()
{
	std::cout << "Bubble Sort\n";
   bool swapped = true;
        while (swapped) {
            swapped = false;
            for (int i = 0; i < itemCount - 1; i++) {
                if (items[i] > items[i + 1]) {
                    std::swap(items[i], items[i + 1]);
                    swapped = true;
                }
            }
        }
   
   
}  // end doSomething
template<class ItemType>
bool ArrayBag<ItemType>::binarySearchIterative(const ItemType& target)
{
   std::cout << "Binary Search Iterative " << target << "\n";
   int low = 0;
        int high = itemCount - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (items[mid] == target) {
               std::cout << "Found it!!! \n";
                return true;
            } else if (items[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
}
template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursive(const ItemType& target) 
{
   return binarySearchRecursiveHelper(target, 0, itemCount - 1);
}

template<class ItemType>
bool ArrayBag<ItemType>::binarySearchRecursiveHelper(const ItemType& target, int low, int high) {
        if (low > high) return false; // Base case

        int mid = low + (high - low) / 2;
        if (items[mid] == target) {
            return true;
        } else if (items[mid] < target) {
            return binarySearchRecursiveHelper(target, mid + 1, high);
        } else {
            return binarySearchRecursiveHelper(target, low, mid - 1);
        }
    }

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

