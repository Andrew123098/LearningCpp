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

struct patientLL{
    string name;   // Name of patient.
    int priority;  // Estimated time until baby is born b/w 30 and 300 minutes.
    int treatment; // Estimates time that patient needs to spend with the doctor.

    patientLL* next; // Next patient in Linked List.
    patientLL* prev; // Previous patient in Linked List.

    patientLL(){};   // Default constuctor.
    patientLL(string initName, int initPriority, int initTreatment, patientLL* initNext, patientLL* initPrev){
        name = initName;
        priority = initPriority;
        treatment = initTreatment;
        next = initNext;
        prev = initPrev;
    }
};

class pqLL
{
    public:
        pqLL();                        // Default constructor.
        patientLL* pop();              // Return highest priority very very pregnant person.
        void push(patientLL* person);  // Add very very pregnant person to the priority queue.
        void printPQ();                // Print the in order priority queue.

    private:
        void reorder(patientLL* head); // Called by pop to properly reorder the priority queue.
        patientLL* head;               // Stores the head of the Linked List.
        patientLL* tail;               // Stores the tail of the Linked List.
};

#endif