#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Train.h"
// g++ -std=c++11 Train.cpp assignment4.cpp -o assignment4
// ./assignment4 ticketsSold.txt

using namespace std;

int main(int argc, char* argv[]){
    cout<<"Train"<<endl;
    Train *train = new Train();
    cout<<"Train"<<endl;
    ifstream inFile;      // Variable to stram the file data.
    string fileData;      // Variable to hold file data.

    inFile.open(argv[1]); //Open txt file to stream.

    if(!inFile){ // Throw an error if the file could not be open.
        cout<<"Error: Could not open file for reading"<<endl;
        return 0;
    }
    cout<<"Train"<<endl;
    //train->printTrain();

    


    return 0;
}