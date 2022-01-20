//
//  MakeYourOwnVector.hpp
//  MakeYourOwnVector
//
//  Created by Polina Lyubavina on 9/13/21.
//

#ifndef MakeYourOwnVector_hpp
#define MakeYourOwnVector_hpp
#pragma once
#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>

class Vector {
  
private:
    T* data_;              // Pointer to the beginning of the array of ints.
    int capacity_;        // The actual length of the array created.
    int size_;            // The number of ints currently being stored.
    
//Method
    //sort vector
    void sorts(const Vector& input) const {
        // sorts this and the rhs vectors using bubble sort
        for(int i = 0; i < input.size_ - 1; i++) {
            // begin swap
            for(int j = 0; j < input.size_ - 1; j++) {
                if( input.data_[j] > input.data_[j + 1] ) {
                    swap( input.data_[j], input.data_[j + 1]);
                }
            }
        }
    }

public:
    
//Constructors
    // Returns a vector with the given capacity and a size of 0
    Vector(int initialCapacity) {
        size_ = 0;
        capacity_ = initialCapacity;
        data_ = new T [initialCapacity];
    }
    
    // Deallocates any heap memory used by the MyVector object.
    //    void freeVector();
    // Destructor: turns freeVector() into a destuctor.
    ~Vector() {
        delete [ ] data_;     // Deletes reference from data_ at the Heap to data_'s address at the Heap.
        std::cout << "Object is being deleted.\n";
    };
    
    // Copy Constructor
    Vector(const Vector& rhs) {
        size_ = rhs.size_;
        capacity_ = rhs.capacity_;
        
        T* newArray = new T [rhs.capacity_];
        for(int i = 0; i <= size_; i++) {
            newArray[i] = rhs.data_[i];
        }
        
        delete [] data_;
        data_ = newArray;
    }
    
// Methods
    // pusback
    void pushBack( T value ) {
        if(capacity_ == size_){   // If capacity is equal in size to size, then we will grow the vector's array size.
            growVector();
        }
        
        set(size_ , value);
        
        size_++;
    }
    
    // pop off
    T popBack() {
        T value_to_pop = get(size_ - 1); // Gets the value that will be popped off.
        
        T* new_array = new T [ capacity_ ];     // Creates new array on Heap.
        for(int i = 0; i < size_ - 1; i++) {        // Adds elements from old array to new array.
            new_array[i] = data_[i];
        }
        
        delete [ ] data_;     // Deletes reference from data_ at the Heap to data_'s address at the Heap.
        data_ = new_array;      // Goes from myVector on Stack to myVector on Heap & updates data_ to equal to new array address on Heap.
        
        size_--;
        
        return value_to_pop;
    }

    // Returns the appropriate value in the vector.
    T get( int index ) {
        return data_[index];    // Sets and returns int index for data_
    }

    // Sets the appropriate value in the vector.
    void set( int index, T newValue ) {
        data_[index] = newValue;    // Sets a given value inside data_ at a specified index.
    } // add validation -- if statement for when the index is larger than size of array

    // Doubles the capacity of the vector. The values are copied from the old array to the new array.
    void growVector() {
        capacity_ = capacity_ * 2;     // Increases capacity size by two on the Heap.
        
        T* new_array = new T [ capacity_ ]; // Creates new array on Heap.
        for(int i = 0; i < size_; i++) {        // Adds elements from old array to new array.
            new_array[i] = data_[i];
        }
        
        delete [ ] data_;     // Deletes reference from data_ at the Heap to data_'s address at the Heap.
        data_ = new_array;      // Goes from myVector on Stack to myVector on Heap & updates data_ to equal to new array address on Heap.
    }
    
    // Returns size of vector
    int getSize() {
        cout << "Size of vector is: " << size_ << "\n";
        return size_;
    }
    
    // Returns capacity of vector
    int getCapacity() {
        cout << "Capacity of vector is: " << capacity_ << "\n";
        return capacity_;
    }
    
    // operator =
    Vector& operator=( const Vector& rhs) {
        size_ = rhs.size;
        capacity_ = rhs.capacity;
        
        T* newArray = new T [rhs.capacity];
        for(int i = 0; i <= size_; i++) {
            newArray[i] = rhs.data_[i];
        }
        
        delete [] data_;
        data_ = newArray;
        
        return *this;
    }
    
    // operator []
    T& operator[]( int index) {
        return data_[index];
    }
    
    // operator ==
    bool operator==(const Vector& rhs) const {
        // first, compares lhs and rhs size and capacity for equality
        if( size_ != rhs.size_ || capacity_ != rhs.capacity_ ) {
            return false;
        }
        // sorts vectors
        sorts(this);
        sorts(rhs);
        // if size == size && capacity == capacity, continue running code and proceed to for loop
        for(int i = 0; i < size_; i++) {
            if(data_[i] != rhs.data_[i]) {
                return false;
            }
        }
        return true;
    }
    
    // operator !=
    bool operator!=(const Vector& rhs) const {
        return !(this == rhs);
    }
    
    // operator <
    bool operator<(const Vector& rhs) const {
        // sorts vectors
        sorts(this);
        sorts(rhs);
        // sorts this and the rhs vectors using bubble sort
        for(int i = 0; i < size_; i++) {
            if(data_[i] < rhs.data_[i]) {
                return false;
            }
        }
        return true;
    }
    
    // operator <=
    bool operator<=(const Vector& rhs) const {
        return (this == rhs) || (this < rhs);
    }
    
    // operator >
    bool operator>(const Vector& rhs) const {
        return !(this == rhs) && !(this < rhs);
    }
    
    // operator >=
    bool operator>=(const Vector& rhs) const {
        return (this == rhs) || (this > rhs);
    }
    
    // operator cout <<
    friend ostream & operator<<(ostream & out, const Vector & rhs) {
        for(int i = 0; i < rhs.size; i++) {
            out << rhs.data_[i];
        }
        return out;
    }
    
//  --------------------------------------------------------------------  //
    
    // begin()
    T* begin() { return data_; }
    
    // end()
    T* end() { return begin() + size_; }
    
    // const begin()
    const T* begin() const { return data_; }
    
    // const end()
    const T* end() const { return begin() + size_; }
    

    


};

#endif /* MakeYourOwnVector_hpp */
