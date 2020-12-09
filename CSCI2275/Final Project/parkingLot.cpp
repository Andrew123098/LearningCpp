#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "CarAndSpot.h"

using namespace std;

int forceInt(string input, int max, int min);

int main(){
                                        // INSTRUCTIONS:
    int initNumSpots;                   // NUMBER OF SPOTS IN PARKING LOT
    int minSpots = 3;                   // MIN # OF SPOTS ALLOWED
    int maxSpots = 1000;                // MAX # OF SPOTS ALLOWED
    int initRate = 2.50;                // RATE CHARGED PER 15 MINUTES (SEE "CALCULATEPRICE" FUNCTION TO CHANGE TIME INTERVAL)            

    string sInitNumSpots;   
    cout<<"Welcome to my Parking Lot Simulation."<<endl<<"This program uses a Red-Black Tree to sort and organize cars in a parking lot."<<endl;
    cout<<"Please enter the number of spots in the parking lot: ";
    cin>>sInitNumSpots;

    // Force input as an integer in proper range.
    initNumSpots = forceInt(sInitNumSpots,maxSpots,minSpots);

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
string sChoice;
bool exit = false;

int maxMenu = 10;
int minMenu = 1;
    
cout << dmenu << endl;
    
while(cin >> sChoice) {
        
    // Flush the newlines and other characters.
    cin.clear();
    cin.ignore();

    // Force user entry as integer.
    choice = forceInt(sChoice, maxMenu, minMenu);

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
          int spotNum;
          string sSpotNum;
          cout<<"Please enter a spot number: ";
          cin>>sSpotNum;
          spotNum = forceInt(sSpotNum,rb.getNumSpots(),0);
          rb.carLeaves(spotNum);
          break;
        }
        
        case 3:
        { // Search for spot and if it is taken.
          int spotNum;
          string sSpotNum;
          cout<<"Please enter a spot number: ";
          cin>>sSpotNum;
          spotNum = forceInt(sSpotNum,rb.getNumSpots(),0);
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

int forceInt(string input, int max, int min){
/* Used in main to force user to input an integer. */
   int output;
   // This do-while loop is meant to force the user to enter an integer between the max and min values.
    do{
      try{ // Try converting input string to integer.
        output = stoi(input);
        if(output < min || output > max) throw 1;
      }
      catch(...){ // If number entered is not in b/w max and min values or not an int try again.
        cout<<"Please enter a number as an integer between "<<min<<" and "<<max<<": ";
        cin>>input;
      }
    }while(output < min || output > max);
    return output;
}    