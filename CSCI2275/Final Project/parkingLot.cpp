#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "CarAndSpot.h"

using namespace std;

int main(){
                                        // INSTRUCTIONS:
    int initNumSpots;                   // NUMBER OF SPOTS IN PARKING LOT
    int minSpots = 3;                   // MIN # OF SPOTS ALLOWED
    int maxSpots = 1000;                // MAX # OF SPOTS ALLOWED
    int initRate = 2.50;                // RATE CHARGED PER 15 MINUTES (SEE "CALCULATEPRICE" FUNCTION TO CHANGE TIME INTERVAL)

    cout<<"Welcome to my Parking Lot Simulation."<<endl<<"This program uses a Red-Black Tree to sort and organize cars in a parking lot."<<endl;

    cout<<"Please enter the number of spots in the parking lot: ";
    cin>>initNumSpots;
    while(initNumSpots < minSpots || initNumSpots > maxSpots || !cin){
      cin.clear();
      cin.ignore();
      if(initNumSpots < minSpots){
        cout<<"Number of spots too small."<<endl<<"Please enter a number of spots as an integer between "<<minSpots<<" and "<<maxSpots<<": ";
      } else if(initNumSpots > maxSpots){
        cout<<"Number of spots too large."<<endl<<"Please enter a number of spots as an integer between "<<minSpots<<" and "<<maxSpots<<": ";
      } else {
        cout<<"Please enter a number of spots as an integer between "<<minSpots<<" and "<<maxSpots<<": ";
      }
      cin>>initNumSpots;
    } 

    rbTree rb(initNumSpots, initRate);

    // TODO: Make interactive list to add cars to random spots.
    string dmenu = "======Main Menu=====\n"
					          "1. Car Enters\n"
					          "2. Car Leaves\n"
                    "3. Display Spot Info\n"
                    "4. Print Tree\n"
                    "5. Pretty Print\n"
                    "6. Display All Spots\n"
                    "7. Number of Cars in Lot\n"
                    "8. Number of Empty Spots\n"
                    "9. Total Revenue\n"
                    "10. Quit\n";
int choice;
bool exit = false;

int maxMenu = 10;
int minMenu = 1;
    
cout << dmenu << endl;
    
while(cin >> choice) {
        
    // Flush the newlines and other characters.
    cin.clear();
    cin.ignore();

      if(choice < minMenu || choice > maxMenu || !cin){
        cout<<"Please enter a number of spots as an integer between "<<minMenu<<" and "<<maxMenu<<": ";
        cin>>choice;
      }
    
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
          int spotNum = -1;
          cout<<"Please enter a spot number: ";
          cin>>spotNum;
          while(spotNum < 0 || spotNum > rb.getNumSpots()){
            cout<<"Incorrect, please enter a spot number as an integer between 0 and "<<rb.getNumSpots()<<": ";
            cin>>spotNum;
          }
          rb.display(spotNum);
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
        { // Display all spots.
          rb.dispAllSpots();
          break;
        }

        case 7:
        { // Display number of cars in the lot.
          cout<<"Cars in lot: "<<rb.getNumCars()<<endl;
          break;
        }

        case 8:
        { // Display number of empty spots in the lot.
          int emptySpots = rb.getNumSpots() - rb.getNumCars();
          cout<<"Number of empty spots: "<<emptySpots<<endl;
          break;
        }

        case 9:
        { // Display total revenue the parking lot has made.
          cout<<"Total Revenue: $"<<rb.getRevenue()<<endl;
          break;
        }
            
        case 10:
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