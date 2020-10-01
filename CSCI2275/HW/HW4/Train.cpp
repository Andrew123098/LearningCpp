#include <iostream>
#include <fstream>
#include <sstream>
#include "Train.h"

using namespace std;

Train::Train(){
    string stringData;    // Variable to hold string data.
    string carCapacities = "The Little Engine That Could: 1\n"
                            "Gilette: 48\n"
                            "Oreville: 40\n"
                            "Keystone: 35\n"
                            "Addie Camp: 25\n"
                            "Redfern: 20\n"
                            "Mystic: 50\n"
                            "Rochford: 52\n"
                            "Harney Canyon: 40\n"
                            "Bluebird: 50\n"
                            "Red Caboose: 1\n";

    // Find initial number of cars from the string.
    int trainSize = 0;
    stringstream cc(carCapacities);            // Create stream from string.
    while(getline(cc, stringData)){            // While not at end of file...
        trainSize++;                           // Increment train size.
    }
    cc.clear();                                // Set new value for stream internal error state flags.
    cc.seekg(0, ios::beg);                     // Seek back to beginning of stream.

    // Initialize arrays.
    string names[trainSize];                   // Stores train car names.
    int caps[trainSize];                       // Stores train car caps.


    // Create train car name and capacity arrays.
    int i = 0;
    while(getline(cc, stringData)){               // While not at end of file.   
        stringstream ss(stringData);              // Make stringstream of file contents.
        string scaps;                             // Stores train car caps temporarily.

        getline(ss, names[i], ':');               // Read in train car names.
        getline(ss, scaps);                       // Read in train car caps.
        caps[i] = stoi(scaps);                    // Move cap trings into integer array.
        i++;
    }

    buildTrain(names, caps, trainSize);
    printTrain();

}

void Train::addCar(string name, int capacity, int passengers, trainCar *previousCar){
/* Insert a new car into the train after the previous. 
The name of the new car is in the argument name.*/
trainCar *node = new trainCar;     // Create new trainCar node.
node->name = name;                 // Assign the trainCar name.
node->capacity = capacity;         // Assign the trainCar capacity.
node->occupancy = passengers;      // Assign the trainCar occupancy.
 
node->previous = previousCar;      // Assign the previous pointer.
node->next = previousCar->next;    // Assign next pointer.
node->next->previous = node;       // Assign next previous pointer to node.
previousCar->next = node;          // Assign previous next node to node.

cout<<node->name<<":"<<node->capacity <<":"<<node->occupancy<<endl;
}


void Train::addPassengers(string name, int numPassengers){
/* Add passengers to the car. The name of the car to add to is the argument name. 
If the car is full, this method should call addCar.*/
trainCar *crawler = new trainCar;
crawler = engine;
while(crawler != NULL){
    if(name == crawler->name){                                  // Check if name is the same as the crawler name.
        int total = crawler->occupancy + numPassengers;         // Set the total number of passengers.
        while(total > crawler->capacity){                       // Run while 
            crawler->occupancy = crawler->capacity;
            total -= crawler->capacity;
            trainCar *node = new trainCar;
            int newTotal = total;
            if(total > crawler->capacity){
                crawler->occupancy = crawler->capacity;
                total -= crawler->capacity;
                newTotal = total;
            } else {
                newTotal = total;
            }
            addCar(name, numPassengers, newTotal, crawler);
        }
        if(total < crawler->capacity){
            crawler->occupancy = total;
        }
    }

    if(crawler->occupancy == crawler->capacity){
        trainCar *node = new trainCar;
        node->next = NULL;
        node->next->capacity = crawler->capacity;
        node->next->name = crawler->name;
    }
    crawler = crawler->next;
}


}


void Train::printTrain(){
/* Start at the head of the train and print the name and occupancy of each car in 
order to the end of the train, and then back again to the head of the train.	*/
if (engine == NULL) {
        cout << "Empty Engine" << endl; 
        return;
    }

    trainCar *crawler = engine;
    while(crawler != NULL) {
        cout<<crawler->name<<": "<<crawler->occupancy<<", ";
        // if (crawler->next != NULL){ //no arrow after last node
        //     cout<<" --> ";
        // }
        crawler = crawler->next;
    }

    //cout << "\n\nhead: " << head->val << endl;
    //cout << "tail: " << tail->val << endl << endl;
}

void Train::buildTrain(std::string names[], int caps[], int trainSize){
/* Build the initial train from the cars given in this writeup. The cars can be fixed in the function, 
you do not need to write the function to work with any list of cars. */

for(int i = 0; i < trainSize-1; i++){
    if(engine == NULL){                 // If first time through...
        trainCar *node = new trainCar;  // Create new trainCar object.
        
        node->name = names[i];          // Assign engine name.
        node->capacity = caps[i];       // Assign engine capacity.
        node->occupancy = 1;            // Assign engine occupancy.

        engine = node;                  // Point engine pointer to engine node.
    } else {
        trainCar *node = new trainCar;

        node->name = names[i];          // Assign car name.
        node->capacity = caps[i];       // Assign car capacity.
        node->occupancy = 0;            // Assign car occupancy.
        
        node->previous = caboose;       // Point previous pointer of new node to where tail currently is.
        caboose->next = node;           // Point next pointer of caboose (the now second to last node) to the new tail node.
        caboose = node;                 // Point caboose pointer to caboose node.
   }
}
    trainCar *node = new trainCar;
    node->name = names[trainSize-1];    // Assign caboose name.
    node->capacity = caps[trainSize-1]; // Assign caboose capacity.        
    node->occupancy = 1;                // Assign caboose occupancy.
    caboose = node;                     // Point caboose pointer to new node.

    printTrain();
    
    return;
}