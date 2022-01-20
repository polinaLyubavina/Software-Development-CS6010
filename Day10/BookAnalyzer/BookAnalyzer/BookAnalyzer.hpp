//
//  BookAnalyzer.hpp
//  BookAnalyzer
//
//  Created by Polina Lyubavina on 9/6/21.
//

#ifndef BookAnalyzer_hpp
#define BookAnalyzer_hpp

#include <stdio.h>
#include <string>
#include <vector>


//finds Title
std::string findTitle(std::vector <std::string> &allWords);

//finds Author
std::string findAuthor(std::vector <std::string> &allWords);

//finds total number of words
int totalWords(std::vector <std::string> &allWords);

//finds total number of characters
int totalCharacters(std::vector <std::string> &allWords);

// finds shortest word in book
std::string findShortest(std::vector<std::string> &allWords);

// finds longest word in book
std::string findLongest(std::vector<std::string> &allWords);

// finds keyword occurences
void findKeyword(std::vector<std::string> &allWords, std::string keyword);

// finds proper nouns
void properNoun(std::vector<std::string> &allWords);

// finds if a letter is capital
bool findCapital(char c);

// finds if a character is a terminator.
bool IsTerminator(char c);

// Returns whether or not the character is ., ?, !, or ,.
bool IsPunctuation(char c);

// finds if a letter is lower case.
bool IsLower(char c);

// finds if letter is a digit.
bool IsDigit(char c);

// Determines whether or not a word contains only digits, and none others.
bool IsDecimalWord( const std::string & word );

// decimal to binary.
std::string DecimalToBinary ( const std::string & word );

// Returns the encoded version of the input string.
std::string EncodeWord( std::string word, int secretKey );

#endif /* BookAnalyzer_hpp */
