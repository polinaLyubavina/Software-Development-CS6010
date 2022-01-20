//
//  Poker.cpp
//  Poker
//
//  Created by Polina Lyubavina on 9/1/21.
//

#include "Poker.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;


//defines suits to use for cards
vector<string> suits = { "clubs", "diamonds", "hearts", "spades" };


//creates deck
vector<Card> createDeck()
{
    vector<Card> deck = {};
    for(string s : suits)
    {
        for( int i = 1; i < 14; i++ )
        {
            Card newcard;
            newcard.rank = i;
            newcard.suit = s;
            deck.push_back( newcard );
        }
    }
    return deck;
}

//creates test deck
//vector<Card> createTestDeck()
//{
//    vector<Card> testdeck = {};
//    for(char s; s < 1; s++)
//    {
//     //   char randCards = rand(1, 4);
//        for( int i = 1; i < 6; i++ )
//        {
//            Card testcard;
//            testcard.rank = i;
//            testcard.suit = s;
//            testdeck.push_back( testcard );
//        }
//    }
//    return testdeck;
//}

//prints deck
void printDeck(vector <Card> deck)
{
    for(Card c : deck)
    {
        if(c.rank == 13) {
            cout << "K" << " of " << c.suit << "\n";
        } else if (c.rank == 12) {
            cout << "Q" << " of " << c.suit << "\n";
        } else if (c.rank == 11) {
            cout << "J" << " of " << c.suit << "\n";
        } else if (c.rank == 1) {
            cout << "A" << " of " << c.suit << "\n";
        } else {
            cout << c.rank << " of " << c.suit << "\n";
        }
    }
}


//shuffles a deck of cards
void shuffleDeck(vector <Card> & deck) { //takes a reference to a deck of cards

//    int j = 0;
    for(int i = deck.size() - 1; i >= 0; i--)
    {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

//checks if sorted
bool isSorted(vector <Card> cardsToCheck)
{
    
    for(int i = 0; i < cardsToCheck.size() - 1; i++ )
    {
        
        if(cardsToCheck[i].rank > cardsToCheck[i + 1].rank)
        {
            
            return false;
        }
    }
    return true;
}

//sorts a vector of Cards
void sortHand( vector<Card> & cardsToSort )
{
    
    while( !isSorted(cardsToSort))
    {
        
        for(int i = 0; i < cardsToSort.size() - 1; i++ )
        {
            
            if(cardsToSort[i].rank >= cardsToSort[i + 1].rank)
            {
                Card temp = cardsToSort[i];
                cardsToSort[i] = cardsToSort[i + 1];
                cardsToSort[i + 1] = temp;
            }
        }
    }
}


//asks if all the cards are the same suit
bool isFlush(vector <Card> testhand)
{
    if(testhand[0].suit == testhand[1].suit && testhand[1].suit == testhand[2].suit && testhand[2].suit == testhand[3].suit && testhand[3].suit == testhand[4].suit && testhand[4].suit == testhand[5].suit)
    {
        return true; 
    } else {
        return false;
    }
}

//asks if all cards are in numerical order
bool isStraight(vector <Card> testhand)
{
    sortHand(testhand);

    for( int i = 0; i < testhand.size() - 1; i++)
    {
        if(testhand[i + 1].rank == testhand[i].rank + 1)
        {
        } else {
            return false;
        }
    }
    return true;
}


//asks if the hand is straight or a flush
bool isStraightFlush(vector <Card> testhand)
{
    if((isStraight(testhand)) && (isFlush(testhand)))
    {
        return true;
    } else {
        return false;
    }
}

//asks if the hand is a straight flush whose low card is a ten
bool isRoyalFlush(vector <Card> testhand)
{
    if((isStraightFlush(testhand)) && (testhand[0].rank == 10))
    {
        return true;
    } else {
        return false;
    }
}


//asks if there are 3 of one rank, and 2 of another
bool isFullHouse(vector <Card> testhand)
{
    sortHand(testhand);
    
    if((testhand[0].rank == testhand[1].rank && testhand[1].rank == testhand[2].rank) && (testhand[3].rank == testhand[4].rank))
    {
        return true;
    }
    if((testhand[0].rank == testhand[1].rank) && (testhand[2].rank == testhand[3].rank && testhand[3].rank == testhand[4].rank))
    {
        return true;
    }
    else
    {
        return false;
    }
}



