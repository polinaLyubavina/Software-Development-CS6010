//
//  Fractions.hpp
//  Fractions
//
//  Created by Polina Lyubavina on 9/14/21.
//

#ifndef Fractions_hpp
#define Fractions_hpp

#pragma once

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std; 

class Fraction {
 
public:
    //Constructors
    // The default constructor, which sets the value of the fraction to 0/1.
    Fraction() {
        numerator = 0;
        denominator = 1;
    };
    
    // A constructor which sets the value of the fraction to a specific numerator (n) and denominator (d).
    Fraction(long n, long d) {
        if( n < 0 && d < 0 ) {      // if both negative, makes positive
            n *= -1;
            d *= -1;
        }
        else if( d < 0 ) {          // if denominator negative, sets the nominator to positive
            n = -n;
            d *= -1;
        }
        
        numerator = n;
        denominator = d;
        
        reduce();                   // reduces the fraction 
    };
    
    //Methods
    // Returns a new fraction that is the result of the right hand side (rhs) fraction added to this fraction.
    Fraction plus(Fraction rhs);
    
    // Returns a new fraction that is the result of the right hand side (rhs) fraction subtracted from this fraction.
    Fraction minus(Fraction rhs);
    
    // Returns a new fraction that is the result of this fraction multiplied by the right hand side (rhs) fraction.
    Fraction times(Fraction rhs);
    
    // Returns a new fraction that is the result of this fraction divided by the right hand side (rhs) fraction.
    Fraction dividedBy(Fraction rhs);
    
    // Returns a new fraction that is the reciprocal of this fraction.
    Fraction reciprocal();
    
    // Returns a string representing this fraction.
    //The string should have the format: "N/D", where N is the numerator, and D is the denominator. This method should always print the reduced form of the fraction. If the fraction is negative, the sign should be displayed on the numerator, e.g., "-1/2" not "1/-2".
    string toString();
    
    // Returns a (double precision) floating point number that is the approximate value of this fraction, printed as a real number.
    double toDouble();
    
    // Lab: Overloading Fraction Operators
    // overloading +
    Fraction operator+( const Fraction& rhs ) const;
    
    // overloading +=
    Fraction& operator+=( const Fraction& rhs );
    
    // overloading -
    Fraction operator-( const Fraction& rhs ) const;

    // overloading -=
    Fraction& operator-=( const Fraction& rhs );

    // overloading *
    Fraction operator*( const Fraction& rhs ) const;

    // overloading *=
    Fraction& operator*=( const Fraction& rhs );

    // overloading /
    Fraction operator/( const Fraction& rhs ) const;

    // overloading /=
    Fraction& operator/=( const Fraction& rhs );

    // overloading ==
    bool operator==( const Fraction& rhs );

    // overloading !=
    bool operator!=( const Fraction& rhs );
    
    // overloading <
    bool operator<( const Fraction& rhs );
    
    // overloading >
    bool operator>( const Fraction& rhs );

    // overloading <=
    bool operator<=( const Fraction& rhs );

    // overloading >=
    bool operator>=( const Fraction& rhs );





    
private:
    long numerator;
    long denominator;
    
    //Methods
    // Changes this fraction to its reduced form.
    void reduce();
    
    // Returns the greatest common divisor of this fraction's numerator and denominator. This is a helper method for the reduce method, below.
    long GCD();

};

#endif /* Fractions_hpp */
