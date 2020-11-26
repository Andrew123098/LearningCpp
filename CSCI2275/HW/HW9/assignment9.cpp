#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <queue>
#include <chrono>
#include "priorityQueueHeap.h"
#include "priorityQueueLL.h"

// g++ -std=c++11 assignment9.cpp priorityQueueHeap.cpp priorityQueueLL.cpp -o assignment9
// ./assignment9 patientData2275.csv

using namespace std;

struct person{
    string name;
    int timeToDel;
    int timeToTreat;
    //overload the >, < operator
    bool operator>(person p2) const{
        return timeToDel > p2.timeToDel;
    }
    bool operator<(person p2) const{
        return timeToDel < p2.timeToDel;
    }
    //if timeToDel is equal, then check timeToTreat
    bool operator==(person p2) const{
        if(timeToDel == p2.timeToDel){
            return timeToTreat < p2.timeToTreat;
        }else{
            return timeToDel < p2.timeToDel;
        }
    }
    person(string n, int t, int t2){
        timeToDel = t;
        timeToTreat = t2;
        name = n;
    }
};
struct compare{
    bool operator()(person p, person p2) const{
        if(p.timeToDel!=p2.timeToDel){
            return p > p2;
        }else{
            return p.timeToTreat > p2.timeToTreat;
        }
    }
};

int main(int argc, char *argv[]){
    ifstream raw;
    raw.open(argv[1]);

    // throw an error if we couldn't open the file
    if (!raw){
        cout << "Error: Could not open file for reading" << endl;
        return 0;
    }
    int heapCapacity = 881;
    pqHP hp(heapCapacity);
    pqLL ll; 

    // Set up file reading. 
    vector<string> data;
    string temp;

    // Ignore the first row of the data.
    getline(raw, temp);

    // Read the .csv file data into a vector.
    while(getline(raw, temp)){
        data.push_back(temp);
    }

    // Build all priority queues.
    string name, sDel, sTreat, line;
    int timeToDel;
    int timeToTreat;

    vector<string> names;
    vector<int> delivery, treatment;
    vector<person> people;
    vector<LLPerson> LLPeople;

    while(!data.empty()){
        line = data.front();           // Set line to the head of the vector.
        stringstream ss(line);         // Make stream from each line.
        data.erase(data.begin());      // Erase the head of the vector.
        getline(ss,name,',');          // Get the name from the stream.
        getline(ss,sDel,',');          // Get the delivery time from the stream.
        getline(ss,sTreat);            // Get the treatment time from the stream.
        timeToDel = stoi(sDel);        // Convert datatypes.
        timeToTreat = stoi(sTreat);    // Convert datatypes.
        person tmp = person(name,timeToDel,timeToTreat); // Make struct.
        LLPerson tmpLL = LLPerson(name,timeToDel,timeToTreat); // Make LL struct.
        // Push all values to vectors.
        names.push_back(name);             
        delivery.push_back(timeToDel);
        treatment.push_back(timeToTreat);
        people.push_back(tmp);
        LLPeople.push_back(tmpLL);
    }

    // Runtime Analysis:

    int numRows[8] = {100,200,300,400,500,600,700,800}; // Number of data points to run. 
    float heapRuntimes[100][8];                         // Stores all runtime data for the heap implementation.
    float LLRuntimes[100][8];                           // Stores all runtime for the Linked List implementation.
    float BIRuntimes[100][8];                           // Stores all runtime data for the builtin PQ implementation.

    // HEAP
    for(int i = 0; i < 8; i++){                             
        for(int j = 0; j < 100; j++){
            auto t1 = chrono::system_clock::now();
            for(int k = 0; k < numRows[i]-1; k++){
                hp.push(names[k],delivery[k],treatment[k]);
            }
            while(hp.curr_size != 0){
                hpPerson popped = hp.pop();
            }
            auto t2 = chrono::system_clock::now();
            heapRuntimes[j][i] = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
        }
    }
    cout<<"HEAP:"<<endl;
    for(int i = 0; i < 100; i++){
        cout<<heapRuntimes[i][0]<<" "<<heapRuntimes[i][1]<<" "<<heapRuntimes[i][2]<<" "<<heapRuntimes[i][3]<<" "<<heapRuntimes[i][4]<<" "<<heapRuntimes[i][5]<<" "<<heapRuntimes[i][6]<<" "<<heapRuntimes[i][7]<<" "<<endl;
    }

    // LINKED LIST
    for(int i = 0; i < 8; i++){                             
        for(int j = 0; j < 100; j++){
            auto t1 = chrono::system_clock::now();
            for(int k = 0; k < numRows[i]-1; k++){
                ll.push(&LLPeople[k]);
            }
            while(ll.curr_size != 0){
                LLPerson* popped = ll.pop();
            }
            auto t2 = chrono::system_clock::now();
            LLRuntimes[j][i] = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
        }
    }
    cout<<endl<<endl<<"LINKED LIST:"<<endl;
    for(int i = 0; i < 100; i++){
        cout<<LLRuntimes[i][0]<<" "<<LLRuntimes[i][1]<<" "<<LLRuntimes[i][2]<<" "<<LLRuntimes[i][3]<<" "<<LLRuntimes[i][4]<<" "<<LLRuntimes[i][5]<<" "<<LLRuntimes[i][6]<<" "<<LLRuntimes[i][7]<<" "<<endl;
    }

    // BUILT IN PRIORITY QUEUE
    priority_queue<person, vector<person>, compare> pq; //greater<vector<person>::value_type>> pq;

    for(int i = 0; i < 8; i++){                             
        for(int j = 0; j < 100; j++){
            auto t1 = chrono::system_clock::now();
            for(int k = 0; k < numRows[i]-1; k++){
                pq.push(people[k]);
            }
            while(hp.curr_size != 0){
                pq.pop();
            }
            auto t2 = chrono::system_clock::now();
            BIRuntimes[j][i] = chrono::duration_cast<chrono::microseconds>(t2-t1).count();
        }
    }
    cout<<endl<<endl<<"BUILT IN:"<<endl;
    for(int i = 0; i < 100; i++){
        cout<<BIRuntimes[i][0]<<" "<<BIRuntimes[i][1]<<" "<<BIRuntimes[i][2]<<" "<<BIRuntimes[i][3]<<" "<<BIRuntimes[i][4]<<" "<<BIRuntimes[i][5]<<" "<<BIRuntimes[i][6]<<" "<<BIRuntimes[i][7]<<" "<<endl;
    }

    
} 

