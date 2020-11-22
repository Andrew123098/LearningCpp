#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include "priorityQueueHeap.h"

using namespace std;

pqHP::pqHP(int initCapacity){
/* Default Constructor */
    capacity = initCapacity;
    heap = new person[capacity];
    
} 

person* pqHP::pop(){
/* Return highest priority very very pregnant person. */

return NULL;
}                 

void pqHP::push(string initName, int initDel, int initTreat){
/* Add very very pregnant person to the priority queue. */
    person newPerson = person(initName, initDel, initTreat);
    int index = 1;

    // If the heap is empty
    if(heap[index].name.length() == 0){ // If the heap is empty (no name in first value) ...
        heap[index] = newPerson;        // Set the eprson to be the first in the PQ.
    } else {                            // Otherwise ...
        while(heap[index].name.length() != 0){ // While there is a person in the current index ...
            index++;                           // Increment the index.
        } 
        heap[index] = newPerson;               // Add the new person at the end of the heap.
        minHeapify(index);                     // Heapify the heap.
    }

}    

void pqHP::printPQ(){
/* Print the in order priority queue. */
    int root = 1;
    printPQHelper(root);
    
}

void pqHP::printPQHelper(int index){
    cout<<index<<endl;
    // Base Case
    if(index <= capacity){
    
        // Define left and right children.
        int lIndex = index*2;
        int rIndex = (index*2)+1;
        person left = heap[lIndex];
        person right = heap[rIndex];
    
        // Print the current index.
        cout<<heap[index].name<<","<<heap[index].timeToDel<<","<<heap[index].timeToTreat<<endl;
    
        // 
        if(left < right){
            printPQHelper(lIndex);
            printPQHelper(rIndex);
        } else {
            printPQHelper(rIndex);
            printPQHelper(lIndex);
        }
    }
}

void pqHP::minHeapify(int index){
/* Called by pop to properly reorder the priority queue. */
    person tempPerson; // Make a temporary person for swapping.
    while(heap[index] < heap[(int)floor(index/2)] && index != 1){ // While the current index is higher priority and we are not at the root...
        tempPerson = heap[index];                                 // SWAP
        heap[index] = heap[(int)floor(index/2)];                  // SWAP
        heap[(int)floor(index/2)] = tempPerson;                   // SWAP
        index/=2;                                                 // Divide index by 2.
    }
}