//
//  NumberConverter.cpp
//  NumberConverter
//
//  Created by Polina Lyubavina on 9/7/21.
//

#include "NumberConverter.hpp"

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

// string to integer
int stringToInt(string strValue, int base) {
    int tempNum = 0;
    int tempPower = 0;
    int tempAnswer = 0;
    if(strValue[0] == '-') {
        return -stringToInt(strValue.substr(1, strValue.length() - 1), base);
    }
    if(base == 10) {
        for(int i = 0; i < strValue.length(); i++) {
            tempNum = strValue[i] - '0';
            tempPower = (int)strValue.length() - i - 1;
            tempAnswer += (tempNum * pow(base, tempPower));
        }
    }
    if(base == 2) {
        for(int i = 0; i < strValue.length(); i++) {
            tempNum = strValue[i] - '0';
            tempPower = (int)strValue.length() - i - 1;
            tempAnswer += (tempNum * pow(base, tempPower));
        }
    }
    if(base == 16) {
        for(int i = 0; i < strValue.length(); i++) {
            if(strValue[i] <= '9') {
                tempNum = strValue[i] - '0';
                tempPower = (int)strValue.length() - i - 1;
                tempAnswer += (tempNum * pow(base, tempPower));
            }
            if(strValue[i] >= 'A' && strValue[i] <= 'F') {
                char tempHex = std::tolower(strValue[i]);
                tempNum = tempHex - 'a' + 10;
                tempPower = (int)strValue.length() - i - 1;
                tempAnswer += (tempNum * pow(base, tempPower));
            }
            if(strValue[i] >= 'a' && strValue[i] <= 'f') {
                tempNum = strValue[i] - 'a' + 10;
                tempPower = (int)strValue.length() - i - 1;
                tempAnswer += (tempNum * pow(base, tempPower));
            }
        }
    }
    return tempAnswer;
}

string reverseString(string input) {
    string output = "";
    for (int i = (int)input.length() - 1; i >= 0; i--) {
        output += input[i];
    }
    return output;
}

// binary to string
string binaryToString(int intValue) {
    string tempNum = "";
    while(intValue != 0) {
        if(intValue % 2 == 0) {
            tempNum += '0';
        }
        else if(intValue % 2 == 1) {
            tempNum += '1';
        }
        intValue = intValue / 2;
    }
    return reverseString(tempNum);
}


//decimal to string
string decimalToString(int intValue) {
    string tempAnswer;
    int modRemainder = 0;
    
    while (intValue != 0) {
        modRemainder = intValue % 10;
        
        tempAnswer += '0' + modRemainder;
        
        intValue = intValue / 10;
    }
    
    return reverseString(tempAnswer);
}

//hexidecimal to string
string hexitToString(int intValue) {
    string tempAnswer;
    int modRemainder = 0;
    
    while (intValue != 0) {
        modRemainder = intValue % 16;
        
        if (modRemainder < 10) {
            tempAnswer += (char) 48 + modRemainder;
        } else {
            tempAnswer += 'A' + modRemainder;
        }
        
        intValue = intValue / 16;
    }
    
    return reverseString(tempAnswer);
}

