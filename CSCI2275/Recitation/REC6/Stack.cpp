#include "Stack.h"
#include <string>
using namespace std;


//linked list stack implementations

void LLStack::push(string toPush) {
    //optional
}

LLNode* LLStack::pop() {
    //optional
}

LLNode* LLStack::peek() {
    return top;
}

void LLStack::printStack() {
    LLNode *crawler = top;
    cout << "\ntop" << endl;
    while (crawler != NULL) {
        cout << crawler->data << " | ";
        crawler = crawler->prev;
    }
    cout << endl;
}

bool LLStack::isEmpty() {
    return top == NULL;
}





//array stack implementations

bool ArrStack::isFull() {
    return top == maxSize;
}

//returns true if stack is empty
bool ArrStack::isEmpty() {
    return top == 0;
}

//adds toPush to the stack, increments top
void ArrStack::push(string toPush) {
    
    if(!isFull()){
        top++;
        stack[top] = toPush;
    } else {
        cout << "Stack is full" << endl.
    }
} 

//returns the top element of the stack, decrements 'top'
string ArrStack::pop() {
    if(!isEmpty()){
        top--;
        return stack[top + 1];
    } else {
        cout << "Stack is empty" <<endl;
        return;
    }

}

//prints stack from bottom -> top
void ArrStack::printStack() {
    for (int i = 0; i < top; i++) {
        cout << stack[i] << endl;
    }
}


int main() {
    // //linked list stack testing
    // LLStack myLLStack;
    // myLLStack.push("pupper");
    // myLLStack.push("doggo");
    // myLLStack.push("henlo");
    // myLLStack.printStack();
    // myLLStack.pop();
    // myLLStack.printStack();

    // cout << "\nprinting stack" << endl;
    // LLNode *temp;
    // while (!myLLStack.isEmpty()) {
    //     temp = myLLStack.pop();
    //     cout << temp->data << endl;
    // }



    // // array stack testing
    // ArrStack myStack(5);
    // myStack.push("Hey");        //add items to stack
    // myStack.push("Hi");
    // myStack.push("Salut");
    // myStack.push("ça va");
    // myStack.push("henlo");
    // myStack.push("any more words");
    // cout << "\nprinting stack" << endl;
    // myStack.printStack();
    // cout << endl << "popping until empty: " << endl;
    // while(!myStack.isEmpty()) {
    //     cout << myStack.pop() << endl;
    // }
}