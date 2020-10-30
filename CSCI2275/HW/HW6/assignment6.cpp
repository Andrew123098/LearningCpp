#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "LinkedList.h"
#include "BST.h"

// g++ -std=c++11 LinkedList.cpp BST.cpp assignment6.cpp -o assignment6
// ./assignment6 Hemingway_edit.txt >> output.txt
void compareOps(int numLines, char *arg);

using namespace std;

int main(int argc, char *argv[]){
    ifstream book;
    string data;
    book.open(argv[1]);
    
    // throw an error if we couldn't open the file
    if (!book){
        cout << "Error: Could not open file for reading" << endl;
        return 0;
    }
    
    LL myLL;
    BST myBST;

    string word;
    while(getline(book,data,' ')){
        stringstream ss(data);
        getline(ss,word);
        myLL.addWords(word);
        myBST.addWordNode(word); // sometimes adds 2 of the same node
    }     

for(int i = 200; i <= 1600; i+=200){
  compareOps(i, argv[1]);
}

cout<<endl;

myLL.countNodes();                 
myLL.countTotalWords();      
myBST.countBSTNodes();             
myBST.countBSTWords();

cout<<endl;

string dmenu = "======Main Menu=====\n"
					"1. Print Word\n"
					"2. Print Tree in Order\n"
          "3. Find Words in Range\n"
          "4. Quit\n";
int choice;
bool exit = false;
    
cout << dmenu << endl;
    
while(cin >> choice) {
        
    // flush the newlines and other characters
    cin.clear();
    cin.ignore();
    
    switch (choice) {
        case 1:
        { //Print a word from the tree.
          string toPrint;
          cout<<"Please enter a word from the book to print: ";
          cin>>toPrint;
          cout<<endl;
          myBST.printWord(toPrint);
          break;
        }
            
        case 2:
        { //Print tree in order
          myBST.printInOrderBST(); 
          break;
        }
        
        case 3:
        { // Print in Range
          string min, max;
          cout<<"Please enter the first word of the range: ";
          cin>>min;
          cout<<endl;
          cout<<"Please enter the second word of the range: ";
          cin>>max;
          cout<<endl;
          myBST.findAlphaRange(min, max); 
          break;
        }
            
        case 4:
        { // Quit
          exit = true;
          break;
        }
    }
    if (exit) {
            break;
        } else {
        cout << endl << dmenu << endl;
        }
  }
return 0;
}

// This function compares the average number of comparisons it takes to build a LL vs a BST.
void compareOps(int numLines, char *arg){
  ifstream book;
  book.open(arg);

  LL myLL;
  BST myBST;

  int LLops = 0;
  int BSTops = 0;
  int loopCounter = 0;
  float LLMean = 0;
  float BSTMean = 0;
  string line, word, data;

  for(int i = 0; i < numLines; i++){
    getline(book,line);
    stringstream ss1(line);
    while(getline(ss1,data,' ')){
      stringstream ss2(data);
      getline(ss2,word);
      LLops = myLL.addWords(word);
      BSTops = myBST.addWordNode(word);
      loopCounter++;
      LLMean+=LLops;
      BSTMean+=BSTops;
    }
  }
  LLMean/=loopCounter;
  BSTMean/=loopCounter;

  cout<<"Lines: "<<numLines<<" | LL Avg. Operations: "<<LLMean<<" | BST Avg. Operations: "<<BSTMean<<endl;

}