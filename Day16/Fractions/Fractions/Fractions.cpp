//
//  Fractions.cpp
//  Fractions
//
//  Created by Polina Lyubavina on 9/14/21.
//

#include "Fractions.hpp"

#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;


// Returns a new fraction that is the result of the right hand side (rhs) fraction added to this fraction.
Fraction Fraction::plus(Fraction rhs) {
    long new_numerator = (rhs.numerator * denominator) + (rhs.denominator * numerator);
    long new_denominator = (rhs.denominator * denominator);
    return Fraction(new_numerator, new_denominator);
}

// Returns a new fraction that is the result of the right hand side (rhs) fraction subtracted from this fraction.
Fraction Fraction::minus(Fraction rhs) {
    long new_numerator =  (rhs.denominator * numerator) - (rhs.numerator * denominator);
    long new_denominator = (rhs.denominator * denominator);
    return Fraction(new_numerator, new_denominator);
}

// Returns a new fraction that is the result of this fraction multiplied by the right hand side (rhs) fraction.
Fraction Fraction::times(Fraction rhs) {
    long new_numerator = (rhs.numerator * numerator);
    long new_denominator = (rhs.denominator * denominator);
    return Fraction(new_numerator, new_denominator);
}

// Returns a new fraction that is the result of this fraction divided by the right hand side (rhs) fraction.
Fraction Fraction:: dividedBy(Fraction rhs) {
    long new_numerator = (numerator * rhs.denominator);
    long new_denominator = (denominator * rhs.numerator);
    return Fraction(new_numerator, new_denominator);
}

// Returns a new fraction that is the reciprocal of this fraction.
Fraction Fraction::reciprocal() {
    long new_numerator = denominator;
    long new_denominator = numerator;
    return Fraction(new_numerator, new_denominator);
}

// Returns a string representing this fraction.
//The string should have the format: "N/D", where N is the numerator, and D is the denominator. This method should always print the reduced form of the fraction. If the fraction is negative, the sign should be displayed on the numerator, e.g., "-1/2" not "1/-2".
string Fraction::toString() {
    string N = to_string(numerator);
    string D = to_string(denominator);
    return N + "/" + D;
}

// Returns a (double precision) floating point number that is the approximate value of this fraction, printed as a real number.
double Fraction::toDouble() {
    return ( numerator / (double) denominator);
}

// Changes this fraction to its reduced form.
void Fraction::reduce() {
    long gcd = GCD();
    
    numerator = numerator / gcd;
    denominator = denominator / gcd;
}

// Returns the greatest common divisor of this fraction's numerator and denominator. This is a helper method for the reduce method, below.
long Fraction::GCD() {
    long gcd = abs(numerator);
    long remainder = abs(denominator);
    while(remainder != 0) {
      long temp = remainder;
      remainder = gcd % remainder;
      gcd = temp;
    }
    
    return gcd; 
}

// Lab: Overloading Fraction Operators
// overloading +
Fraction Fraction::operator+( const Fraction& rhs ) const{
    long new_numerator = (rhs.numerator * denominator) + (rhs.denominator * numerator);
    long new_denominator = (rhs.denominator * denominator);
    return Fraction(new_numerator, new_denominator);
}

// overloading +=
Fraction& Fraction::operator+=( const Fraction& rhs ) {
    numerator = (rhs.numerator * denominator) + (rhs.denominator * numerator);
    denominator = (rhs.denominator * denominator);
    return *this;
}

// overloading -
Fraction Fraction::operator-( const Fraction& rhs ) const{
    long new_numerator =  (rhs.denominator * numerator) - (rhs.numerator * denominator);
    long new_denominator = (rhs.denominator * denominator);
    return Fraction(new_numerator, new_denominator);
}

// overloading -=
Fraction& Fraction::operator-=( const Fraction& rhs ) {
    numerator =  (rhs.denominator * numerator) - (rhs.numerator * denominator);
    denominator = (rhs.denominator * denominator);
    return *this;
}
// overloading *
Fraction Fraction::operator*( const Fraction& rhs ) const{
    long new_numerator = (rhs.numerator * numerator);
    long new_denominator = (rhs.denominator * denominator);
    return Fraction(new_numerator, new_denominator);
}

// overloading *=
Fraction& Fraction::operator*=( const Fraction& rhs ) {
    numerator = (rhs.numerator * numerator);
    denominator = (rhs.denominator * denominator);
    return *this;
}

// overloading /
Fraction Fraction::operator/( const Fraction& rhs ) const{
    long new_numerator = (numerator * rhs.denominator);
    long new_denominator = (denominator * rhs.numerator);
    return Fraction(new_numerator, new_denominator);
}

// overloading /=
Fraction& Fraction::operator/=( const Fraction& rhs ) {
    numerator = (rhs.numerator / numerator);
    denominator = (rhs.denominator / denominator);
    return *this;
}

// overloading ==
bool Fraction::operator==( const Fraction& rhs ) {
    if(numerator == rhs.numerator && denominator == rhs.denominator) {
        return true;
    }
    return false;
}

// overloading !=
bool Fraction::operator!=( const Fraction& rhs ) {
    if(numerator != rhs.numerator && denominator != rhs.denominator) {
        return true;
    }
    return false;
}

// overloading <
bool Fraction::operator<( const Fraction& rhs ) {
    if(numerator < rhs.numerator && denominator < rhs.denominator) {
        return true;
    }
    return false;
}

// overloading >
bool Fraction::operator>( const Fraction& rhs ) {
    if(numerator > rhs.numerator && denominator > rhs.denominator) {
        return true;
    }
    return false;
}

// overloading <=
bool Fraction::operator<=( const Fraction& rhs ) {
    if(numerator <= rhs.numerator && denominator <= rhs.denominator) {
        return true;
    }
    return false;
}

// overloading >=
bool Fraction::operator>=( const Fraction& rhs ) {
    if(numerator >= rhs.numerator && denominator >= rhs.denominator) {
        return true;
    }
    return false;
}
