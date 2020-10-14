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
    engine = NULL;
    caboose = NULL;                         
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
}


void Train::addPassengers(string name, int numPassengers){
//cout<<"Im infinite 1"<<endl;
/* Add passengers to the car. The name of the car to add to is the argument name. 
If the car is full, this method should call addCar.*/
trainCar *crawler = new trainCar;                                        // Create crawler pointer.
crawler = engine;                                                        // Point crawler to head of LL.
while(crawler != nullptr){                                               // While the crawler has not reached the end of the LL...
    if(name == crawler->name){                                           // If name is equal to the crawler name...
        int total = numPassengers;                                       // Set total passengers to occupancy + the new passengers.
        int newTotal = 0;
        int counter = 1;   

        while(name == crawler->next->name.substr(0, crawler->name.size()-2)) {   // While the total is greater than the train car capacity... // 
            counter++;
            crawler = crawler->next;
        }

        if((crawler->capacity - crawler->occupancy) != 0){
                int passengerCount = 0;
                while(crawler->occupancy != crawler->capacity){
                    passengerCount++;
                    crawler->occupancy++;
                    if(passengerCount == numPassengers){break; }
                }
                newTotal = total - passengerCount;
            }
        if(newTotal == 0){return; }
        
        name = name+"_"+to_string(counter);
        addCar(name, crawler->capacity, 0, crawler);
        crawler = crawler->next;

        if((newTotal+crawler->occupancy > crawler->capacity)) {
            crawler->occupancy = crawler->capacity;
            newTotal = newTotal - crawler->capacity;
            counter++;
            printTrain(); 
            } else {
                crawler->occupancy = crawler->occupancy + newTotal;
                cout<<"Added --> "<<crawler->name<<":"<<crawler->capacity<<":"<<crawler->occupancy<<endl;
                newTotal = 0;
                return;
            }
        } else {
            crawler = crawler->next;
        }
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
        cout << " --> ";                                // Print an arrow.
        crawler = crawler->next;                        // Point crawler to next node.
        }
    cout<<caboose->name<<":"<<caboose->occupancy<<endl<<endl;
}

void Train::buildTrain(std::string names[], int caps[], int trainSize){
/* Build the initial train from the cars given in this writeup in a circular queue. The cars can be fixed in the function, 
you do not need to write the function to work with any list of cars. */

    trainCar *crawler = new trainCar(names[0], caps[0], 1, NULL, NULL);
    engine = crawler;
    cout<<engine->name<<":"<<engine->capacity<<":"<<engine->occupancy<<endl;
    for(int i = 1; i < trainSize-1; i++){
        trainCar *node = new trainCar(names[i], caps[i], 0, NULL, crawler);
        crawler->next = node;
        crawler = node;
        cout<<crawler->name<<":"<<crawler->capacity<<":"<<crawler->occupancy<<endl;
    }
    caboose = new trainCar(names[trainSize-1], caps[trainSize-1], 1, NULL, crawler);
    crawler->next = caboose;
    crawler = crawler->next;
    cout<<crawler->name<<":"<<crawler->capacity<<":"<<crawler->occupancy<<endl;
}
