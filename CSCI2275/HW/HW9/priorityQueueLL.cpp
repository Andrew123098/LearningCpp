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
        cout<<"LL is empty."<<endl;
        return NULL;
    }
    if(curr_size == 1){
        LLPerson* toRet = new LLPerson;
        toRet = head;
        head = NULL;
        tail = NULL;
        curr_size--;
        return toRet;
    }
    
    LLPerson* toRet = new LLPerson;
    toRet = head;
    head = head->next;
    toRet->next = NULL;
    curr_size--;
    return toRet;
}                 

void pqLL::push(LLPerson person){
/* Add very very pregnant person to the priority queue. */
    LLPerson pPerson = person;
    LLPerson* newPerson = &pPerson;
    LLPerson* crawler = new LLPerson;
    crawler = head;

// CASE: LL is empty.
    if(curr_size == 0){
        head = newPerson;
        tail = newPerson;
        curr_size++;
        cout<<head->name<<endl;
        return;
    }
// CASE: LL has 1 value.
    if(curr_size == 1){
        if(newPerson > head){
            head->next = newPerson;
            tail = newPerson;
            cout<<"1"<<endl;
        } else {
            newPerson->next = head;
            head = newPerson;
            cout<<"2"<<endl;
        }
        cout<<head->name<<"-->"<<head->next->name<<endl;
        curr_size++;
        return;
    }

// CASE: Higher priority than head.
    if(newPerson < head){
        newPerson->next = head;
        head = newPerson;
        curr_size++;
        return;
    }

// CASE: Lower priority than tail.
    if(newPerson > tail){
        tail->next = newPerson;
        tail = newPerson;
        curr_size++;
        return;
    }

// CASE: Add middle value.
    while(newPerson > crawler->next){
        crawler = crawler->next;
    }
    newPerson->next = crawler->next;
    crawler->next = newPerson;
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

