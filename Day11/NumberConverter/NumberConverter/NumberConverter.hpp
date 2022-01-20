//
//  NumberConverter.hpp
//  NumberConverter
//
//  Created by Polina Lyubavina on 9/7/21.
//

#ifndef NumberConverter_hpp
#define NumberConverter_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>


// string to integer
int stringToInt(std::string strValue, int base);

// binary to string
std::string binaryToString(int intValue);

// decimal to string
std::string decimalToString(int intValue);

// hexadecimal to string
std::string hexitToString(int intValue);

#endif /* NumberConverter_hpp */
