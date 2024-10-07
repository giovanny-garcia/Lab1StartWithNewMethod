#include "ArrayBag.h"
#include <iostream>
#include <cstddef>

// *** Add new method code to the ADT implementation file
template <class ItemType>
ArrayBag<ItemType>::ArrayBag() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
} // end default constructor

template <class ItemType>
int ArrayBag<ItemType>::getCurrentSize() const
{
   return itemCount;
} // end getCurrentSize

template <class ItemType>
bool ArrayBag<ItemType>::isEmpty() const
{
   return itemCount == 0;
} // end isEmpty

template <class ItemType>
bool ArrayBag<ItemType>::add(const ItemType &newEntry)
{
   bool hasRoomToAdd = (itemCount < maxItems);
   if (hasRoomToAdd)
   {
      items[itemCount] = newEntry;
      itemCount++;
   } // end if

   return hasRoomToAdd;
} // end add

template <class ItemType>
bool ArrayBag<ItemType>::remove(const ItemType &anEntry)
{
   int locatedIndex = getIndexOf(anEntry);
   bool canRemoveItem = !isEmpty() && (locatedIndex > -1);
   if (canRemoveItem)
   {
      itemCount--;
      items[locatedIndex] = items[itemCount];
   } // end if

   return canRemoveItem;
} // end remove

template <class ItemType>
void ArrayBag<ItemType>::clear()
{
   itemCount = 0;
} // end clear

template <class ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType &anEntry) const
{
   int frequency = 0;
   int curIndex = 0; // Current array index
   while (curIndex < itemCount)
   {
      if (items[curIndex] == anEntry)
      {
         frequency++;
      } // end if

      curIndex++; // Increment to next entry
   } // end while

   return frequency;
} // end getFrequencyOf

template <class ItemType>
bool ArrayBag<ItemType>::contains(const ItemType &anEntry) const
{
   return getIndexOf(anEntry) > -1;
} // end contains

template <class ItemType>
ItemType ArrayBag<ItemType>::findSmallest() const
{
   if (itemCount == 0) //checks for the amount of entries
   {
      std::cout << " Bag is empty. Try adding a value.\n";
   }
   ItemType smallestValue = toVector()[0]; //assumes the first entry is the smallest.

   for (int i = 1; i < itemCount; i++) //loops for each entry
   {
      if (toVector()[i] < smallestValue)  
      {                                   //if current index is smaller than the saved value
         smallestValue = items[i];        //it is saved instead.
      }
   }
   return smallestValue;            //returns value
}

template <class ItemType>
ItemType ArrayBag<ItemType>::findLargest() const
{
   if (itemCount == 0)  //checks for the amount of entries
   {
      std::cout << " Bag is empty. Try adding a value.\n";
   }
   ItemType largestValue = items[0]; //assumes the first entry is the largest.

   for (int i = 1; i < itemCount; i++) //loops for each entry
   {
      if (items[i] > largestValue)     
      {                                //if current index is smaller than the saved value
         largestValue = items[i];      //index value is saved instead.
      }
   }
   return largestValue;       //returns value
}
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

template <class ItemType>
std::vector<ItemType> ArrayBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   for (int i = 0; i < itemCount; i++)
      bagContents.push_back(items[i]);

   return bagContents;
} // end toVector

// private
template <class ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType &target) const
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
      } // end if
   } // end while

   return result;
} // end getIndexOf
