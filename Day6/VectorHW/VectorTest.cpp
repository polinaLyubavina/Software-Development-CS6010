/*
  Author: Daniel Kopta and ??
  July 2017
  
  CS 6010 Fall 2019
  Vector util library tests

  Compile this file together with your VectorUtil library with the following command:
  clang++ -std=c++11 VectorTest.cpp VectorUtil.cpp

  Most of the provided tests will fail until you have provided correct 
  implementations for the VectorUtil library functions.

  You will need to provide more thorough tests.
*/

#include <iostream>
#include <string>

// Include the VectorUtil library
#include "VectorUtil.h"

/*
 * Helper function for failing a test.
 * Prints a message and exits the program.
 */
void ErrorExit(std::string message)
{
  std::cerr << "Failed test: " << message << std::endl;
  exit(1);
}


int main()
{
  
  // Set up some input vectors for testing purposes.

  // We can use list initialization syntax:
  vector<int> v1 = {3, 1, 0, -1, 5};

  // Or we can repeatedly push_back items
  vector<int> v2;
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(3);

  // When testing, be sure to check boundary conditions, such as an empty vector
  vector<int> empty;
  
  
  /* 
   * Contains tests 
   */

  // v1 doesn't contain 4, so this should return false
  if(Contains(v1, 4))
    ErrorExit("Contains test 1");

  // v1 does contain -1, so this should return true
  if(!Contains(v1, -1))
    ErrorExit("Contains test 2");

  /* 
   * The vector 'empty' doesn't contain anything, so this should return false
   * The specific value we're looking for here (99) is not important in this test. 
   * This test is designed to find any general errors caused by the array being empty. 
   * That type of error is unlikely to depend on the value we are looking for.
  */
  if(Contains(empty, 99))
    ErrorExit("Contains empty");
  
  // TODONE: Add your own tests that thoroughly exercise your VectorUtil library.
    
    // minimum of v1 is -1, return false
    if(FindMin(v1) != -1)
        ErrorExit("FindMin test 1");
    
    // v1 doesn't have -10, return false
    if(FindMin(v1) == -10)
        ErrorExit("FindMin test 2");
    
    // v1 minimum is not 3, but 3 is included in vector, return false
    if(FindMin(v1) == 3)
        ErrorExit("FindMin test 3");
    
    // v1 doesn't have 6, so return false
    if(FindMax(v1) == 6)
        ErrorExit("FindMax test 1");
    
    // v1 does include 3, but 3 is not the max, return false
    if(FindMax(v1) == 3)
        ErrorExit("FindMax test 2");
    
    // v1 contains 5 as max, return true
    if(FindMax(v1) != 5)
        ErrorExit("FindMax test 3");
    
    // v1 contains 5 index slots that have a value of 8 when combined, if Average has a value other than int of 1 (not rounded to a float or double) should return false.
    if(Average(v1) == 4)
        ErrorExit("Average test 1");
    
    // v1 average is 1, this should return false
    if(Average(v1) != 1)
        ErrorExit("Average test 2");
    
    // v1 is not sorted in ascending order, return false
    if(IsSorted(v1))
        ErrorExit("IsSorted test 1");
    
    // v2 is sorted in ascending order, return true
    if(!IsSorted(v2))
        ErrorExit("IsSorted test 2");
    
    // empty vector is sorted
    vector<int> v3 = {};
    if(!IsSorted(v3))
        ErrorExit("IsSorted test 3");
    
    // vector with a single value is sorted
    vector<int> v4 = {1};
    if(!IsSorted(v4))
        ErrorExit("IsSorted test 4");
    
    // 
    
    
    

  // Since any failed test exits the program, if we made it this far, we passed all tests.
  std::cout << "All tests passed!" << std::endl; 

}
