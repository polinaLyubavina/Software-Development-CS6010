//
//  Poker.hpp
//  Poker
//
//  Created by Polina Lyubavina on 9/1/21.
//

#ifndef Poker_hpp
#define Poker_hpp

#pragma once

#include <iostream>
#include <stdio.h>
#include <string>


//declares structure Card
struct Card
{
    int rank;           // Ace : 1, Jack : 11, Queen : 12, King : 13.
    std::string suit;   // clubs, diamonds, hearts, and spades.
};

//creates deck
std::vector<Card> createDeck();

//prints deck
void printDeck(std::vector<Card> deck);

//test decks
//std::vector<Card> createTestDeck();

//shuffles a deck of cards
void shuffleDeck(std::vector <Card> & deck);

//asks if all the cards are the same suit
bool isFlush(std::vector <Card> testhand);

//asks if all cards are in numerical order
bool isStraight(std::vector <Card> testhand);

//asks if the hand is straight or a flush
bool isStraightFlush(std::vector <Card> testhand);

//asks if the hand is a straight flush whose low card is a ten
bool isRoyalFlush(std::vector <Card> testhand);

//asks if there are 3 of one rank, and 2 of another
bool isFullHouse(std::vector <Card> testhand);

//sorts a vector of Cards
void sortHand( std::vector<Card> & cardsToSort );

//checks if sorted
bool isSorted(std::vector <Card> cardsToCheck);


#endif /* Cards_hpp */
