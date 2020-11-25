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

struct hpPerson{ 
    string name;     // Name of patient.
    int timeToDel;   // Estimated time until baby is born b/w 30 and 300 minutes.
    int timeToTreat; // Estimates time that patient needs to spend with the doctor.

    hpPerson(){};   // Default constuctor.
    hpPerson(string initName, int initDel, int initTreat){
        name = initName;
        timeToDel = initDel;
        timeToTreat = initTreat;
    }

    // overload the > and < operators for struct
    bool operator>(hpPerson p2) const{
        if(timeToDel == p2.timeToDel)
            return timeToTreat > p2.timeToTreat;
        
        return timeToDel > p2.timeToDel;
    }
    bool operator<(hpPerson p2) const{
        if(timeToDel == p2.timeToDel)
            return timeToTreat < p2.timeToTreat;
        
        return timeToDel < p2.timeToDel;
    }
    // if timeToDel is equal than check the timeToTreat
    // overlaod == operator for struct
    bool operator==(hpPerson p2) const{
        if(timeToDel == p2.timeToDel){
            return timeToTreat < p2.timeToTreat;
        } else {
            return timeToDel < p2.timeToDel;
        }
    }
};
struct hpCompare{
    bool operator()(hpPerson p, hpPerson p2){
        if(p.timeToDel != p2.timeToDel){
            return p > p2;
        } else {
            return p.timeToTreat > p2.timeToTreat;
        }
    }
};

class pqHP
{
    public:
        pqHP(){};                          // Default constructor.
        pqHP(int c);                       // Constructor that defines capacity.
        hpPerson pop();                      // Return highest priority very very pregnant person.
        void push(string n, int D, int T); // Add very very pregnant person to the priority queue.
        int capacity;                      // Stores max capacity of heap.
        int curr_size;                     // Stores the current size of the heap.
 
    private:              
        hpPerson* heap;                      // Initializes pointer to array that is a heap.
        void minHeapifyTop(int index);     // Called by pop to properly reorder the priority queue.
        void minHeapifyBot(int index);     // Called by push to properly reorder the priority queue.
};

#endif
