//
//  main.cpp
//  MakeYourOwnVector
//
//  Created by Polina Lyubavina on 9/13/21.
//

#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <numeric>


#include "MakeYourOwnVector.hpp"

using namespace std;

// finds even number for count_if 
bool isEven( int & n) {
    if(n % 2 == 2) {
    }
    return n;
}


int main(int argc, const char * argv[]) {

    Vector<int> firstTest(2);
    
// Tests
    
//    assert(myVector != 0);
    
    assert( firstTest.getCapacity() == 2 );
    assert( firstTest.getSize() == 0 );
    
    firstTest.pushBack(4);
    firstTest.pushBack(14);
    firstTest.pushBack(32);
    
    assert( firstTest.get(0) == 4 );
    assert( firstTest.get(1) == 14 );
    assert( firstTest.get(2) == 32 );
    
    // assert for [] subscript overload
    assert( firstTest[0] == 4 );
    assert( firstTest[1] == 14 );
    assert( firstTest[2] == 32 );
    
    Vector<int> secondTest = firstTest;
    
    secondTest[2] = 8;
    
    cout << "Old vector: " << firstTest[0] << " " << firstTest[1] << " " << firstTest[2] << "\n";
    cout << "New vector: " << secondTest[0] << " " << secondTest[1] << " " << secondTest[2] << "\n";
    
    assert( secondTest[0] == 4 );
    assert( secondTest[1] == 14 );
    assert( secondTest[2] == 8 );
    
    assert( secondTest.popBack() == 8 );
    assert( secondTest.popBack() == 14 );
    assert( secondTest.popBack() == 4 );
    
    assert( secondTest.getCapacity() == 4 );
    
    for ( int i = 0; i < 1000; i++ ) {
        secondTest.pushBack( i * 2 );
    }
    
    assert( secondTest.getSize() == 1000 );
    assert( secondTest.getCapacity() == 1024 );
    assert( secondTest.get( 666 ) == 666 * 2 );
    
//  --------------------------------------------------------------------  //

    // create new test Vector
    Vector<int> thirdTest(6);
    thirdTest.pushBack(2);
    thirdTest.pushBack(1);
    thirdTest.pushBack(5);
    thirdTest.pushBack(3);
    thirdTest.pushBack(90);
    thirdTest.pushBack(6);

    
//     sorts Vector
    std::sort( thirdTest.begin(), thirdTest.end() );
    
    // prints Vector
    for(int x : thirdTest) {
        cout << "Third test sorted: " << x << "\n";
    }
    
    // min_element
   auto minValue = *min_element( thirdTest.begin(), thirdTest.end() );
    cout << "Min value is: " << minValue << "\n";
    
    // min_element
   int accumulateVector = std::accumulate( thirdTest.begin(), thirdTest.end(), 0 );
    cout << accumulateVector << "\n";
    
    // count_if even numbers
    auto count = count_if( thirdTest.begin(), thirdTest.end(), isEven);
    cout << "Even number: " << count << "\n";
    
//  --------------------------------------------------------------------  //

    
//    myVector.freeVector();
//    assert(myVector == 0);
    
//    cout << "Object is being deleted.\n";

    cout << "End of program.\n";
    
    return 0;
}
