//
//  Sorter.cpp
//  Sorting Algorithms
//
//  Created by Marty Kausas on 10/27/14.
//  Copyright (c) 2014 Marty Kausas. All rights reserved.
//

#include "Sorter.h"

/**
 * 
 */
void Sorter::insertionSort(vector<int> vec) {
    // sample vector to sort [ 3,1,5,2,4 ]
    printf("Before Sorting: ");
    printVector(vec);
    
    int temp1; // first val to compare
    int temp2; // val to compare to temp1
    int temp3; // temp variable used to switch temp1 and temp2 in vector
    
    // iterate through the vector and grab initial values to compare
    for (int i = 0; i < vec.size() - 1; i++) {
        // loop to work backwards from i + 1 if temp2 is smaller then temp1 and more
        for (int j = i + 1; j > i; j--) {
            temp1 = vec[i];
            temp2 = vec[j];
            if (temp1 > temp2) { // temp1 is greater, should be after temp2, switch
                printf("%d > %d switching positions\n", temp1, temp2);
                temp3 = temp1;
                vec[i] = temp2;
                vec[j] = temp3;
                if (i > 0)
                    i--;
            } else { // temp2 is greater and in the correct place, move on
                printf("%d < %d moving on\n", temp1, temp2);
                break;
            }
        }
    }
    
    printf("After Sorting: ");
    printVector(vec);
}

void Sorter::printVector(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (i == 0)
            printf("[ ");
        
        printf("%d", vec[i]);
        if (i != vec.size() - 1)
            printf(",");
        else
            printf(" ]\n");
    }
}