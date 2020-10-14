//
//  Queue.hpp
//  CircularQueue
//
//  Created by Sunil on 2/25/17.
//  Copyright © 2017 Sunil. All rights reserved.
//

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

struct carPassengers{
    int passengers;
    std::string carName;
};
class Queue
{
public:
    Queue(int);
    ~Queue();
    //circular queue methods
    bool enqueue(carPassengers cp);
    carPassengers dequeue();
    void printQueue(); //probably good for debug
    bool queueIsFull(); //check when full
    bool queueIsEmpty(); //check when empty
    
protected:
private:
    int queueSize;
    int queueHead;
    int queueTail;
    int queueCount;
    carPassengers *cpQueue;
};

#endif // QUEUE_H

