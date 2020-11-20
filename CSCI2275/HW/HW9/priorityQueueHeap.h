//
//  Assignment9.h
//  Assignment9
//
//

// Make sure we do not compile and allocate memory twice.
#ifndef PRIORITYQUEUEHEAP_H
#define PRIORITYQUEUEHEAP_H

#include <iostream>

using namespace std;

// global array where each index contains a pointer to a data struct called person (name, delivery time and treatment time)
// in constructor of heap, pass in the number of people and then declare an arry of that size

struct patientHP{
    string name;   // Name of patient.
    int priority;  // Estimated time until baby is born b/w 30 and 300 minutes.
    int treatment; // Estimates time that patient needs to spend with the doctor.

    patientHP(){};   // Default constuctor.
    patientHP(string initName, int initPriority, int initTreatment){
        name = initName;
        priority = initPriority;
        treatment = initTreatment;
    }
};

class pqHP
{
    public:
        pqHP(){};                        // Default constructor.
        pqHP(int c);                     // Constructor that defines capacity.
        patientHP* pop();                // Return highest priority very very pregnant person.
        void push(patientHP* person);    // Add very very pregnant person to the priority queue.
        void printPQ();                  // Print the in order priority queue.
        int capacity;                    // Stores max capacity of heap.
 
    private:              
        patientHP* heap;                 // Initializes pointer to array that is a heap.
        void reorder(patientHP* person); // Called by pop to properly reorder the priority queue.
};

#endif
