#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Train.h"
#include "Queue.h"

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

void Train::removePassengers(){
    /* This option simulates passengers leaving the train. The user enters the name
    of a car and the number of passengers exiting. When a car is empty, delete it. 
    If the number of passenegrs is greater than capacity, set occupancy = 0 and delete the car.*/

    //ask user for number of passengers and car
    bool nameChecker = false;
    char removeName[100];
    int removePassengers = -1;
    trainCar *crawler = new trainCar;
    

    // Make sure name entered equals one of the names in the train that is not the engine or caboose.           
    while(nameChecker == false){
        crawler = engine;
        cout<<endl<<"Please enter a car name from the train below: "<<endl;
        printTrain();
        cout<<endl<<"Car Name: ";
        cin.getline(removeName, sizeof(removeName));
        cout<<endl;
        while(crawler->next != nullptr){
            if(removeName == crawler->name){
                nameChecker = true;
                break;
            }
            crawler = crawler->next;
        }
        // Check the last value of the train
        if(crawler->next == nullptr){
            if(crawler->name == removeName){
                nameChecker = true;
            } else { // Throw an error if input name does not match any car name
                cout<<"ERROR: Your input did not match any of the car names. "<<endl;
            }
        }

        // Make sure they don't choose the engine or caboose
        if(removeName == engine->name || removeName == caboose->name){
            nameChecker = false;
            cout<<"ERROR: You cannot remove train workers."<<endl;
        }
    }

    // Make sure the person enters a positive, non-zero number
    while(removePassengers <= 0){
        cout<<"Please enter the number of people to remove from the car: ";
        cin>>removePassengers;
        cout<<endl;
        if(removePassengers < 0){
            cout<<"ERROR: Please enter a positive number."<<endl;
        } else if(removePassengers == 0){
            cout<<"No passengers were removed."<<endl;
            return;
        }
    }

    // Remove the given number of passengeres from the given car.
    // If total people removed is greater than the occupancy, set occupancy to 0 and delete the car.
    if(removePassengers >= crawler->occupancy){
        trainCar *temp = new trainCar;
        temp = crawler;
        crawler = crawler->previous;

        temp->occupancy = 0;
        temp->capacity = 0;

        crawler->next = temp->next;
        temp->next->previous = crawler;
        
        cout<<"There are 0 people left in "<<temp->name<<"."<<endl;
        cout<<temp->name<<" was deleted from the train."<<endl<<endl;
        delete temp;
    } else { // Otherwise, just remove the passengers.
        crawler->occupancy = crawler->occupancy-removePassengers;
        cout<<"There were "<<removePassengers<<" removed from "<<crawler->name<<"."<<endl;
        cout<<"There are still "<<crawler->occupancy<<" people in "<<crawler->name<<"."<<endl<<endl;
    }
    return;
}

void Train::removeAllPassengers(){
/*This option simulates all remaining passengers leaving the train. Start from the front of	the	
train and move to the back of the train. Don’t delete the engine or the caboose. Before a car is 
deleted, print the name of the car and the number of passengers.*/

    trainCar *crawler = new trainCar;
    trainCar *deletor = new trainCar;
    crawler = engine;
    deletor = engine->next;

    while(crawler->next != caboose){
        crawler->next = deletor->next;
        deletor->next->previous = crawler;
        cout<<"Deleting "<<deletor->name<<" which has "<<deletor->occupancy<<" passengers."<<endl;
        delete deletor;
        deletor = crawler->next;
    }
    printTrain();
    cout<<endl;
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
    cout<<caboose->name<<":"<<caboose->occupancy<<endl;
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
