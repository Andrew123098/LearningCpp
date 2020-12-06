#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "CarAndSpot.h"

// g++ -std=c++11 parkingLot.cpp CarAndSpot.cpp -o parkingLot
// ./parkingLot

using namespace std;

int main(){

    int initNumSpots = 40;
    int initRate = 2.50;
    rbTree rb(initNumSpots, initRate);

    // TODO: Make interactive list to add cars to random spots.
    string dmenu = "======Main Menu=====\n"
					          "1. Add Car\n"
					          "2. Delete Car\n"
                    "3. Display SpotInfo\n"
                    "4. Print Tree\n"
                    "5. Pretty Print\n"
                    "6. Quit\n";
int choice;
bool exit = false;
    
cout << dmenu << endl;
    
while(cin >> choice) {
        
    // Flush the newlines and other characters.
    cin.clear();
    cin.ignore();
    
    switch (choice) {
        case 1:
        { // Add a car to the parking lot.
          time_t t;
          time(&t);
          rb.carEnters(t);
          break;
        }
            
        case 2:
        { // Car leaves the parking lot.
          int spotNum = -1;
          cout<<"Please enter your spot number: ";
          cin>>spotNum;
          while(spotNum < 0 || spotNum > rb.getNumSpots()){
            cout<<"Incorrect, please enter you spot number as an integer between 0 and "<<rb.getNumSpots()<<": ";
            cin>>spotNum;
          }
          rb.carLeaves(spotNum);
          break;
        }
        
        case 3:
        { // Search for spot and if it is taken.
          rb.display(5);
          break;
        }

        case 4:
        { // Print rbTree, number of cars in parking lot, and how many spots are open.
          rb.printRBTree();
          break;
        }

        case 5:
        { // Print rbTree in file-style.
          rb.prettyPrint();
          break;
        }
            
        case 6:
        { // Quit
          exit = true;
          break;
        }
    }
    if (exit) {
            break;
        } else {
        cout << endl << dmenu << endl;
        }
  }
    return 0;
}