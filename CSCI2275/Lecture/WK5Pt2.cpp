// INTRO TO LINKED LISTS

#include <iostream>

using namespace std;

int main(){
    /* LINKED LISTS:
     * Allocate memory for individual objects.
     * Linked together using pointers.
     * Not memory contignous.
     * Follow the pointers to recover the linked list.
     * 
     * STEPS:
     * Create an object.
     * Add to the list.
     * Allocate memory for another object.
     * Link together.
     * etc.
     */
    
    // EXAMPLE:
    struct node{
        int key;
    }

    //pointers of type node
    node *next;
    node *previous;

    //Next points to the next node in the list 
    //& previous points to the previous node in the list

    // |Previous| <--> |data| <--> |Next|

    // A doubly linked list has next and previous (2 directions)
    // A singly linked list has next only (1 direction)

    //Create a doubly linked list w/ 3 nodes w/ key values of 5, 6 & 7

    node *n = new node;
    n->next = nullptr;
    n->previous = nullptr;
    n->key = 5;

    //feature of the Linked List:
    //We have to store a pointer to the head of the list - first node in the list.

    node *head = n;
    node *temp = n;

    //Create the next node
    n = new node;
    n->next = nullptr;
    n->previous = nullptr;
    n->key = 6;

    //Link the 2 nodes
    temp->next = n;
    n->previous = temp;
    temp = temp->next;


    //Create the next node
    n = new node;
    n->next = nullptr;
    n->previous = nullptr;
    n->key = 7;

    //Link the 2 nodes
    temp->next = n;
    n->previous = temp;

    //END: Data structure has been built ...
    // but, how do we traverse the linked list?
    
    //TRAVERSE THE LINKED LIST:
    // We have to start at the head.
    // Follow the pointers until we reach a nullptr.
    // Vice versa for going backwards through the linked list.

    node *temp = head;
    while(temp != nullptr){
        cout<<temp->key<<endl;
        //move to next node
        temp = temp->next;
    }

    //What happens if I do this after the while loop?
    cout<<temp->key<<endl;
    //Temp is set to null pointer (segmentation fault).

    //INSERT A NODE AT A LOCATION:
    // Add a node with k = 7 after k = 6
    //  Start at head.
    //  Traverse the list until we find a node where key = 6.
    //  Update the next and previous pointers for surrounding nodes.

    node *temp = head;
    bool notFound = true;
    while(temp != nullptr && notFound){
        if(temp->key == searchValue){
            //Create the new node
            node *n = new node;
            n->key = 7;
            //point n at key = 8
            n->next = temp->next;
            
            //Link n with preious in both directions
            temp->next = n;
            n->previous = temp;
            n->next->previous = n;
            notFound = false;
        } else {
            temp = temp->next;
        }
    }


    // what does the following print?
    cout<<temp->next->key<<endl;
    // Will print 7

    

    








    return 0;
}