//
//  BookAnalyzer.cpp
//  BookAnalyzer
//
//  Created by Polina Lyubavina on 9/6/21.
//

#include "BookAnalyzer.hpp"

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


//finds Title
string findTitle(vector <string> &allWords) {
    string bookTitle = "";
    for(int i = 0; i < allWords.size(); i++) {
        if(allWords[i] == "Title:") {
            for(int j = i; j < i + 100; j++) {
                if(allWords[j] == "Author:") {
                    return bookTitle;
                }
                bookTitle = bookTitle + allWords[j] + " ";
            }
            return "unknown";
        }
    }
    return "unknown";
}

//finds Authors
string findAuthor(vector <string> &allWords) {
    string bookAuthor = "";
    for(int i = 0; i < allWords.size(); i++) {
        if(allWords[i] == "Author:") {
            for(int j = i; j < i + 100; j++) {
                if(allWords[j] == "Release" && allWords[j+1] == "Date:") {
                    return bookAuthor;
                }
                bookAuthor = bookAuthor + allWords[j] + " ";
            }
            return "unknown";
        }
    }
    return "unknown";
}

//finds total number of words
int totalWords(vector <string> &allWords) {
    int totalWordsNum = (int)allWords.size();
    return totalWordsNum;
}

//finds total number of characters
int totalCharacters(vector <string> &allWords) {
    int totalNumChar = 0;
    for(int i = 0; i < allWords.size(); i++) {
        totalNumChar += allWords[i].length();
    }
    return totalNumChar;
}

// finds shortest word in book
string findShortest(vector<string> &allWords) {
    string shortestWord = allWords[0];
    for(int i = 0; i < allWords.size(); i++) {
        if(shortestWord.length() > allWords[i].length()) {
            shortestWord = allWords[i];
        }
    }
    return shortestWord;
}

// finds longest word in book
string findLongest(vector<string> &allWords) {
    string longestWord = allWords[0];
    for(int i = 0; i < allWords.size(); i++) {
        if(longestWord.length() < allWords[i].length()) {
            longestWord = allWords[i];
        }
    }
    return longestWord;
}

string lower(string toConvert) {
    for (int i = 0; i < toConvert.length(); i++) {
        toConvert[i] = tolower(toConvert[i]);
    }
    return toConvert;
}

// finds keyword occurences
void findKeyword(vector<string> &allWords, string keyword) {
    vector<string> occurences (0);
    vector<int> numCharPassed (0);
    int charPassedThusFar = 0;
    for(int i = 0; i < allWords.size(); i++) {
        if(lower(allWords[i]) == lower(keyword)) {
            if(i == 0) {
                occurences.push_back(allWords[i] + " " + allWords[i + 1]);
                numCharPassed.push_back(charPassedThusFar);
            }
            else if(i == allWords.size()-1) {
                occurences.push_back(allWords[i - 1] + " " + allWords[i]);
                numCharPassed.push_back(charPassedThusFar);
            }
            else {
                occurences.push_back(allWords[i - 1] + " " + allWords[i] + " " + allWords[i + 1]);
                numCharPassed.push_back(charPassedThusFar);
            }
        }
        charPassedThusFar += allWords[i].length();
    }
    
    int bookTotalCharacters = totalCharacters(allWords);
    
    cout << "The word \"" << keyword << "\" appears " << occurences.size() << " times: \n";
    for(int i = 0; i < occurences.size(); i++) {
        cout << " at " << 100 * numCharPassed[i] / bookTotalCharacters << "%: " << occurences[i] << "\n";
    }
}

// finds if a character is a terminator.
bool IsTerminator(char c) {
    return (c == 33 || c == 46 || c == 63);
};

// finds if a letter is capital
bool findCapital(char c) {
    return (c >= 65 && c <= 90 );
}

// finds if letter is lower case.
bool IsLower(char c) {
    return (c >= 97 && c <= 122);
}

// finds if letter is a digit.
bool IsDigit(char c) {
    return (c >= 48 && c <= 57);
}

// Determines whether or not a word contains only digits, and none others.
bool IsDecimalWord( const string & word ) {
    for(int i = 0; i < word.length(); i++) {
        if(!IsDigit(word[i])) {
            return false;
        }
    }
    return true;
}

// finds capital letter
void properNoun(vector<string> &allWords) {
    vector<string> occurences (0);
    vector<int> numCharPassed (0);
    int charPassedThusFar = 0;
    
    for(int i = 0; i < allWords.size(); i++) {
        if(findCapital(allWords[i][0])) {
            if(i == 0) {
                occurences.push_back(allWords[i] + " " + allWords[i + 1]);
                numCharPassed.push_back(charPassedThusFar);
            }
            else if(i == allWords.size()-1  && !IsTerminator(allWords[i - 1][allWords[i - 1].length() - 1])) {
                occurences.push_back(allWords[i - 1] + " " + allWords[i]);
                numCharPassed.push_back(charPassedThusFar);
            }
            else if (!IsTerminator(allWords[i - 1][allWords[i - 1].length() - 1])) {
                occurences.push_back(allWords[i - 1] + " " + allWords[i] + " " + allWords[i + 1]);
                numCharPassed.push_back(charPassedThusFar);
            }
        }
        charPassedThusFar += allWords[i].length();
    }

    int bookTotalCharacters = totalCharacters(allWords);

    cout << "There are " << occurences.size() << " proper nouns: \n";
    for(int i = 0; i < occurences.size(); i++) {
        cout << " at " << 100 * numCharPassed[i] / bookTotalCharacters << "%: " << occurences[i] << "\n";
    }
}

// helper function not called in main
string reverseString(string input) {
    string output = "";
    for (int i = (int)input.length() - 1; i >= 0; i--) {
        output += input[i];
    }
    return output;
}

// decimal to binary.
string DecimalToBinary ( const string & word ) {
    string tempNum = "";
    if(!IsDecimalWord(word)) {
        cout << "Not a decimal word.\n";
        return word;
    }
    int intValue = stoi(word);
    while(intValue != 0) {
        if(intValue % 2 == 0) {
            tempNum += '0';
        }
        else if(intValue % 2 == 1) {
            tempNum += '1';
        }
        intValue = intValue / 2;
    }
    return reverseString(tempNum);
}

// Returns whether or not the character is ., ?, !, or ,.
bool IsPunctuation(char c) {
    return (IsTerminator(c) || c == 44);
};


// Returns the encoded version of the input string.
string EncodeWord( string word, int secretKey ) {
    if(IsDecimalWord(word)) {
        return DecimalToBinary(word);
    }
    else {
        for(int i = 0; i < word.length(); i++) {
            if( IsPunctuation(word[i]) ){
                
            }
            else if ( IsLower(word[i]) ) {
                word[i] = (((word[i] - 97) + secretKey) % 26) + 97;  // - 97 because ASCII low case letter starts there
            }
            else {
                word[i] = (((word[i] - 65) + secretKey) % 26) + 65;
            }
        }
    }
    return word;
}
