#include <string>
#include <iostream>
using namespace std;

//doubly linked list node
struct LLNode {
    int val;
    LLNode *next = NULL;       //this is the 'link' to the next node in a linked list
    LLNode *prev = NULL;
};

//doubly linked list
class myLL {
    private:
        LLNode *head;
        LLNode *tail;
    public:
        myLL();
        void prepend(int val); //todo - add a node to the front of the linked list
        void append(int val);  //todo - add a node to the end of the linked list
        void showLL();
        void reverseShow();
};

myLL::myLL() {
    head = NULL;
    tail = NULL;
}

//TODO together :D
//add value to the front of the list
void myLL::prepend(int value) {
    if(head == NULL){
        LLNode *node = new LLNode;
        node->val = value;
        head = node;
        return;
    }
    
    LLNode *node = new LLNode;
    node->val = value; // Set val to inputted value.
    node->next = head; // Point next pointer to where head currenty is.
    head->prev = node; // Point previous pointer of head (the now second node) to the new head node.

    head = node; //Point head to new head node.
    return;
}

//TODO
//add value to the end 
void myLL::append(int value) {
    if(tail == NULL){
        LLNode *node = new LLNode;
        node->val = value;
        tail = node;
        return;
    }
    LLNode *node = new LLNode;
    node->val = value; // Set val to inputted value.
    node->prev = tail; // Point previous pointer of new node to where tail currently is.
    tail->next = node; // Point next pointer of tail (the now second to last node) to the new tail node.
    tail = node;      // Point tail pointer to new tail node.
    return;
    
}

//iterate through LL and print each value
void myLL::showLL() {
    if (head == NULL) {
        cout << "empty LL" << endl; 
    }

    LLNode *crawler = head;
    while(crawler != NULL) {
        cout << crawler->val;
        if (crawler->next != NULL) //no arrow after last node
            cout << " --> ";
        crawler = crawler->next;
    }

    cout << "\n\nhead: " << head->val << endl;
    cout << "tail: " << tail->val << endl << endl;
}

void myLL::reverseShow() {
    LLNode *crawler = new LLNode;

    crawler = tail;

    while(crawler!= NULL) {
        cout << crawler->val << " --> ";
        crawler = crawler->prev;

    }
}

int main() {
    myLL myList;
    
    // myList.prepend(3);  //3
    // myList.prepend(2);  //2->3
    // myList.prepend(1);  //1->2->3
    
    // myList.append(5); //1->2->3->5
    // myList.append(8);  //1->2->3->5->8
    // myList.prepend(13);  //1->2->3->5->13
    // myList.showLL();
    
    //recitation exercise
    //create a linked list from this array representing the coolest CU csci classes, and the number 10
    int classes[10] = {2275, 3022, 2824, 2400, 1300, 4622, 1200, 4302, 3753, 10};

    myList.prepend(classes[0]);
    for(int i = 1; i < 10 ; i++){
        myList.append(classes[i]);
    }
    myList.reverseShow();
    myList.showLL();

}