//
//  main.cpp
//  StringAnalyzer
//
//  Created by Polina Lyubavina on 8/28/21.
//

#include "LetterHelpers.hpp"

#include "HelperFunctions.hpp"


#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
#include <ctime>

using namespace std;






int main() {
    
    string userInput;
    
    // Asks user to input a string.
    cout << "Enter a string containing one or more sentences: \n";
    getline(cin, userInput);
    
    while (userInput != "done") {
        cout << "Analysis: \n";
        
        cout << " Number of words: " << NumWords(userInput) << "\n";
        
        cout << " Number of sentences: " << NumSentences(userInput) << "\n";
        
        cout << " Number of vowels: " << NumVowels(userInput) << "\n";
        
        cout << " Number of consonants: " << NumConsonants(userInput) << "\n";
        
        cout << " Reading level (average word length): " << AverageWordLength(userInput) << "\n";

        cout << " Average vowels per word: " << AverageVowelsPerWord(userInput) << "\n";
        
        // Asks user to input a string.
        cout << "Enter a string containing one or more sentences: \n";
        getline(cin, userInput);
    };
    
    cout << "Goodbye.\n";
    
    return 0;
}
