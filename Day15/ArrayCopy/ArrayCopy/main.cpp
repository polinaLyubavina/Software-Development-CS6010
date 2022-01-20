//
//  main.cpp
//  ArrayCopy
//
//  Created by Polina Lyubavina on 9/13/21.
//

#include <iostream>
#include <cassert>

using namespace std;

// Write a function that takes an array of doubles as a parameter (actually as 2 parameters: a pointer to a double, and the size of the array) and returns a copy of the array (it should return a pointer to the start (first element) of the copied array).

double* copy_array(double* dPointer, int size){
    
    double* copied_array = new double [size];     // Creates an array with the same size as the pointer array.
    
    for(int i = 0; i < size; i++) {               // Goes through the pointer array and stores values in second array.
        copied_array[i] = dPointer[i];
    }
    
    cout << copied_array[9] << "\n";
    return copied_array;
}


int main(int argc, const char * argv[]) {
    
    double* myArray = new double[10];   // Returns a pointer to the first of 10 doubles.
    myArray[9] = 180;
    
    assert( myArray[9] = 180);          // Test
    
    copy_array(myArray, 10);
    
    
    return 0;
}
