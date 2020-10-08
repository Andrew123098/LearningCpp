#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Train.h"
// g++ -std=c++11 Train.cpp assignment4.cpp -o assignment4
// ./assignment4 ticketsSold.txt

using namespace std;

int main(int argc, char* argv[]){
    Train *train = new Train();
    ifstream inFile;      // Variable to stram the file data.
    string data;      // Variable to hold file data.

    inFile.open(argv[1]); //Open txt file to stream.

    if(!inFile){ // Throw an error if the file could not be open.
        cout<<"Error: Could not open file for reading"<<endl;
        return 0;
    }
    
    string name;
    string snumPassengers;
    int numPassengers;
    while(getline(inFile, data)){
        stringstream ss(data);
        getline(ss, name, ',');
        getline(ss, snumPassengers);
        numPassengers = stoi(snumPassengers);
        cout<<"Add Passengers: "<<name<<":"<<numPassengers<<endl;
        train->addPassengers(name, numPassengers);
    }
    train->printTrain();
    return 0;
}