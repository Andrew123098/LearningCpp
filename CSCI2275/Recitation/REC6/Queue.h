#include <iostream>
#include <string>
using namespace std;

struct QNode {
    string data;
    QNode *next;
    
    QNode() {
        data = "";
        next = NULL;
    }
    
    QNode(string toQ) {
        data = toQ;
        next = NULL;
    }
};

class LLQueue {
    private:
        QNode *head, *tail;


    public:
        LLQueue() {
            head = NULL;
            tail = NULL;
        };
        bool isEmpty();
        void enqueue(string);  //optional
        QNode* dequeue();      //optional
        QNode* peek();
        void printQueue();
};



//circular queues
class circQueue {
    private:
        int head;
        int tail;
        int count;
        int maxSize;
        string *queue;

    public:
        circQueue(int size) {
            head = tail = -1;
            maxSize = size;
            count = 0;
            queue = new string[maxSize];
        }

        bool isFull();
        bool isEmpty();
        void enqueue(string); //together todo
        string dequeue();     //together todo
        void printQueue();
};