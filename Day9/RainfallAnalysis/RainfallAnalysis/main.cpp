//
//  main.cpp
//  RainfallAnalysis
//
//  Created by Polina Lyubavina on 9/2/21.
//

#include "RainfallAnalysis.hpp"

#include <iostream>
#include <math.h>
#include <string>
#include <stdio.h>
//#include <cassert>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;


// Helper sort functions

int findSmallest(const vector<float> & numbers, int startIndex)
{
    int smallestIndex = startIndex;
    
    for(int i = startIndex + 1; i < numbers.size(); i++)
    {
        if(numbers[i] < numbers[smallestIndex])
        {
            smallestIndex = i;
        }
    }
    return smallestIndex;
}

float temp;
void swap(float & a, float & b)
{
    temp = a;
    a = b;
    b = temp;
}

string tempstring;
void swapstring(string & a, string & b)
{
    tempstring = a;
    a = b;
    b = tempstring;
}

int tempyear;
void swapyear(int & a, int & b)
{
    tempyear = a;
    a = b;
    b = tempyear;
}

void selectionSort(vector<float> & numbers, vector<string> months, vector<int> year)
{
    for(int i = 0; i < numbers.size(); i++)
    {
        int smallestIndex = findSmallest(numbers, i);
        
        swap(numbers[i], numbers[smallestIndex]);
        swapstring(months[i], months[smallestIndex]);
        swapyear(year[i], year[smallestIndex]);
    }
}


int main(int argc, const char * argv[]) {
    
    vector<string> filenames = {"Day9_AtlantaRainfall.txt", "Day9_MaconRainfall.txt"};
    ofstream appendOutputStream ("rainfall_results.txt", std::ios_base::app);
    //    outputStream << "CS 60110 Rainfall Analysis\n";
    appendOutputStream << "CS 60110 Rainfall Analysis\n";
    
    // sets decimal place to two
    appendOutputStream << std::fixed << std::setprecision(2);
    
    for(int i = 0; i < filenames.size(); i++)
        
    {
        string cityName;
        string filename = filenames[i];
        ifstream myStream (filename);
        
        if( myStream.fail() )
        {
            cout << "Fail to open file: " << filename << ".\n";
            exit(1);
        }
        
        // gets data from file to variables & vectors
        myStream >> cityName;
        
        vector<string> month;
        vector<int> year;
        vector<float> rainfall;
        
        string tempmonth;
        int tempyear;
        float temprainfall;
        
        while(myStream >> tempmonth >> tempyear >> temprainfall)
        {
            cout << "Read in: " << tempmonth << " " << tempyear << " " << temprainfall << "\n";
            month.push_back(tempmonth);
            year.push_back(tempyear);
            rainfall.push_back(temprainfall);
        }
        
        // begins data computations and sets output stream
        
    //    ofstream outputStream("rainfall_results.txt");
        appendOutputStream << "Rainfall data for " << cityName << "\n";
        appendOutputStream << "\n";
    
        
        // overall average rainfall function
        float overallRainfall = 0.0;
        
        for(int i = 0; i < month.size(); i++)
        {
            overallRainfall = overallRainfall + rainfall[i];
        }
        
        float averageRainfall = overallRainfall / (float) month.size();
        
        appendOutputStream << "The average rainfall amount is " << averageRainfall << "  inches.\n";
        
        // average rainfall per month
        vector<float> monthsOverall = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        
        for(int i = 0; i < month.size(); i++)
        {
          monthsOverall[i % 12] = monthsOverall[i % 12] + rainfall[i];
        }
        
        vector<float> monthsAverage = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        for(int i = 0; i < monthsOverall.size(); i++)
        {
            monthsAverage[i] = monthsOverall[i] / (float)(month.size()/12);
            
            appendOutputStream << "The average rainfall amount for " << month[i] << " is " << monthsAverage[i] << "inches.\n";
        }
        
        // Wettest months
        int rfsize = rainfall.size();
        
        selectionSort(rainfall, month, year);
        appendOutputStream << "\nThe rain amount (in inches) of the four wettest months is: " << rainfall[rfsize - 1] << " " << rainfall[rfsize - 2] << " " << rainfall[rfsize - 3] << " " << rainfall[rfsize - 4] << "\n";
        
        // Driest months
        selectionSort(rainfall, month, year);
        appendOutputStream << "The rain amount (in inches) of the four driest months is: " << rainfall[0] << " " << rainfall[1] << " " << rainfall[2] << " " << rainfall[3] << "\n\n";
        
        // Median
        float findMedian;
        
        selectionSort(rainfall, month, year);
        int rainMedianPos = rainfall.size() / 2;
        float rainMedian = rainfall[rainMedianPos];
        
        appendOutputStream << "The median month is: \n" << month[rainMedianPos] << " " << year[rainMedianPos] << " " << rainMedian << "\n\n";
        
        
    }
    
    return 0;
}
