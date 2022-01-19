//
//  LetterHelpers.cpp
//  StringAnalyzer
//
//  Created by Polina Lyubavina on 8/30/21.
//

#include "LetterHelpers.hpp"


// Returns whether or not the character is a letter.
bool IsLetter(char c) {
    return ((c >= 65 && c <= 90) || (c>= 97 && c<= 122));
}


// Returns whether or not the character is a vowel.
bool IsVowel(char c) {
    return ( c == 65 || c == 97 || c == 69 || c == 101 || c == 79 || c == 111 || c == 73 || c == 105 || c == 85 || c == 117 || c == 89 || c == 121);
};


// Returns whether or not the character is a consonant.
bool IsConsonant(char c) {
    return ( !IsVowel(c) && IsLetter(c));
};


// Returns whether or not the character is a " " space.
bool IsSpace(char c) {
    return (c == 32);
}


// Returns whether or not the character is ., ?, or !.
bool IsTerminator(char c) {
    return (c == 33 || c == 46 || c == 63);
};


// Returns whether or not the character is ., ?, !, or ,.
bool IsPunctuation(char c) {
    return (IsTerminator(c) || c == 44);
};
