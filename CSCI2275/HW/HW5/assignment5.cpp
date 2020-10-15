#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Train.h"
#include "Queue.h"

// g++ -std=c++11 Train.cpp Queue.cpp assignment5.cpp -o assignment5
// ./assignment5 ticketsSold.txt

using namespace std;

int main(int argc, char *argv[]){
    string names[9] = {"Gilette", "Oreville", "Keystone", "Addie Camp", "Redfern", "Mystic", "Rochford", "Harney Canyon", "Bluebird"};
    int caps[9] = {48, 40, 35, 25, 20, 50, 52, 40, 50};
    Train myTrain;
    myTrain.printTrain();
    ifstream tickets;
    tickets.open(argv[1]);
    // throw an error if we couldn't open the file
    if (!tickets)
    {
        cout << "Error: Could not open file for reading" << endl;
        return 0;
    }


    Queue myQueue(9);
    
    // for(int i = 0; i < 9; i++){
    //     carPassengers cp;
    //     cp.passengers = caps[i];
    //     cp.carName = names[i];
    //     myQueue.enqueue(cp);
    // }
    // myQueue.printQueue();

    // Dequeue returns the carpassenger object then call addpassengers


    // loop until the end of the file
    while(!tickets.eof()){
        //put menu here
        	std::string dmenu = "======Main Menu=====\n"
					"1. Enqueue from file\n"
					"2. Enqueue from user\n"
                    "3. Dequeue\n"
                    "4. Remove selected passengers\n"
					"5. Remove all passengers\n"
					"6. Print train\n"
					"7. Print queue\n"
					
					"8. Quit";
    
    int choice;
    bool exit = false;
    
    cout << dmenu << endl;
    
    while(cin >> choice) {
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
				//enqueue from file
                bool success = false;
                string data, temp;
                carPassengers finput;

                // Get data from the file and store in carPassengers struct
                getline(tickets, data);
                stringstream ss(data);
                getline(ss, finput.carName, ',');
                getline(ss, temp);
                finput.passengers = stoi(temp);

                // Call enqueue for this struct and return success or failure.
                success = myQueue.enqueue(finput);
                if(success == false){
                    cout<<"Failed to add to queue. Please try again later."<<endl;
                } else {
                    cout<<"Added "<<finput.passengers<<" tickets for "<<finput.carName<<" car to the queue."<<endl;
                }
                break;
            }
            
            case 2:
            {
				//enqueue from user
                bool success = false;
                bool nameChecker = false;
                bool countChecker = false;
                int index = 0;
                carPassengers input;
                
                // Check if user input a valid car name
                while(nameChecker == false){
                    cout<<"Please enter a train name from the following list: Gilette, Oreville, Keystone, Addie Camp, Redfern, Mystic, Rochford, Harney Canyon, Bluebird:"<<endl;
                    cin>>input.carName;
                    for(index = 0; index < 9; index++){
                        if(input.carName == names[index]){
                            nameChecker = true;
                            break;
                        }
                    }
                    if(nameChecker == false){
                        cout<<"Inputted name did not match any of the given train car names."<<endl<<endl;
                    }
                }

                // Check if user input a valid number of tickets
                while(countChecker == false){
                    cout<<"Please enter the number of passengers you wish to add. Due to limited space, please enter a number less than "<<caps[index]<<": ";
                    cin>>input.passengers;
                    if(input.passengers > caps[index]){
                        cout<<"We do not have that much space in that car. Please enter a lower number"<<endl;
                    } else {
                        countChecker = true;
                    }
                }

                // Call enqueue for the struct and return success or failure
                success = myQueue.enqueue(input);
                if(success == false){
                    cout<<"Failed to add to queue. Please try again later."<<endl;
                } else {
                    cout<<"Added "<<input.passengers<<" tickets for "<<input.carName<<" car to the queue."<<endl;
                }
                break;
            }
            case 3:
            {
                // Dequeue and passengers to train
                carPassengers addNewPassengers;
                addNewPassengers = myQueue.dequeue();
                
                // Passengers will be added to the train if success = true, that happens in dequeuePassengers
                myTrain.addPassengers(addNewPassengers.carName, addNewPassengers.passengers);
                break;
            }
            case 4:
            {
                //remove passengers
                myTrain.removePassengers();
                break;
            }
            case 5:
            {
                //remove all passengers and delete cars
                myTrain.removeAllPassengers();
                break;
            }
            case 6:
            {
                //print train
                myTrain.printTrain();
                break;
            }
            case 7:
            {
                //print queue
                myQueue.printQueue();
                break;
            }
            case 8:
            {
                exit = true;
                break;
            }
        }
        
        if (exit) {
            break;
        }
        
        cout << dmenu << endl;
    }

    }    

}