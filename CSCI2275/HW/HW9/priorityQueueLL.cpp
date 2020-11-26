#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include "priorityQueueLL.h"

using namespace std;

pqLL::pqLL(){
/* Default constructor */
    head = NULL;
    tail = NULL;
    curr_size = 0;
}

LLPerson* pqLL::pop(){
/* Return highest priority very very pregnant person. */
    // If the LL is empty.
    if(curr_size == 0){
        //cout<<"LL is empty."<<endl;
        return NULL;
    }
    // If the LL has 1 value in it.
    if(curr_size == 1){
        LLPerson* toRet = head;
        head = NULL;
        tail = NULL;
        curr_size--;
        return toRet;
    }
    LLPerson* toRet = head;
    //cout<<toRet->name<<endl;
    head = head->next;
    toRet->next = NULL;
    curr_size--;
    return toRet;
}                 

void pqLL::push(LLPerson *person){
/* Add very very pregnant person to the priority queue. */
    LLPerson* crawler = head;

// CASE: LL is empty.
    if(curr_size == 0){ 
        head = person;
        tail = person;
        curr_size++;
        return;
    }
// CASE: LL has 1 value.
    if(curr_size == 1){
        if(person->timeToDel > head->timeToDel){
            head->next = person;
            tail = person;
        } else if(person->timeToDel < head->timeToDel) {
            person->next = head;
            head = person;
            tail = person->next;
        }
        curr_size++;
        return;
    }

// CASE: Higher priority than head.
    if(person->timeToDel < head->timeToDel || (person->timeToDel == head->timeToDel && person->timeToTreat < head->timeToTreat)){
        person->next = head;
        head = person;
        curr_size++;
        return;
    }

// CASE: Lower priority than tail.
    if(person->timeToDel > tail->timeToDel || (person->timeToDel == head->timeToDel && person->timeToTreat > head->timeToTreat)){
        tail->next = person;
        tail = person;
        curr_size++;
        return;
    }

// CASE: Add middle value.
    while(person->timeToDel > crawler->next->timeToDel){
        crawler = crawler->next;
    }
    while(person->timeToTreat > crawler->next->timeToTreat && crawler->next->name == person->name){
        crawler = crawler->next;
    }
    person->next = crawler->next;
    crawler->next = person;
    curr_size++;
}    

void pqLL::printPQ(){
/* Print the in order priority queue. */
    LLPerson* crawler = new LLPerson;
    crawler = head;
    while(crawler->next != NULL){
        cout<<crawler->name<<","<<crawler->timeToDel<<","<<crawler->timeToTreat<<endl;
        crawler = crawler->next;
    }
}