//
//  main.cpp
//  FunctionPractice
//
//  Created by Polina Lyubavina on 8/27/21.
//

#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <ctime>

using namespace std;



// Part 2: Write Your Own Functions
    


// Write a function that performs the hypotenuse task described above, but does not read from std::cin
// You don't want to do std::cin in the function directly because a function is a black box and its point is to save you work. Get the inputs and call the function from somewhere else.
double find_hypotenuse (double i, double j) {
    double n = (sqrt(pow(i, 2)) + (pow(j, 2)));
    return n;
}



//Why would it be difficult to turn the speed/velocity task above into a function? What imperfect solutions can you come up with that wrap that code into one (or more) functions?
// It would be difficult to turn the speed/velocity task into a function because it returns more than one output. Just put it all inside a function.



//Challenge question: write a function called isPrime that takes an integer and returns whether or not it's a prime number
int isPrime (int number) {
    n = number 
}
    

// Write a function isCapitalized that takes in a string parameter and returns whether or not the string starts with a capital letter.
bool isCapitalized (string word) {
    char firstLetter = word.front();
    if(firstLetter >= 65 && firstLetter <= 90) {
        return true;
    } else {
        return false;
    }
}

// Write a function boolToString that takes in a Boolean parameter and returns the string "true" or "false" depending on its value. Use this function to display the results of testing the isCapitalized function.
string boolToString (bool word){
    if (word == true) {
        return "true";
    } else {
        return "false";
    }
}


int main() {
    
//isCapitalized function call
    string userString;
    cout << "Give me a word: \n";
    cin >> userString;
    if (isCapitalized(userString)) {
        cout << "The string is capitalized." << "\n";
    } else {
        cout << "The string is not capitalized." << "\n";
    }
    
    
//boolToString function call
    cout << boolToString(isCapitalized(userString)) << "\n";
    
    
// find_hypotenuse function call & provided inputs
    double side1 = 20;
    double side2 = 30;
    cout << find_hypotenuse(side1 ,side2) << "\n"; // prints out function's value
    
    double hypotenuse = find_hypotenuse(side1 ,side2); // stores value from function
    cout<< hypotenuse << "\n";
    
    
    
    
    
// Part 1: Practice Calling Functions
    
    
    
// a) find the hypotenuse

    int firstSideLength = 0;
    int secondSideLength = 0;
    float thirdSideLength = 0;

    cout << "Enter right-angle side lengths of a triangle. Enter first side: \n";
    cin >> firstSideLength;

    cout << "Enter second side: \n";
    cin >> secondSideLength;

    firstSideLength = pow(firstSideLength, 2);
    secondSideLength = pow(secondSideLength, 2);

    thirdSideLength = sqrt(firstSideLength + secondSideLength); // calculate hypotenuse

    cout << "The length of the hypotenuse is: " << thirdSideLength << "\n";

    

// b) x and y velocity
    
    int speedingAlong = 0;
    int angledAt = 0;
    int velocityX = 0;
    int velocityY = 0;

    cout << "Enter the speed you're going at: \n";
    cin >> speedingAlong;

    cout << "Enter angle you're going at: \n";
    cin >> angledAt;

    velocityX = speedingAlong * (cos(angledAt));
    velocityY = speedingAlong * (sin(angledAt));

    cout << "Your x velocity is: " << velocityX << "\n";
    cout << "Your y velocity is: " << velocityY << "\n";
    
    
    
// c) copy and run code from cppreference.com

    std::time_t result = std::time(nullptr);
    std::cout << std::asctime(std::localtime(&result))
              << result << " seconds since the Epoch\n";

// The code works as expected. The functions called in this snippet are time(), cout(), asctime(), and localtime()

    
    
    return 0;
}
