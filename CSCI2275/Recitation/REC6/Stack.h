#include <iostream>
#include <string>
using namespace std;

//skeleton for array implementation of a stack
class ArrStack {
    private:
        int top;            //index of top element
        string *stack;      //stack
        int maxSize;        //size of data

    public:
        //initializes a stack w/ maxSize = size
        ArrStack(int size) {
            top = 0;
            maxSize = size;
            stack = new string[maxSize];
        }

        bool isFull();
        bool isEmpty();
        void push(string);  //together todo
        string pop();       //together todo
        void printStack(); 
};



//item in a linked list tack
struct LLNode {
    string data;
    LLNode *prev;
    LLNode() {
        data = "";
        prev = NULL;
    }
};

//skeleton for a linked list implementation of a stack
class LLStack {
    private: 
        LLNode *top;
    public:
        LLStack() {
            top = NULL;
        }
        // bool isFull();
        bool isEmpty();
        void push(string val); //optional
        LLNode *peek();        //optional
        LLNode *pop();
        void printStack();
};