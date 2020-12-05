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
    rbTree rb(initNumSpots);

    // TODO: Make interactive list to add cars to random spots.
    string dmenu = "======Main Menu=====\n"
					"1. Add Car\n"
					"2. Delete Car\n"
                    "3. Search Spot\n"
                    "4. Print Tree\n"
                    "5. Quit\n";
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
          rb.carLeaves(5);
          break;
        }
        
        case 3:
        { // Search for spot and if it is taken.
          rb.search(5);
          break;
        }

        case 4:
        { // Print rbTree, number of cars in parking lot, and how many spots are open.
          rb.printRBTree();
        }
            
        case 5:
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