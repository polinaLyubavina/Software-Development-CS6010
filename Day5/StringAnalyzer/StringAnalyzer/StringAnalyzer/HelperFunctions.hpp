//
//  HelperFunctions.hpp
//  StringAnalyzer
//
//  Created by Polina Lyubavina on 8/30/21.
//

#ifndef HelperFunctions_hpp
#define HelperFunctions_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;



int NumWords(string s);
int NumLetters(string s);
int NumSentences(string s);
int NumVowels(string s);
int NumConsonants(string s);

double AverageWordLength(string s);
double AverageVowelsPerWord(string s);

#endif /* HelperFunctions_hpp */
