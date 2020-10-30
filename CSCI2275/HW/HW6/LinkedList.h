//
//  Assignment6.h
//  Assignment6
//
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

struct Node{
    string word;
    int count;
    Node *next;
    Node *previous;
    Node(){}; // default constructor
    
    Node(string initWord, int initCount, Node *initNext, Node *initPrevious)
    {
        word = initWord;
        count = initCount;
        next = initNext;
        previous = initPrevious;
    }

};
class LL
{
public:
    LL();
    void buildLL(string words[], int counts[], int LLSize);
    void printLL();
    int addWords(string word);
    void prepend(string word, int count);
    void append(string word, int count);
    int searchLL(string word);
    void countNodes();
    void countTotalWords();
protected:
private:
    Node *head;//head of the linked list
    Node *tail;//tail of the linked list
    void addNode(string word, Node *previousNode);
};

#endif // TRAIN_H


