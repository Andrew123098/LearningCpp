//
//  Exam3.cpp
//  CSCI 2275
//

#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "BST.h"
#include "Graph.h"

using namespace std;

void die(string message) {
    cout << message << endl;
    exit(0);
}
string removeSpecialCharacters(string s){
    for (int i = 0; i < s.size(); i++) { 
          
        // Finding the character whose  
        // ASCII value fall under this 
        // range 
        if ((s[i] < 'A' || s[i] > 'Z') && 
            (s[i] < 'a' || s[i] > 'z'))  
        {    
            // erase function to erase  
            // the character 
            s.erase(i, 1);  
            i--; 
        } 
    } 
    return s; 
}

int PopulateBST(BST* bst, string filename) {
    ifstream file(filename);
    
    // non-existant or corrupted file
    if(file.fail()) {
        die("Check if file exists!");
    }
    
    string title, word, line;
    int count;
    while(std::getline(file, line, ' ')) {
        line = removeSpecialCharacters(line);
        
        count = bst->addWordNode(line);

    }
    return count;
}

int main(int argc, const char * argv[]) {

    BST bst;
    Graph g;
    string filename(argv[1]);
    int count = 0;
    count = PopulateBST(&bst, filename);
    cout<<count<<" words added to BST"<<endl;
    bst.printPreOrderBST();

    bst.buildVerticesFromBST(&g);
    bst.buildEdgesFromBST(&g);
    g.displayEdges();
    
    return 0;
}
