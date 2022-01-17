//
//  main.cpp
//  Part1_UnitConversion
//
//  Created by Polina Lyubavina on 8/24/21.
//
// Part 1 - Polina Lyubavina (@polinalyubavina)
// Part 2 - Terra Tidwell (@terratidwell)

#include <iostream>

int main ()
{

    // Unit '1 Ounce = x of these'
    
    float ounces; // user puts in ounces
    
    std::cout << "Enter volume in ounces for conversion: " << std::endl;
    std::cin >> ounces;
    
    float cups = ounces * 0.125;
    float pints = ounces * 0.0625;
    double gallons = ounces * 0.0078125;
    float liters = ounces * 0.0296;
    float cubic_inches = 1.8;

    std::cout << " Ounces: " << ounces << std::endl;
    std::cout << " Cups: " << cups << std::endl;
    std::cout << " Pints: " << pints << std::endl;
    std::cout << " Gallons: " << gallons << std::endl;
    std::cout << " Liters: " << liters << std::endl;
    std::cout << " Cubic inches: " << cubic_inches << std::endl;

}
