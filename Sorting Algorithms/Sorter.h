//
//  Sorter.h
//  Sorting Algorithms
//
//  Created by Marty Kausas on 10/27/14.
//  Copyright (c) 2014 Marty Kausas. All rights reserved.
//

#ifndef __Sorting_Algorithms__Sorter__
#define __Sorting_Algorithms__Sorter__

#include <iostream>
#import <vector>
using namespace std;

class Sorter {
    
public:
    
    int nums[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    void insertionSort(vector<int> vec);
    void printVector(vector<int> vec);
private:
};

#endif /* defined(__Sorting_Algorithms__Sorter__) */
