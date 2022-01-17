//
//  main.cpp
//  RoadTripCalculator
//
//  Created by Polina Lyubavina on 8/24/21.
//

#include <iostream>


int main ()
{
    
    int distance; //Length of trip (in miles)
    float mpg; // miles per gallon
    float costOfGas; //in dollars per gallon
    
    std::cout << "How many miles did you travel? "; // space because user will type right after
    std::cin >> distance;
    
    std::cout << "How many miles per gallon did your car get? ";
    std::cin >> mpg;
    
    std::cout << "How much did gas cost? ($/gallon) ";
    std::cin >> costOfGas;
    
    float numGallonsUsed = distance / mpg;
    
    float totalCost = numGallonsUsed * costOfGas;
    
    std::cout << "Total cost of your trip of " << distance << "miles " << " was " << totalCost << std::endl; // "\n"
    
}
