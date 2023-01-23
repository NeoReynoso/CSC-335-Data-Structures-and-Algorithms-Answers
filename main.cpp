//
//  main.cpp
//  CSC 335 Homework Answers
//
//  Created by Ivan Reynoso on 1/23/23.
//



#include <iostream>

#include <ctime>

#include <vector>

using namespace std;

//Insertion sort

template<typename T>

void insertionSort(vector<T>& l)

{

       for (int i = 1; i < l.size(); i++)

       {

              int j = i;

              while (j > 0 && (l[j] < l[j - 1]))

              {

                     T temp = l[j];

                     l[j] = l[j - 1];

                     l[j - 1] = temp;

                     j--; // move index j back

              }

       }

}

//partition list

template <typename T>

int partition(vector<T>& l, int i, int k)

{

       bool done = false;

       int midpoint = i + (k - i) / 2; //Pick middle value as pivot

       T pivot = l[midpoint];

       int low = i; //

       int high = k;

       while (!done) {

              while (l[low] < pivot) ++low; /* Increment low while l[l] < pivot */

              while (pivot < l[high]) --high; /* Decrement high while pivot < l[h] */

              if (low >= high)

                     done = true;

              else

              {

                     T temp = l[low];

                     l[low] = l[high];

                     l[high] = temp;

                     ++low; --high;

              }

       }

       return high;

}

template <typename T>

void Quicksort(vector<T>& l, int i, int k)

{

       int j = 0;

       if (i >= k) //Base case: If 1 or zero elements,

              return; //partition is already sorted

              /* Partition the array.

              Value j is the location of last

              element in low partition. */

       j = partition(l, i, k);

       /* Recursively sort low and high

       partitions */

       Quicksort(l, i, j);

       Quicksort(l, j + 1, k);

}

//============================= Merge function merges two sorted lists

template<typename T>

void merge(vector<T>& l, int i, int j, int k) {

       // Create temporary array mergedNumbers

       // Initialize position variables

       vector<T> mergedNumbers(k - i + 1);

       int leftPos = i;

       int rightPos = j + 1;

       // Add smallest element to merged numbers

       int mergePos = 0;

       while (leftPos <= j && rightPos <= k)

       {

              if (l[leftPos] <= l[rightPos])

              {

                     mergedNumbers[mergePos] = l[leftPos];

                     ++leftPos;

              }

              else

              {

                     mergedNumbers[mergePos] = l[rightPos];

                     ++rightPos;

              }

              ++mergePos;

       }

       // If left partition not empty, add remaining elements

       while (leftPos <= j)

       {

              mergedNumbers[mergePos] = l[leftPos];

              ++leftPos;

              ++mergePos;

       }

       // If right partition not empty, add remaining elements

       while (rightPos <= k)

       {

              mergedNumbers[mergePos] = l[rightPos];

              ++rightPos;

              ++mergePos;

       }

       // Copy merge number back to numbers

       for (mergePos = 0; mergePos < mergedNumbers.size(); ++mergePos)

       {

              l[i + mergePos] = mergedNumbers[mergePos];

       }

}

//merge sort function

template<typename T>

void mergeSort(vector<T>& l, int i, int k)

{

       int j = 0;

       if (i < k)

       {

              j = (i + k) / 2; // Find the midpoint in the partition

              // Recursively sort left and right partitions

              mergeSort(l, i, j);

              mergeSort(l, j + 1, k);

              // Merge left and right partition in sorted order

              merge(l, i, j, k);

       }

}

int main()

{

       vector<int> vInsert;

       clock_t tInsert, tMerge, tQuick;

       int listSize = 1000; // start with initial size of 1000 integers

       while (listSize <= 450000) // use max listlist of 450000

       {

              for (int i = 0; i < listSize; i++)

                     vInsert.push_back(rand() % listSize * 5); // generate the list

              vector<int> vMergeSort = vInsert; // copy the list over to

              vector<int> vQuickSort = vInsert;

              if (listSize <= 10000) // do not include insertion sort over n =10000

              {

                     tInsert = clock();

                     insertionSort(vInsert);

                     tInsert = clock() - tInsert;

                     cout << "List Size = " << listSize << " Time taken by the Insertion Sort: "

                           << (double)tInsert / CLOCKS_PER_SEC << endl;

              }

              tMerge = clock();

              mergeSort(vMergeSort, 0, vMergeSort.size() - 1);

              tMerge = clock() - tMerge;

              cout << "List Size = " << listSize << " Time taken by the Merge Sort: " <<

                     (double)tMerge / CLOCKS_PER_SEC << endl;

              tQuick = clock();

              Quicksort(vQuickSort, 0, vQuickSort.size() - 1);

              tQuick = clock() - tQuick;

              cout << "List Size = " << listSize << " Time taken by the QuickSort: " <<

                     (double)tQuick / CLOCKS_PER_SEC << endl;

              if (listSize < 10000)

                     listSize += 3000;

              else

                     listSize += 50000;

              cout << "===========================\n";

       }

       system("pause");

       return 0;

}
