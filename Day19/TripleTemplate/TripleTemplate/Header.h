//
//  Header.h
//  TripleTemplate
//
//  Created by Polina Lyubavina on 9/17/21.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <vector>

template<typename T>

struct Triple {
    
private:
    
    
public:
    // member variables
    T   a_;
    T   b_;
    T   c_;
    
    // Constructor
    Triple(T user_input_a, T user_input_b, T user_input_c) {
        a_ = user_input_a;
        b_ = user_input_b;
        c_ = user_input_c;
    };
    
    // Destructor
    ~Triple() {
        std::cout << "Object destroyed.\n";
    }
    
//    // Copy constructor
//    Triple(const Triple & input);
    
    // Methods
    // Adds member variables together
    T addMemberVariables() {
        return a_ + b_ + c_; 
    }
    
};

#endif /* Header_h */
