//
//  Sorter.cpp
//  Sorting Algorithms
//
//  Created by Marty Kausas on 10/27/14.
//  Copyright (c) 2014 Marty Kausas. All rights reserved.
//

#include "Sorter.h"

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
    
    int temp1; // first val to compare
    int temp2; // val to compare to temp1
    int swap; // temp variable used to switch temp1 and temp2 in vector
    
    // iterate through the vector and grab initial values to compare
    for (int i = 0; i < vec.size() - 1; i++) {
        // loop to work backwards from i + 1 if temp2 is smaller then temp1 and more
        for (int j = i + 1; j > i; j--) {
            temp1 = vec[i];
            temp2 = vec[j];
            if (temp1 > temp2) { // temp1 is greater, should be after temp2, switch
                printf("%d > %d switching positions\n", temp1, temp2);
                swap = temp1;
                vec[i] = temp2;
                vec[j] = swap;
                if (i > 0)
                    i--;
            }
            
            else { // temp2 is greater and in the correct place, move on
                printf("%d < %d moving on\n", temp1, temp2);
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