//
//  main.cpp
//  VectorPractice
//
//  Created by Polina Lyubavina on 8/30/21.
//

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <cassert>


using namespace std;


// Takes a vector of ints as a parameter and returns the sum of all the values in the vector.
int sum(vector<int> y) {
    int numLoop = 0;
    for(int index = 0; index < y.size(); index++) {
        numLoop = numLoop + y[index];
    }
    return numLoop;
};

// Takes a string as a parameter and returns a vector of chars that contains the same data.
vector<char> stringToVec(string s) {
    vector<char> stringedAlong;
    for(char index = 0; index < s.length(); index++) {
        stringedAlong.push_back(s[index]);
    }
    return stringedAlong;
}

// Takes a vector of ints and returns a vector with the same elements in reverse order.
vector<int> reverse(vector<int> n) {
    vector<int> reverseOrder;
    for(int index = n.size() - 1; index >= 0; index--) {
        reverseOrder.push_back(n[index]);
    }
    return reverseOrder;
};
                  
                  
                  

int main() {
    
//    // Input for the sum of all the values in the vector.
    vector<int> integers = {10, 10, 12, 12};
    cout << "Sum of all the values in the vector is: " << sum(integers) << "\n";

    
    // Input for a vector of chars from a string.
    string words = "Too bad code isn't written in rapping rhymes.";
    cout << "Check the first character is equivalent to first letter in your string: " << stringToVec(words).front() << "\n";
    
    
    // Input for a vector of reversed ints.
    vector<int> numToReverse = {1, 2, 3, 4, 5, 6, 7};
    vector<int> emptyVec = {};
    vector<char> emptyCharVec = {};
    
    // Tests
    assert(sum(integers) == 44);
    assert(sum(emptyVec) == 0);
    assert(stringToVec(words).front() == words[0]);
    assert(stringToVec("") == emptyCharVec);
    assert(reverse(numToReverse).front() == numToReverse[6]);
    assert(reverse(emptyVec) == emptyVec);
    
    
    
    
    return 0;
}
