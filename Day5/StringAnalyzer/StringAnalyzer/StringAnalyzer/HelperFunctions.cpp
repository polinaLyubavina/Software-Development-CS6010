//
//  HelperFunctions.cpp
//  StringAnalyzer
//
//  Created by Polina Lyubavina on 8/30/21.
//

#include "HelperFunctions.hpp"
#include "LetterHelpers.hpp"
#include <string>
#include <iostream>

using namespace std;


// Returns the number of words in the string.
int NumWords(string s) {
    int words = 1;
    
    for(int x = 0; x < s.length(); x++) {
        if ( IsSpace(s[x])) {
            words++;
        }
    }

    return words;
};

// Returns the number of letters in the string.
int NumLetters(string s) {
    int letters = 0;
    
    for(int x = 0; x < s.length(); x++) {
        if(IsLetter(s[x])) {
            letters++;
        }
    }
    
    return letters;
};

// Returns the number of sentences in the string.
int NumSentences(string s) {
    int sentences = 0;
    
    for(int x = 0; x < s.length(); x++) {
        if ( IsTerminator(s[x])) {
            sentences++;
        }
    }
    
    return sentences;
};

// Returns the number of vowels in the string.
int NumVowels(string s) {
    int vowels = 0;
    
    for(int x = 0; x < s.length(); x++) {
        if ( IsVowel(s[x])) {
            vowels++;
        }
    }
    
    return vowels;
};

// Returns the number of consonants in the string.
int NumConsonants(string s) {
    int consonants = 0;
    
    for(int x = 0; x < s.length(); x++) {
        if ( IsConsonant(s[x])) {
            consonants++;
        }
    }
    
    return consonants;
};

// Returns the average length of all words in the string.
double AverageWordLength(string s) {
    double averageWordLength = 0;
    
    averageWordLength = ((double) NumLetters(s) / (double) NumWords(s));
    
    return averageWordLength;
};

// Returns the average number of vowels per word in the string.
double AverageVowelsPerWord(string s) {
    double averageVowels = 0;
    
    averageVowels = ((double) NumVowels(s) / (double) NumWords(s));
    
    return averageVowels;
};

// Returns reading level

