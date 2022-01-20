////
////  MakeYourOwnVector.cpp
////  MakeYourOwnVector
////
////  Created by Polina Lyubavina on 9/13/21.
////
//
//#include "MakeYourOwnVector.hpp"
//
//
//#include <vector>
//#include <stdio.h>
//#include <iostream>
//
//using namespace std;
//
//
//// Destructor deallocates any heap memory used by the MyVector object.
////void ~Vector::freeVector() {
////    delete [ ] myArray;     // Deletes reference from myArray at the Heap to myArray's address at the Heap.
////    delete this;                    // Deletes pointer myVector from Stack to the Heap.
////    myVector = nullptr;                 // Sets myVector to null.
////}
//
//
//// Sets the appropriate value in the vector.
//void Vector::set( int index, int newValue ) {
//    myArray[index] = newValue;    // Sets a given value inside myArray at a specified index.
//} // add validation -- if statement for when the index is larger than size of array
//
//
//// Work as they do for std::vector
//void Vector::pushBack( int value ) {
//    if(capacity == size){   // If capacity is equal in size to size, then we will grow the vector's array size.
//        growVector();
//    }
//
//    set(size , value);
//
//    size++;
//}
//
//
//int Vector::popBack() {
//    int value_to_pop = get(size - 1); // Gets the value that will be popped off.
//
//    int* new_array = new int [ capacity ];     // Creates new array on Heap.
//    for(int i = 0; i < size - 1; i++) {        // Adds elements from old array to new array.
//        new_array[i] = myArray[i];
//    }
//
//    delete [ ] myArray;     // Deletes reference from myArray at the Heap to myArray's address at the Heap.
//    myArray = new_array;      // Goes from myVector on Stack to myVector on Heap & updates myArray to equal to new array address on Heap.
//
//    size--;
//
//    return value_to_pop;
//}
//
//
//// Returns the appropriate value in the vector.
//int Vector::get( int index ) {
//    return myArray[index];    // Sets and returns int index for myArray
//}
//
//
//// Doubles the capacity of the vector. The values are copied from the old array to the new array.
//void Vector::growVector() {
//    capacity = capacity * 2;     // Increases capacity size by two on the Heap.
//
//    int* new_array = new int [ capacity ]; // Creates new array on Heap.
//    for(int i = 0; i < size; i++) {        // Adds elements from old array to new array.
//        new_array[i] = myArray[i];
//    }
//
//    delete [ ] myArray;     // Deletes reference from myArray at the Heap to myArray's address at the Heap.
//    myArray = new_array;      // Goes from myVector on Stack to myVector on Heap & updates myArray to equal to new array address on Heap.
//}
//
//
//// Returns size of vector
//int Vector::getSize() {
//    cout << "Size of vector is: " << size << "\n";
//    return size;
//}
//
//
//// Returns capacity of vector
//int Vector::getCapacity() {
//    cout << "Capacity of vector is: " << capacity << "\n";
//    return capacity;
//}
//
//// Copy Constructor
//Vector::Vector(const Vector& rhs) {
//    size = rhs.size;
//    capacity = rhs.capacity;
//
//    int* newArray = new int [rhs.capacity];
//    for(int i = 0; i <= size; i++) {
//        newArray[i] = rhs.myArray[i];
//    }
//
//    delete [] myArray;
//    myArray = newArray;
//}
//
//// operator=
//Vector& Vector::operator=( const Vector& rhs) {
//    size = rhs.size;
//    capacity = rhs.capacity;
//
//    int* newArray = new int [rhs.capacity];
//    for(int i = 0; i <= size; i++) {
//        newArray[i] = rhs.myArray[i];
//    }
//
//    delete [] myArray;
//    myArray = newArray;
//
//    return *this;
//}
//
//// operator[]
//int& Vector::operator[]( int index) {
//    return myArray[index];
//}
//
//// operator cout <<
//ostream & operator<<(ostream & out, const Vector & rhs) {
//    for(int i = 0; i < rhs.size; i++) {
//        out << rhs.myArray[i];
//    }
//    return out;
//}
//
