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
    vector<int> x = {3, 1, 5, 2, 4};
    s.insertionSort(x);
    return 0;
}
