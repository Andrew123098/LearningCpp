#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include "priorityQueueHeap.h"

using namespace std;

pqHP::pqHP(int initCapacity){
/* Default Constructor */
    capacity = initCapacity;
    heap = new patientHP[capacity];
    
} 

patientHP* pqHP::pop(){
/* Return highest priority very very pregnant person. */

return NULL;
}                 

void pqHP::push(patientHP* person){
/* Add very very pregnant person to the priority queue. */

}    

void pqHP::printPQ(){
/* Print the in order priority queue. */

}

void pqHP::reorder(patientHP* person){
/* Called by pop to properly reorder the priority queue. */

}