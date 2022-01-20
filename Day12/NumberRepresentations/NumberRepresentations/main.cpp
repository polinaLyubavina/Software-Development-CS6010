//
//  main.cpp
//  NumberRepresentations
//
//  Created by Polina Lyubavina on 9/8/21.
//

#include <iostream>
#include <math.h>
#include <string>
#include <cstdint>
#include <cassert>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

bool approxEquals( double a, double b, double tolerance ) {
    double total = a - b;
    if(abs(total) < tolerance) {
        cout << "the value is equivalent.\n";
        return true;
    } else {
        cout << "the value is not equivalent.\n";
        return false;
    }
}

void readUnicode( ) {
    ifstream s ("UTF-8-demo.txt");
    char c;
    int numAscii = 0;
    int numUni = 0;
    while(s >> c) {
        cout << c << "\n";
        if(c < 0) {
            numUni += 1;
        }
        else if(c >= 0) {
            numAscii += 1;
        }
    }
    cout << "Number of ASCII characters in file: " << numAscii << "\n";
    cout << "Number of Unicode characters in file: " << numUni << "\n";
    s.close();
}

int main(int argc, const char * argv[]) {
    
    //PART 1

    // Use sizeof() to find size of built in data types
    int sizeInt = sizeof(int);
    cout << sizeInt << "\n";
    
    int sizeFloat = sizeof(float);
    cout << sizeFloat << "\n";
    
    int sizeDouble = sizeof(double);
    cout << sizeDouble << "\n";
    
    int sizeChar = sizeof(char);
    cout << sizeChar << "\n";
    
    int sizeBool = sizeof(bool);
    cout << sizeBool << "\n";
    
    int sizeLong = sizeof(long);
    cout << sizeLong << "\n";
    
    int sizeSigned8 = sizeof(int8_t);
    cout << sizeSigned8 << "\n";
    
    int sizeSigned16 = sizeof(int16_t);
    cout << sizeSigned16 << "\n";
    
    int sizeUnSigned8 = sizeof(uint8_t);
    cout << sizeUnSigned8 << "\n";
    
    int sizeUnSigned16 = sizeof(uint16_t);
    cout << sizeUnSigned16 << "\n";
    
    int sizeSigned32 = sizeof(int32_t);
    cout << sizeSigned32 << "\n";
    
    int sizeUnSigned64 = sizeof(uint64_t);
    cout << sizeUnSigned64 << "\n";
    
    // Signed numbers
    int8_t minSigned8 = -0x7F;
    cout << "min of signed 8 is: " << +minSigned8 << "\n";

    int8_t maxSigned8 = 0x7F;
    cout << "max of signed 8 is: " << +maxSigned8 << "\n";

    int16_t minSigned16 = -0x7FFF;
    cout << "min of signed 16 is: " << +minSigned16 << "\n";

    int16_t maxSigned16 = 0x7FFF;
    cout << "max of signed 16 is: " << +maxSigned16 << "\n";

    int64_t minSigned64 = -0x7FFFFFFF;
    cout << "min of signed 64 is: " << +minSigned64 << "\n";

    int64_t maxSigned64 = 0x7FFFFFFF;
    cout << "max of signed 64 is: " << +maxSigned64 << "\n";
    
    // Unsigned numbers
    uint8_t minUnsigned8 = 0x00;
    cout << "min of unsigned 8 is: " << +minUnsigned8 << "\n";

    uint8_t maxUnsigned8 = 0xFF;
    cout << "max of unsigned 8 is: " << +maxUnsigned8 << "\n";
    
    uint16_t minUnsigned16 = 0x00;
    cout << "min of unsigned 16 is: " << minUnsigned16 << "\n";
    
    uint16_t maxUnsigned16 = 0xFFFF;
    cout << "max of unsigned 16 is: " << maxUnsigned16 << "\n";
    
    uint64_t minUnsigned64 = 0x00;
    cout << "min of unsigned 64 is: " << minUnsigned64 << "\n";
    
    uint64_t maxUnsigned64 = 0xFFFFFFFF;
    cout << "max of unsigned 64 is: " << maxUnsigned64 << "\n";
    
    // PART 2: Floating Point
    
    cout << setprecision(18); //print numbers to 18 digits of accuracy
    
    double computeDecimals = .1 + .2;
    assert(computeDecimals != .3);
    cout << "output for .1 + .2 is: " << computeDecimals << "\n";
    
    double a = .1;
    double b = .2;
    double tolerance = .01;
    approxEquals( a + b, .3, tolerance );
    
    
    // Part 3: Unicode/UTF-8
    
//    ifstream myStream ("UTF-8-demo.txt");

    char wordByWord;
    
    readUnicode( );
    
    
    return 0;
}
