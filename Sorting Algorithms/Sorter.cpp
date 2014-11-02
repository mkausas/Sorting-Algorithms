//
//  Sorter.cpp
//  Sorting Algorithms
//
//  Created by Marty Kausas on 10/27/14.
//  Copyright (c) 2014 Marty Kausas. All rights reserved.
//

#include "Sorter.h"
#include<iostream>
using namespace std;

/**
 * Insertion Sort
 * WORST CASE O(n^2) time complexity
 *
 * -- Optimal at 8-20 elements --
 * This sorting method compares to values adjacent in a list
 * and compares the values. If the value with the larger index 
 * is smaller then the values will be switched within the list. 
 * The smaller value will then compare itself to the next index 
 * value beneath it and will continue to switch until it finds
 * a value lower then its own. This process continues till the 
 * loop has finished iterating the list. 
 */
void Sorter::insertionSort(vector<int> vec) {
    printf("-- Insertion Sort --\n");
    printf("Before Sorting: ");
    printVector(vec);
    
    int swap; // temp variable used to switch temp1 and temp2 in vector
    
    // iterate through the vector and grab initial values to compare
    for (int i = 0; i < vec.size() - 1; i++) {
        // loop to work backwards from i + 1 if temp2 is smaller then temp1 and more
        for (int j = i + 1; j > i; j--) {
            if (vec[i] > vec[j]) { // temp1 is greater, should be after temp2, switch
                printf("%d > %d switching positions\n", vec[i], vec[j]);
                swap = vec[i];
                vec[i] = vec[j];
                vec[j] = swap;
                if (i > 0)
                    i--;
            }
            
            else { // temp2 is greater and in the correct place, move on
                printf("%d < %d moving on\n", vec[i], vec[j]);
                break;
            }
        }
    }
    
    printf("After Sorting: ");
    printVector(vec);
}


/**
 * Selection Sort
 * WORST CASE O(n^2) time complexity
 *
 * -- Optimal at 10-20 elements  --
 * This sorting method iterates through the entire list to find 
 * the smalles value. It then switches this values with the list's
 * 0 index value. Repeat this process until the outerloop finishes
 * iterating through the list.
 */
void Sorter::selectionSort(vector<int> vec) {
    printf("-- Selection Sort --\n");
    printf("Before Sorting: ");
    printVector(vec);
    
    int swap;
    int temp;
    int minVal;
    int minIndex;

    for (int i = 0; i < vec.size() - 1; i++) {
        temp = vec[i];
        minVal = temp;
        minIndex = i;
        for (int j = i; j < vec.size(); j++) {
            if (vec[j] < minVal) {
                minVal = vec[j];
                minIndex = j;
            }
        }
        
        swap = temp;
        vec[i] = minVal;
        vec[minIndex] = swap;
        printf("swapped %d and %d\n", minVal, swap);
    }
    
    printf("After Sorting: ");
    printVector(vec);
}

/**
 * Selection Sort
 * WORST CASE O(n^2) time complexity
 *
 * This sorting method iterates through the entire list in adjacent
 * pairs. With each inner loop iteration the two values will be 
 * compared and switched if out of place. This process is repeated 
 * until sorting is complete.
 */
void Sorter::bubbleSort(vector<int> vec) {
    printf("-- Bubble Sort --\n");
    printf("Before Sorting: ");
    printVector(vec);
    
    int swap;
    
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i; j < vec.size() - 1; j++) {
            if (vec[j] > vec[j+1]) {
                swap = vec[j];
                vec[j] = vec[j+1];
                vec[j + 1] = swap;
            }
        }
    }
    
    printf("After Sorting: ");
    printVector(vec);
}

/**
 * Shell Sort Sort
 * WORST CASE O(n^2) time complexity
 *
 * This sorting method iterates subarrays of the inputted vector.
 * It performs insertion sorts on the subarrays and decrements 
 * the number of number of subarrays it sorts through in each 
 * iteration. 
 * 
 * For example in an array of 12 objects one might start out at
 * 5 subarrays and work down from there:
 * First Pass: (a1, a6, a11), (a2, a7, a12), (a3, a8), (a4, a9), (a5, a10)
 * Second Pass: (a1, a4, a7, a10), (a2, a5, a8, a11), (a3, a6, a9, a12)
 * Third Pass: (a1, ..., a12)
 */
void Sorter::shellSort(vector<int> vec) {
    printf("-- Shell Sort --\n");
    printf("Before Sorting: ");
    printVector(vec);
    
    // optimal gaps according to wikepedia
//    int gaps[] = { 1, 4, 10, 23, 57, 132, 301, 701 };
    
    
    int gap = (int) ((5.0 / 12) * vec.size());
    int swap;
    
    // iteratate through all gap sizes
    for (int g = gap; g > 0; g--) {
        printf("g = %d\n", g);

        // iterate between subarrays
        for (int i = 0; i < gap; i++) {
            // iterate through the subarrays themselves
            for (int j = i; j < vec.size() - gap; j += gap) {
                // loop to work backwards from j if j - gap is smaller then j and more
                for (int k = j + gap; k >= gap; k -= gap) {
                    if (vec[k] < vec[k - gap]) { // temp1 is greater, should be after temp2, switch
                        printf("%d < %d switching positions\n", vec[k], vec[k - gap]);
                        swap = vec[k];
                        vec[k] = vec[k - gap];
                        vec[k - gap] = swap;
                    }
                    
                    else { // values are in the right position, do not continue checking lower indexes 
                        printf("%d > %d moving on\n", vec[k], vec[k - gap]);
                        break;
                    }
                }
            }
        }
        // decrement gap by 2 as a default; for optimization find the best decremented values on wikepedia
        gap -= 2;
    }
    
    printf("After Sorting: ");
    printVector(vec);
}




/**
 * Prints a vector in a pretty output format, for example:
 * A vector that contains 1, 2, 3, 4, 5 will print as
 * [ 1, 2, 3, 4, 5 ]
 */
void Sorter::printVector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (i == 0)
            printf("[ ");
        
        printf("%d", vec[i]);
        if (i != vec.size() - 1)
            printf(", ");
        else
            printf(" ]\n");
    }
}