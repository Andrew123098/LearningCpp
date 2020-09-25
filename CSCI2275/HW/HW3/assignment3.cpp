// ==========================================
// Filename: Assignment3.cpp
// Author: Rhonda Hoenigman
// Date: 9/15/2020
// Description: Counts unique words in a file
// outputs the top N most common words
// Uses TextAnalyzer class
// ./Assignment3 10 HungerGames_edit.txt ignoreWords.txt
// g++ -std=c++11 assignment3.cpp -o assignment3
// ==========================================

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "TextAnalyzer.h"
using namespace std;

// main expects 2 arguments, filename and number of top words
int main(int argc, char* argv[])
{
    ifstream inStream;      // stream for reading in file
    bool commonWord;        // flag for whether word is common word
    string word;
    bool wordFound;

    // verify we have the correct number of parameters, else throw error msg & return
    if (argc != 4)
    {
        cout << "Usage: Assignment3Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
        return 0;
    }

    int numCommon = atoi(argv[1]);
    TextAnalyzer *ta = new TextAnalyzer(argv[3]);

    // // DYNAMIC MEMORY EXERCISE #1
    // cout<<"DYNAMIC MEMORY EXERCISE #1:"<<endl;

    // int size = 10;                    // Size of dynamically allocated array.
    // wordItem *p = new wordItem[size]; // Create dynamically allocated array of wordItem struct.
    // for (int i = 0; i < size; i++){   // Set default values for the array of structs.
    //     p[i].count = 0;
    //     p[i].word = 'a';
    //     cout<<"Index "<<i<<" in array has count = "<<p[i].count<<" and word = "<<p[i].word<<endl;
    // }
    // cout<<endl<<"END"<<endl<<endl;

    // // DYNAMIC MEMORY EXERCISE #2
    // cout<<"DYNAMIC MEMORY EXERCISE #2:"<<endl;

    // string sinputIndex;
    // int inputIndex;
    // // Ask the use to input an index.
    // do {
    //     cout<<"Please enter an index of value 0 to "<<size-1<<": ";
    //     cin>>sinputIndex;
    //     cout<<endl;
    //     inputIndex = stoi(sinputIndex);
    // } while(inputIndex < 0 || inputIndex > size-1);

    // // Put that index into the dynamically allocated array.
    // for (int i = size-1; i > inputIndex; i--){
    //     p[i] = p[i-1];
    // }
    // p[inputIndex].word = "test";
    // p[inputIndex].count = 99;

    // // Print out the array
    // for(int i = 0; i <= size-1; i++){
    //     cout<<"Index "<<i<<" in array has count = "<<p[i].count<<" and word = "<<p[i].word<<endl;
    // }

    // cout<<endl<<"END"<<endl<<endl;

    // // DYNAMIC MEMORY EXERCISE #3
    // cout<<"DYNAMIC MEMORY EXERCISE #3:"<<endl;

    // // Ask the user to input an index.
    // string sinputIndex2;
    // int inputIndex2;
    // do {
    //     cout<<"Please enter an index of value 0 to "<<size-1<<": ";
    //     cin>>sinputIndex2;
    //     cout<<endl;
    //     inputIndex2 = stoi(sinputIndex2);
    // } while(inputIndex2 < 0 || inputIndex2 > size-1);

    // wordItem *p2 = new wordItem[size*2];

    // for(int i = 0; i < inputIndex2; i++){
    //     p2[i].word = p[i].word;
    //     p2[i].count = p[i].count;
    // }

    // p2[inputIndex2].word = "test2";
    // p2[inputIndex2].count = 100;

    // for(int i = inputIndex2+1; i <= size; i++){
    //     p2[i].word = p[i-1].word;
    //     p2[i].count = p[i-1].count;
    // }
    // delete []p;
    
    // // Print out the array
    // for(int i = 0; i <= size; i++){
    //     cout<<"Index "<<i<<" in array has count = "<<p2[i].count<<" and word = "<<p2[i].word<<endl;
    // }

    // cout<<endl<<"END"<<endl;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // open the file
    inStream.open(argv[2]);

    // throw an error if we couldn't open the file
    if (!inStream)
    {
        cout << "Error: Could not open file for reading" << endl;
        return 0;
    }

    // loop until the end of the file
    while (!inStream.eof())
    {
        // read in a word
        inStream>>word;
        wordFound = ta->insertWord(word); //the insertWord method will call isIgnoreWord
        if(wordFound){
            //cout<<"Word added: "<<word<<endl;
        }else{
            //cout<<"Word is common word"<<endl;
        }
    }
    // close the file
    inStream.close();

    // sort the array by word count, should be currently in alpha order
    ta->sortByWordCount();
    cout<<"Sorted by word count"<<endl;
 
    // print out the top N most common words in the document
    ta->printTopN(numCommon);
    // print how many time the array doubled
    cout << "#" << endl;
    cout << "Array doubled: " << ta->getNumDoublings() << endl;
    // print the unique non-common words
    cout << "#" << endl;
    cout << "Unique non-common words: "<< ta->getNumberOfUniqueWords() <<endl;
  
    // print out the total number of non-common words
    cout << "#" << endl;
    cout << "Total non-common words: " << ta->getTotalNonCommonWords() << endl;
    
    return 0;
}

