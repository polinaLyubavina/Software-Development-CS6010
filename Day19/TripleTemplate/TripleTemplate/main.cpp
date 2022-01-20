//
//  main.cpp
//  TripleTemplate
//
//  Created by Polina Lyubavina on 9/17/21.
//

#include "Header.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

    // test ints
    Triple<int> firstTriple(3, 4, 7);
    std::cout << firstTriple.a_ << " " << firstTriple.b_ << " " << firstTriple.c_ << "\n";
    
    // test adding ints
    cout << firstTriple.addMemberVariables() << "\n";

    
    // test string
    Triple<string> secondTriple("mango", "pineapple", "peach");
    std::cout << secondTriple.a_ << " " << secondTriple.b_ << " " << secondTriple.c_ << "\n";
    
    // test adding strings 
    cout << secondTriple.addMemberVariables() << "\n";
    
    Triple<vector<int>> thirdTriple({1, 2, 3}, {4, 5, 6}, {7, 8, 9});

    // you cannot perform sum on a vector because the + operator has not been overloaded to add vectors together
//    thirdTriple.addMemberVariables();
//    cout << thirdTriple.addMemberVariables() << "\n";
    
    return 0;
}
