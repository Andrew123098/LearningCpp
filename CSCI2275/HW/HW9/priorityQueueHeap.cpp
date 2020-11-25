#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <array>
#include "priorityQueueHeap.h"

using namespace std;

pqHP::pqHP(int initCapacity){
/* Default Constructor */
    capacity = initCapacity;
    heap = new hpPerson[capacity];
    curr_size = 0;
} 

void pqHP::push(string initName, int initDel, int initTreat){
/* Add very very pregnant person to the priority queue. */
    hpPerson newPerson = hpPerson(initName, initDel, initTreat);

    if(curr_size >= capacity){          // If the heap is full ...
        cout<<"Full Heap"<<endl;        // Print the heap is full. 
        return;                         // and return.
    } else {                            // Otherwise ...
        curr_size++;                    // Increment the size of the heap.
        heap[curr_size] = newPerson;    // Add the new person at the end of the heap.
        minHeapifyBot(curr_size);       // Heapify the heap.
    }
}    

hpPerson pqHP::pop(){
/* Return highest priority very very pregnant person. */
    if(curr_size == 0){               // If the heap is empty ...
        cout<<"Heap is empty."<<endl; // Print that the heap is empty.
        return hpPerson();              // And return a null person.
    }
    if(curr_size == 1){               // If the heap has only 1 hpPerson in it ...
        curr_size--;                  // Decrement the current size.
        hpPerson toRet = heap[1];       // Create person object to return.
        heap[1] = hpPerson();           // Delete the values in index 1.
        return toRet;                 // And return the person.
    }
    hpPerson toRet = heap[1];           // Person to return is the root. 
    heap[1] = heap[curr_size];        // Set root to last value n heap.
    
    curr_size--;                      // Decrement the current size.
    minHeapifyTop(1);                 // MinHeapify the heap.
    return toRet;                     // Return the original root.
}                 

void pqHP::minHeapifyBot(int i){
/* Called by pop to properly reorder the priority queue. */
    while(i > 1 && heap[(int)floor(i/2)] > heap[i]){
        swap(heap[(int)floor(i/2)], heap[i]);
        i = (int)floor(i/2);
    }
}

void pqHP::minHeapifyTop(int i){
/* Called by push to properly reorder the priority queue. */
    int left = 2*i;              // Store left child index.
    int right = (2*i)+1;         // Store right child index.
    int root = i;                // Store root index.
    
    // If the left child is within the tree and is less in value than the root, move root to its left child.
    if(left <= curr_size && heap[left] < heap[root])
       root = left;
    
    // If the right child is within the tree and is less in value than the root, move root to its right child.
    if(right <= curr_size && heap[right] < heap[root])
        root = right;

    if(root != i){                // If the root has moved ...
        swap(heap[i],heap[root]); // Swap the root and the new position.
        minHeapifyTop(root);      // Recursively call on the new position.
    }
}