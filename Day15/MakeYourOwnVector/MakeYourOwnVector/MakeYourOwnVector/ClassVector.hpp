//
//  ClassVector.hpp
//  MakeYourOwnVector
//
//  Created by Polina Lyubavina on 9/14/21.
//

#ifndef ClassVector_hpp
#define ClassVector_hpp

#include "MakeYourOwnVector.hpp"

#include <stdio.h>

class Vector {
    
public:
    int* myArray;              // Pointer to the beginning of the array of ints.
    int capacity;        // The actual length of the array created.
    int size;            // The number of ints currently being stored.
    
};

#endif /* ClassVector_hpp */
