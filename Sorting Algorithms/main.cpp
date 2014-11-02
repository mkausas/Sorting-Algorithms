//
//  main.cpp
//  Sorting Algorithms
//
//  Created by Marty Kausas on 10/27/14.
//  Copyright (c) 2014 Marty Kausas. All rights reserved.
//

#include <iostream>
#include "Sorter.h"
int main(int argc, const char * argv[])
{
    Sorter s;
//    vector<int> x = {3, 1, 5, 2, 4};
    vector<int> x = { 62, 83, 18, 53, 7, 17, 95, 86, 47, 69, 25, 28 };
    
    // run insertion sort
//    s.insertionSort(x);
    
    // run selection sort
    s.selectionSort(x);
    
    // run bubble sort
//    s.bubbleSort(x);
    
    // run shell sort
//    s.shellSort(x);
    
    return 0;
}
