#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Queue.h"
#include "Train.h"

using namespace std;

Queue::Queue(int maxSize){   // Create the circular queue by calling buildTrain with maxSize as its argument.
    queueHead = queueTail = -1;
    queueCount = 0;
    cpQueue = new carPassengers[maxSize];
    queueSize = maxSize;
}

Queue::~Queue(){}

bool Queue::enqueue(carPassengers cpp){
    if(queueHead == -1){ // If the queue is empty                                  
        queueHead = 0;
        queueTail = 0;
    } else if((queueHead == 0 && queueTail == queueSize-1) || (queueTail == queueHead-1)){ // If the queue is full in array or circular form
        // Check if queue is full.
        cout <<"Queue is full." <<endl;
        return false;
    } else if(queueTail == queueSize-1 && queueHead != 0){ //If we are at the end of the array but there is space at the beginning of the array
        // Wrap around.
        queueTail = 0;
    } else { // Queue is not full and we do not have to wrap around
        // Default standard case.
        queueTail++;
    }

    cpQueue[queueTail].carName = cpp.carName;
    cpQueue[queueTail].passengers = cpp.passengers;
    queueCount++;
    return true;
}

carPassengers Queue::dequeue(){
if(queueHead == -1){                              // If the queue is empty (nothing has been added or taken away yet)
        cout<<"Queue is empty"<<endl;
        exit;
    }
    carPassengers toRet = cpQueue[queueHead];     // The is where we dequeue from
    
    if(queueHead == queueTail){                   // If we have dequeue everythingfrom the queue.
        queueHead = -1;
        queueTail = -1;
    } else if (queueHead == queueSize - 1){       // Wrap around if head is at end of array.
        queueHead = 0;
    } else{                                       // No wrap around and queue is not empty
        queueHead++;
    }
    
    cout<<"dequeuing "<<toRet.carName<<": "<<toRet.passengers<<endl;
    queueCount--;
    return toRet;
}

void Queue::printQueue(){
    if (queueHead == -1) {
        cout << "Queue empty D:" << endl;
        return;
    }

    cout << "\nPrinting (circular) queue: " << endl;
    if (queueTail >= queueHead) {
        for (int i = queueHead; i <= queueTail; i++) {
            cout << "q[" << i << "]: " << cpQueue[i].carName<<":"<<cpQueue[i].passengers<< " | ";
        }
    } else {
        for (int i = queueHead; i < queueSize; i++) {
            cout << "q[" << i << "]: " << cpQueue[i].carName<<":"<<cpQueue[i].passengers<< " | ";
        }
        for (int i = 0; i <= queueTail; i++) {
            cout << "q[" << i << "]: " << cpQueue[i].carName<<":"<<cpQueue[i].passengers<< " | ";
        }
    }
    cout << endl;
}

// bool Queue::queueIsFull(){

// }

// bool Queue::queueIsEmpty(){

// }


