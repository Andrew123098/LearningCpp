#include <iostream>
#include <string>
#include "Queue.h"
using namespace std;


//linked list queue implementations 

bool LLQueue::isEmpty() {
    return head == NULL && tail == NULL;
}

void LLQueue::enqueue(string toQ) {
    
}

QNode* LLQueue::dequeue() {
    //optional
}

QNode* LLQueue::peek() {
    return head;
}

void LLQueue::printQueue() {
    if (!isEmpty()) {
        QNode *crawler = head;
        cout << "\nHead" << endl;
        while(crawler != NULL) {
            cout << crawler->data << " | ";
            crawler = crawler->next;
        }
        cout << endl;
    } else {
        cout << "q empty, can't print" << endl;
    }
}




//circular array queue implementations

void circQueue::enqueue(string toQ) {
    if(head = -1){
        head = 0;
        tail = 0;
    } else if((head == 0 && tail == maxSize-1) || (tail == head-1)){
        // Check if queue is full.
        cout <<"Queue is full." <<endl;
        return;
    } else if(tail == maxSize-1 && head != 0){
        // Wrap around.
        tail = 0;
    } else {
        // Default standard case.
        tail++;
    }

    tail++;
    queue[tail] = toQ;
    count++;
    return;
}


string circQueue::dequeue() {
    if(head == -1){
        return "Queue is empty";
    }
    string toRet = queue[head];
    queue[head] = -1;
    
    if(head == tail){
        head = -1;
        tail = -1;
    } else if (head == maxSize - 1){
        head = 0;
    } else{
        head++;
    }
    cout<<"dequeuing "<<toRet<<endl;
    count--;
    return toRet;
}

void circQueue::printQueue() {
    if (head == -1) {
        cout << "Queue empty D:" << endl;
        return;
    }

    cout << "\nPrinting (circular) queue: " << endl;
    if (tail >= head) {
        for (int i = head; i <= tail; i++) {
            cout << "q[" << i << "]: " << queue[i] << " | ";
        }
    } else {
        for (int i = head; i < maxSize; i++) {
            cout << "q[" << i << "]: " << queue[i] << " | ";
        }
        for (int i = 0; i <= tail; i++) {
            cout << "q[" << i << "]: " << queue[i] << " | ";
        }
    }
    cout << endl;
}

bool circQueue::isFull() {
    return count == maxSize;
}

bool circQueue::isEmpty() {
    return count == 0;
}

int main (){

    // //circular queue testing
    // circQueue myQ(10);
    // myQ.enqueue("a");
    // myQ.enqueue("b");
    // myQ.enqueue("c");
    // myQ.enqueue("d");
    // myQ.printQueue();
    // myQ.enqueue("f");
    // myQ.enqueue("g");
    // myQ.enqueue("h");
    // myQ.enqueue("i");
    // myQ.enqueue("j");
    // myQ.enqueue("k");
    // myQ.printQueue();
    // myQ.dequeue();
    // myQ.printQueue();
    // myQ.dequeue();
    // myQ.printQueue();
    // myQ.dequeue();
    // myQ.printQueue();
    // myQ.dequeue();
    // myQ.printQueue();
    // myQ.enqueue("l");
    // myQ.enqueue("m");
    // myQ.enqueue("n");
    // myQ.enqueue("o");
    // myQ.printQueue();


    // //Linked list testing
    // LLQueue myQ;
    // myQ.enqueue("Hello,");
    // myQ.enqueue("world!");
    // myQ.enqueue("world!");
    // myQ.printQueue();
    // myQ.enqueue("dogogogog!");
    // myQ.printQueue();
    // cout << myQ.dequeue()->data  << endl;
    // cout << myQ.dequeue()->data  << endl;
    // cout << myQ.dequeue()->data  << endl;
    // myQ.printQueue();
}
