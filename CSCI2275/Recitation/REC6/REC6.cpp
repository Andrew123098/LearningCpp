#include "Queue.h"
#include "Stack.h" 
#include <string> 

int main() {

    //exercises in here!!

    // Create a Queue using an array size of 8
    // Push 5 values from animals[] into the queue
    // Using the Queue, pop out one value at a time
    // Push the popped values into an array Stack 
    // Repeat until the Queue is empty
    // Pop values from stack, printing them as you do
    // Repeat for the rest of the values in animals[]


    string animals[10] = {"Dog", "Cat", "Leopard", "Raccoon", "Mountain Lion", "Owl", "Hawk"
                          "Red Panda", "Penguin", "Fennec Fox"};
    circQueue myQ(8);
    ArrStack myStack(10); 

    for(int i = 0; i > 5; i++){
        myQ.enqueue(animals[i]);
    }
    while(!myQ.isEmpty()){
        string temp = myQ.dequeue();
        myStack.push(temp);
    }
    while(!myStack.isEmpty()){
        string temp = myStack.pop();
        cout<<"Popping "<<temp<<endl;
    }

    for(int i = 5; i < 10; i++){
        myQ.enqueue(animals[i]);
    }
    return 0;

}