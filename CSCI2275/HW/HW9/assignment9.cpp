#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include "priorityQueueHeap.h"
#include "priorityQueueLL.h"

// g++ -std=c++11 assignment9.cpp priorityQueueHeap.cpp priorityQueueLL.cpp -o assignment9
// ./assignment9 patientData2275.csv

using namespace std;

int main(int argc, char *argv[]){
    ifstream raw;
    raw.open(argv[1]);

    // throw an error if we couldn't open the file
    if (!raw){
        cout << "Error: Could not open file for reading" << endl;
        return 0;
    }
    int heapCapacity = 10000;
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
    while(!data.empty()){
        line = data.front();           // Set line to the head of the vector.
        stringstream ss(line);         // Make stream from each line.
        data.erase(data.begin());      // Erase the head of the vector.
        getline(ss,name,',');          // Get the name from the stream.
        getline(ss,sDel,',');          // Get the delivery time from the stream.
        getline(ss,sTreat);            // Get the treatment time from the stream.
        timeToDel = stoi(sDel);        // Convert datatypes.
        timeToTreat = stoi(sTreat);    // Convert datatypes.
        hp.push(name,timeToDel,timeToTreat); // Push to heap.
    }

    hp.printPQ();

    






}