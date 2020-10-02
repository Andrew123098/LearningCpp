#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Train.h"

using namespace std;

Train::Train(){
    int trainSize = 11;
    string names[trainSize] = {"The Little Engine That Could", "Gilette", "Oreville", "Keystone",
    "Addie Camp", "Redfern", "Mystic", "Rochford", "Harney Canyon", "Bluebird", "Red Caboose"};
    int caps[trainSize] = {1, 48, 40, 35, 25, 20, 50, 52, 40, 50, 1};                               
    buildTrain(names, caps, trainSize);
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

cout<<"Added --> "<<node->name<<":"<<node->capacity<<":"<<node->occupancy<<endl;
}


void Train::addPassengers(string name, int numPassengers){
/* Add passengers to the car. The name of the car to add to is the argument name. 
If the car is full, this method should call addCar.*/
trainCar *crawler = new trainCar;                                        // Create crawler pointer.
crawler = engine;                                                        // Point crawler to head of LL.
int carNumber = 2;                                                       // Initialize counter for new cars of the same name.
while(crawler != nullptr){                                               // While th crawler has not reached the end of the LL...
    if(name == crawler->name){                                           // If name is equal to the crawler name...
        int total = crawler->occupancy + numPassengers;                  // Set total passengers to occupancy + the new passengers.
        while(total > crawler->capacity){                                // While the total is greater than the train car capacity...
            crawler->occupancy = crawler->capacity;                      // Set the current train car's occupancy to the capacity.
            total = total - crawler->capacity;                           // Subtract the train car capacity from the total number of passengers.
            string scarNumber = to_string(carNumber);
            name = name+"_"+scarNumber;                                  // Concatenate the name values.
            addCar(name, crawler->capacity, crawler->capacity, crawler); // Add the full train car to the LL.
            crawler = crawler->next;                                     // Put the crawler at the newly named car.
            carNumber++;                                                 // And increment the car number.
        }
        if(total != 0){                                                  // If the remaining total is greater than zero.
            carNumber++;                                                 // Increment the train car number.
            string scarNumber = to_string(carNumber);
            name = name+"_"+scarNumber;                                  // Concatenate the name values.
            addCar(name, crawler->capacity, total, crawler);             // Add the last car of the same name.
            return;                                                      // End the fucntion.
        }
    }
    crawler = crawler->next;                                             // Point crawler to the next node.
}
}


void Train::printTrain(){
/* Start at the head of the train and print the name and occupancy of each car in 
order to the end of the train, and then back again to the head of the train.	*/
    cout<<endl<<"Print Train:"<<endl;                   // Format Title
    if (engine == nullptr) {                            // If the LL hasn't been made yet...
        cout << "empty LL" << endl;                     // Return error message.
        return;                                         // Exit function.
    }
    trainCar *crawler = engine;                         // Create crawler pointer.
    while(crawler != caboose) {                         // While the crawler is not the caboose...
        cout<<crawler->name<<":"<<crawler->occupancy;   // Print the trainCar values.
        if (crawler->next != caboose){                  // If the next value is not the caboose...
            cout << " --> ";                            // Print an arrow.
            crawler = crawler->next;                    // Point crawler to next node.
        } else {                                        // If the next value is the caboose...
            crawler = crawler->next;                    // Point crawler to caboose.
            cout<<" --> "<<crawler->name<<":"<<crawler->occupancy<<endl<<endl; // Print Values.
            break;                                      // Break out of while loop.
        }       
    }
}

void Train::buildTrain(std::string names[], int caps[], int trainSize){
/* Build the initial train from the cars given in this writeup. The cars can be fixed in the function, 
you do not need to write the function to work with any list of cars. */
    prepend(names[0], caps[0]);
    for(int i = 1; i < trainSize; i++){
        append(names[i], caps[i]);
    }
    printTrain();
    return;
}

void Train::prepend(string carName, int cap) {
    if(engine == NULL){              // If we have not declared the head yet...
        trainCar *node = new trainCar;  // Create new node.
        node->name = carName;           // Assign node name.
        node->capacity = cap;           // Assign node capacity.
        node->occupancy = 1;            // Assign node occupancy.
        engine = node;                  // Assign node to be the head.
        return;                         
    }
    
    trainCar *node = new trainCar;      // Create new node
    node->name = carName;               // Assign node name.
    node->capacity = cap;               // Assign node capacity.
    node->occupancy = 0;                // Assign node occupancy.
    
    node->next = engine;                // Point next pointer to where head currenty is.
    engine->previous = node;            // Point previous pointer of head (the now second node) to the new head node.
    engine = node;                      // Point head to new head node.
    return;
}

void Train::append(string carName, int cap) {
    if(caboose == NULL){             // If we have not declared the tail...
        trainCar *node = new trainCar;  // Create new node.
        node->name = carName;           // Assign node name.
        node->capacity = cap;           // Assign node capacity.
        node->occupancy = 1;            // Assign node occupancy.
        caboose = node;                 // Assign node to be the tail.
        return;
    }
    trainCar *node = new trainCar;      // Create new node.
    node->name = carName;               // Assign node name.
    node->capacity = cap;               // Assign node capacity.
    node->occupancy = 0;                // Assign ode occupancy.

    node->previous = caboose;           // Point previous pointer of new node to where tail currently is.
    caboose->next = node;               // Point next pointer of tail (the now second to last node) to the new tail node.
    caboose = node;                     // Point tail pointer to new tail node.
    return;   
}
