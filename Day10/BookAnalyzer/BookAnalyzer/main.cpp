//
//  main.cpp
//  BookAnalyzer
//
//  Created by Polina Lyubavina on 9/3/21.
//

#include "BookAnalyzer.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <map>

using namespace std;

int main(int argc, const char * argv[]) {
    // asks user to input a book name and keyword
    string bookFile;
    string command;
    
    if(argc > 1) {
        bookFile = argv[1];
        command = argv[2];
    }

    cout << bookFile;
    cout << command;


    //ensures the file name/book exists
    if( !(bookFile == "Thackeray_VanityFair.txt" || bookFile == "Tolstoy_AnnaKarenina.txt" || bookFile == "Tolstoy_OnTheSignificanceOfScienceAndArt.txt" || bookFile == "Tolstoy_WarAndPeace.txt" || bookFile == "dune.txt" || bookFile == "dune_encoded.txt") )
        {
            cout << "This book file: '" << bookFile << "' does not exist in our library. Try again later. Bye!\n";
            return(1);
        }
    
    ifstream myStream (bookFile);
    
    // ------------------------------------------------ //
        
    std::set<string> tempwords;
    
    // from key string to value int.
    std::map<string, int> wordCount;
    
    string tempword;
        
    
    // creates vector to store all words from file into
    vector<string> allWords (0);
//    string tempwords;
    while(myStream >> tempword)
    {
//        allWords.push_back(tempwords);
        tempwords.insert(tempword);
        wordCount[ tempword ]++;
    }
    

//    for( pair< const string, int> kvp : wordCount ) {
//        cout << kvp.first << " has # of words: " << tempwords.size() << "\n";
//    }
    
    int largestCount = -1;
    string popWord = " ";
    for(map<string, int>::iterator iter = wordCount.begin(); iter != wordCount.end(); iter++ ) {
        if( iter->second > largestCount) {
            largestCount = iter->second;
            popWord = iter-> first;
        }
    }
    cout << "Most popular word '" << popWord << "' occurred x times: " << largestCount << "\n";
        
    cout << "Number of unique words is: " << tempwords.size() << "\n";
        
    // ------------------------------------------------ //


    
    myStream.close(); 
    
    if (command != "-encode") {
        cout << "\nStatistics:\n";
        cout << findTitle(allWords) << "\n";
        cout << findAuthor(allWords) << "\n";
        cout << "Total words: " << totalWords(allWords) << "\n";
        cout << "Total characters: " << totalCharacters(allWords) << "\n";
        cout << "Shortest word: " << findShortest(allWords) << "\n";
        cout << "Longest word: " << findLongest(allWords) << "\n\n";
        properNoun(allWords);
        findKeyword(allWords, command);
    } else {
        if (argc != 4) {
            cout << "Wrong number of arguments passed. Doing nothing. \n";
            exit(1);
        }
        
        int encodingOffset = atoi(argv[3]);
        
        for(int i = 0; i < allWords.size(); i++) {
           allWords[i] = EncodeWord(allWords[i], encodingOffset);
        }
        
        string outputFileName = bookFile.insert(bookFile.rfind("."), "_encoded");
        ofstream outputStream (outputFileName);
        
        for (string s : allWords) {
            outputStream << s << " ";
        }
        
        outputStream.close();
        
    }
    
    return 0;
}
