//
//  main.cpp
//  NumberConverter
//
//  Created by Polina Lyubavina on 9/7/21.
//
#include "NumberConverter.hpp"

#include <iostream>
#include <math.h>
#include <string>
#include <cassert>

using namespace std;

int main(int argc, const char * argv[]) {

    string strValue = "";
    int base = 0;
    int intValue = 0;
    
//    cout << "Value for string to int: \n";
//    cin >> strValue;
//    cout << "Base: \n";
//    cin >> base;
//    cout << "Answer: \n" << stringToInt(strValue, base) << "\n";
//
//    cout << "Value for string to int: \n";
//    cin >> strValue;
//    cout << "Base: \n";
//    cin >> base;
//    cout << "Answer: \n" << stringToInt(strValue, base) << "\n";
//
//    cout << "Value for string to int: \n";
//    cin >> strValue;
//    cout << "Base: \n";
//    cin >> base;
//    cout << "Answer: \n" << stringToInt(strValue, base) << "\n";
//
//    cout << "Value for binary to string: \n";
//    cin >> intValue;
//    cout << "Answer: \n"  << binaryToString(intValue) << "\n";
//
//    cout << "Value for decimal to string: \n";
//    cin >> intValue;
//    cout << "Answer: \n" << decimalToString(intValue) << "\n";
//
    cout << "Value for hexit to string: \n";\
    cout << (char) 55 << "\n";
    cin >> intValue;
    cout << "Answer: \n" << hexitToString(255) << "\n";

//
////    if(argc > 1) {
////        strValue = argv[1];
////        base = stoi(argv[2]);
////    }
//


    // Tests
    assert(binaryToString(10) == "1010");
    assert(binaryToString(64) == "1000000");
    assert(binaryToString(63) == "111111");
    
    assert(decimalToString(10) == "10");
    assert(decimalToString(200) == "200");
    assert(decimalToString(8123) == "8123");
    
    assert(hexitToString(9) == "9");
    assert(hexitToString(14) == "E");
    assert(hexitToString(255) == "FF");

    
    return 0;
}
