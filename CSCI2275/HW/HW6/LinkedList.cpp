#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "LinkedList.h"

using namespace std;

LL::LL(){
/* Default constructor: Just set head and tail to NULL. */
    
    head = NULL;
    tail = NULL;
}

void LL::addNode(string word, Node *previousNode){
/* Insert a new car into the train after the previous. 
The name of the new car is in the argument name. */

// Create new Node.
Node *node = new Node(word, 1, previousNode->next, previousNode);
if(previousNode != tail)                  // If not making new tail node...
    previousNode->next->previous = node;  // Make the next node's previous pointer equal to the new node.
previousNode->next = node;                // Make the previous node's next pointer equal to the new node.
if(previousNode == tail)                  // If making a new tail node...
    tail = node;                          // set tail equal to the new node.
return;                                   // Return.
}


int LL::addWords(string word){
/* Add passengers to the car. The name of the car to add to is the argument name. 
If the car is full, this method should call addCar. */
    Node *crawler = head;                                           // Create crawler pointer.
    int opCounter = 0;                                              // Variable to count comparisons.
    if(tail == NULL){                                               // If the tail has not yet been created...
        tail = new Node(word, 1, NULL, NULL);                       // Assign first value to the tail.
        return 0;                                                   // Return.
    }
    if(tail != NULL && head == NULL){                               // If the tail has been assigned and the head has not...
        head = new Node(word, 1, tail, NULL);                       // Assign second value to the head.
        tail->previous = head;                                      // Connect head and tail.
        return 0;                                                   // Return.
    }
    
    while(crawler->next != nullptr){                                    // While the crawler->next is not the tail...
        if(word == crawler->word){                                      // If the word equals the crawler's word...
            crawler->count++;                                           // Increase the count of the node.
            opCounter++;                                                // Increase comparison counter.
            return opCounter;                                           // Return.
        } else if(crawler->word > word && crawler->previous != NULL){   // If the crawler word is greater than word and not at the head...
            opCounter++;                                                // Increase comparison counter.
            addNode(word,crawler->previous);                            // Add a node.
            return opCounter;                                           // Return.
        } else if(word > tail->word){                                   // If word is greater than the tail word...
            opCounter++;                                                // Increase comparison counter.
            addNode(word,tail);                                         // Add the node as the new tail.
            return opCounter;                                           // Return.
        } else if(crawler->word > word && crawler == head){             // If the word is first alphabetically...
            Node *node = new Node(word, 1, head, NULL);                 // Make new node.
            head->previous = node;                                      // Set head previous to the new head.
            head = node;                                                // Set head to the new node.
            opCounter++;                                                // Increase comparison counter.
            return opCounter;                                           // Return..
        }
        opCounter++;                                                 // Increase comparison counter.
        crawler = crawler->next;                                     // Move crawler down the list
    }
    return -1;
}

void LL::printLL(){
/* Start at the head of the train and print the name and occupancy of each car in 
order to the end of the train, and then back again to the head of the train. */
    cout<<endl<<"Print Linked List:"<<endl;             // Format Title
    if (head == nullptr) {                              // If the LL hasn't been made yet...
        cout << "empty LL" << endl;                     // Return error message.
        return;                                         // Exit function.
    }
    Node *crawler = head;                               // Create crawler pointer.
    while(crawler != tail) {                            // While the crawler is not the tail...
        cout<<crawler->word<<":"<<crawler->count;       // Print the Node values.
        cout << "-->";                                  // Print an arrow.
        crawler = crawler->next;                        // Point crawler to next node.
        }
    cout<<tail->word<<":"<<tail->count<<endl<<endl;     // Print the tail.
}

void LL::countNodes(){
    Node *crawler = head;
    int nodeCounter = 1;
    // Base cases
    if(head == NULL && tail == NULL){
        cout<<"The Linked List is empty."<<endl;
        return;
    } else if((head != NULL && tail == NULL)||(head == NULL && tail != NULL)){
        cout<<"LL Nodes: 1"<<endl;
    }

    while(crawler != tail){
        nodeCounter++;
        crawler = crawler->next;
    }
    cout<<"LL Nodes: "<<nodeCounter<<endl;
}

void LL::countTotalWords(){
    Node *crawler = head;
    int wordCounter = 0;
    // Base cases
    if(head == NULL && tail == NULL){
        cout<<"The Linked List is empty."<<endl;
        return;
    }

    while(crawler != tail){
        wordCounter = wordCounter + crawler->count;
        crawler = crawler->next;
    }
    cout<<"LL Words: "<<wordCounter<<endl;
}

int LL::searchLL(string word){
    Node *crawler = head;
    int opCounter = 0;
    //Base Case: LL is empty
    if(head == NULL && tail == NULL){
        cout<<"The Linked List is empty."<<endl;
        return 0;
    }
    // Loop through all values of LL in order until word is reached
    while (crawler != tail){
        if(crawler->word == word){ 
            opCounter++;
            cout<<"LL Operations: "<<opCounter<<endl;
            return opCounter;
        } else {
            opCounter++;
            crawler = crawler->next;
        }
    }
    // Check the tail
    if(word == tail->word){
        opCounter++;
        cout<<"LL Operations: "<<opCounter<<endl;
        return opCounter;
    } else { // If the word does not exist in the LL
        cout<<"Word does not exist in the Linked List."<<endl;
        return -1;
    }
}

