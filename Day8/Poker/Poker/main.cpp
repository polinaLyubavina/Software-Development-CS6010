//
//  main.cpp
//  Poker
//
//  Created by Polina Lyubavina on 9/1/21.
//

#include "Poker.hpp"

#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

int main() {
    
    vector<Card> deck = createDeck();

    printDeck(deck);
    
    //create a test hand
    vector<Card> testhand(5);
    
    Card cardone;
    cardone.rank = 1;
    cardone.suit = "hearts";
    testhand.push_back( cardone );
    
    Card cardtwo;
    cardone.rank = 7;
    cardone.suit = "hearts";
    testhand.push_back( cardtwo );
    
    Card cardthree;
    cardone.rank = 8;
    cardone.suit = "hearts";
    testhand.push_back( cardthree );
    
    Card cardfour;
    cardone.rank = 11;
    cardone.suit = "spades";
    testhand.push_back( cardfour );
    
    Card cardfive;
    cardone.rank = 12;
    cardone.suit = "spades";
    testhand.push_back( cardfive );
    
    
//Analysis
    
    //creates a second hand to test
    vector<Card> secondhand;
    shuffleDeck(deck);
    
    for(int i = 0; i < 5; i++)
    {
        secondhand.push_back(deck[i]);
    }
    printDeck(secondhand);
    
    isFlush(secondhand);
    cout << "1\n";  // test how far program got
    
    isStraight(secondhand);
    cout << "2\n";  // test how far program got

    isStraightFlush(secondhand);
    cout << "3\n";  // test how far program got

    isRoyalFlush(secondhand);
    cout << "4\n";  // test how far program got

    isFullHouse(secondhand);
    cout << "5\n";  // test how far program got


    
    
    return 0;
}
