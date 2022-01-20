/*
 * Author: Daniel Kopta and <add your names here>
 * July 2017

 * Testing program for your Fraction class.
 * These tests are not very thorough, and you will need to add your own.
*/

// Include the student's Fraction class
#include "Fractions.hpp"

// Standard includes
#include <iostream>
#include <string>
// Also include math so we can use the pow and abs functions (see below)
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

bool CompareDoubles( double d1, double d );


/* Helper function for writing tests that compare strings.
 * Compares expected to result, and prints an error if they don't match. 
 */
void Test( const string & message, const string & expected, const string & result )
{
  cout << "Test: " << message << endl;
  if(expected != result) {
    cout << "\tFAILED, expected: \"" << expected << "\", got: \"" << result << "\"" << endl;
  }
  else {
    cout << "\tPASSED" << endl;
  }
}

/* Helper function for writing tests that compare doubles (overloaded version of the above)
 * Compares expected to result, and prints an error if they don't match. 
 */
void Test( const string & message, double expected, double result )
{
  cout << "Test: " << message << endl;
  if( !CompareDoubles( expected, result ) ) {
    cout << "\tFAILED, expected: " << expected << ", got: " << result << endl;
  }
  else {
    cout << "\tPASSED" << endl;
  }
}


/*
 * Helper function
 * Returns whether or not two doubles are "equivalent",
 * within a certain error bound. 
 *
 * As we know, floating point numbers are incapable of 
 * precisely representing certain values, so to compare
 * equality, we must tolerate some absolute difference.
 */
bool CompareDoubles( double d1, double d2 )
{
  return std::abs( d1 - d2 ) < 1e-6;
}

/* 
 * Basic constructor and toString tests
 */
void TestConstructors()
{
  std::string result = "";
  Fraction f1;
  result = f1.toString();
  Test( "Default constructor", "0/1", result );
  
  Fraction f2(1, 2);
  result = f2.toString();
  Test( "Basic constructor", "1/2", result );

  //TODO: Add your own additional tests here
    
}


/*
 * Negative fraction tests
 */
void TestNegative()
{
  std::string result = "";
  Fraction f1(-1, 2);
  result = f1.toString();
  Test( "Negative numerator", "-1/2", result );

  Fraction f2(1, -2);
  result = f2.toString();
  Test( "Negative denominator", "-1/2", result ); 

  Fraction f3(-1, -2);
  result = f3.toString();
  Test( "Negative numerator and denominator", "1/2", result );

  Fraction f4(4, -16);
  result = f4.toString();
  Test( "Negative denominator and reduce", "-1/4", result );


  //TODO: Add your own additional tests here
}


/*
 * Reduced fraction tests
 */
void TestReduced()
{
  std::string result = "";
  Fraction f1(2, 4);
  result = f1.toString();
  Test( "Reduce fraction (2/4)", "1/2", result );

  //TODO: Add your own additional tests here
    
    Fraction f2(-6, 10);
    result = f2.toString();
    Test( "Reduce fraction (-6/10)", "-3/5", result );
}


/*
 * Reciprocal tests
 */
void TestReciprocal()
{
  std::string result = "";
  Fraction f1(1, 3);
  f1 = f1.reciprocal();
  result = f1.toString();
  Test( "Reciprocal of simple", "3/1", result );

  Fraction f2(-1, 2);
  f2 = f2.reciprocal();
  result = f2.toString();
  Test( "Reciprocal of negative", "-2/1", result );

  Fraction f3(6, 2);
  f3 = f3.reciprocal();
  result = f3.toString();
  Test( "Reciprocal of non-reduced", "1/3", result );

  //TODO: Add your own additional tests here
}

/* 
 * Fraction addition tests
 */
void TestPlus()
{
  std::string result = "";
  Fraction f1(4, 6);
  Fraction f2(3, 4);
  
  // Should result in 17/12
  Fraction f3 = f1.plus(f2);
  result = f3.toString();
  Test( "Addition of non-reduced", "17/12", result );

  //TODO: Add your own additional tests here
}

/*
 * Multiplication tests
 */
void TestMultiply()
{
  std::string result = "";
  Fraction f1(4, 6);
  Fraction f2(3, 4);
  
  // Should result in 12/24
  Fraction f3 = f1.times(f2);
  result = f3.toString();
  Test( "Multiplication of reduced", "1/2", result );

}

/*
 * Division tests
 */
void TestDivide()
{
  std::string result = "";
  Fraction f1(4, 6);
  Fraction f2(3, 4);
  
  // Should result in 16/18
  Fraction f3 = f1.dividedBy(f2);
  result = f3.toString();
  Test( "Division of reduced", "8/9", result );

}

/*
 * Subtraction tests
 */
void TestSubtract()
{
  std::string result = "";
  Fraction f1(4, 6);
  Fraction f2(3, 4);
  
  // Should result in -1/12
  Fraction f3 = f1.minus(f2);
  result = f3.toString();
  Test( "Subtraction of reduced", "-1/12", result );

}

void TestToDouble()
{
  Fraction f1(1, 2);
  double result = f1.toDouble();
  Test( "toDouble (1/2)", 0.5, result );

  Fraction f2(1, 3);
  result = f2.toDouble();
  Test( "toDouble (1/3)", 1.0/3.0, result );
}

/*
 * Approximates pi using a summation of fractions.
 */
double ComputePi()
{
  Fraction sum;

  // We will only compute the first 4 terms
  // Note that even with long (64-bit) numbers, 
  // the intermediate numbers required for fraction addition 
  // become too large to represent if we go above k=4.
  for( long k = 0; k < 4; k++ )
  {
    Fraction multiplier( 1, pow(16, k) );
    Fraction firstTerm(  4, 8*k + 1 );
    Fraction secondTerm( 2, 8*k + 4 );
    Fraction thirdTerm(  1, 8*k + 5 );
    Fraction fourthTerm( 1, 8*k + 6 );

    Fraction temp = firstTerm.minus( secondTerm );
    temp = temp.minus( thirdTerm );
    temp = temp.minus( fourthTerm );
 
    Fraction product = multiplier.times( temp );

    sum = sum.plus( product );
  }
  
  return sum.toDouble();
}

int main()
{
  // Break up the tests into categories for better readability.
    TestConstructors();
    TestNegative();
    TestReduced();
    TestReciprocal();
    TestToDouble();
    TestPlus();
    TestMultiply();
    TestDivide();
    TestSubtract();

  Test("Approximating pi", 3.141592, ComputePi());

  // TODO: Add your own additional tests

}
