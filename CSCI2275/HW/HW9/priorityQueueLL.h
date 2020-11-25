//
//  Assignment9.h
//  Assignment9
//
//

// Make sure we do not compile and allocate memory twice.
#ifndef PRIORITYQUEUELL_H 
#define PRIORITYQUEUELL_H

#include <iostream>

using namespace std;

struct LLPerson{ 
    string name;     // Name of patient.
    int timeToDel;   // Estimated time until baby is born b/w 30 and 300 minutes.
    int timeToTreat; // Estimates time that patient needs to spend with the doctor.

    LLPerson* next; // Next patient in Linked List.

    LLPerson(){};   // Default constuctor.
    LLPerson(string initName, int initDel, int initTreat){
        name = initName;
        timeToDel = initDel;
        timeToTreat = initTreat;
        next = NULL;
    }
    LLPerson(string initName, int initDel, int initTreat, LLPerson* initNext){
        name = initName;
        timeToDel = initDel;
        timeToTreat = initTreat;
        next = initNext;
    }


    // overload the > and < operators for struct
    bool operator>(LLPerson p2) const{
        if(timeToDel == p2.timeToDel)
            return timeToTreat > p2.timeToTreat;
        
        return timeToDel > p2.timeToDel;
    }
    bool operator<(LLPerson p2) const{
        if(timeToDel == p2.timeToDel)
            return timeToTreat < p2.timeToTreat;
        
        return timeToDel < p2.timeToDel;
    }
    // if timeToDel is equal than check the timeToTreat
    // overlaod == operator for struct
    bool operator==(LLPerson p2) const{
        if(timeToDel == p2.timeToDel){
            return timeToTreat < p2.timeToTreat;
        } else {
            return timeToDel < p2.timeToDel;
        }
    }
};
struct LLCompare{
    bool operator()(LLPerson p, LLPerson p2){
        if(p.timeToDel != p2.timeToDel){
            return p > p2;
        } else {
            return p.timeToTreat > p2.timeToTreat;
        }
    }
};

class pqLL
{
    public:
        pqLL();                       // Default constructor.
        LLPerson* pop();              // Return highest priority very very pregnant person.
        void push(LLPerson person);   // Add very very pregnant person to the priority queue.
        void printPQ();               // Print the in order priority queue.
        int curr_size;                // Holds the current size of the linked list.

    private:
        void reorder(LLPerson* head); // Called by pop to properly reorder the priority queue.
        LLPerson* head;               // Stores the head of the Linked List.
        LLPerson* tail;               // Stores the tail of the Linked List.
};

#endif