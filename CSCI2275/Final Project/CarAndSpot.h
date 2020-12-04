// Make sure we do not compile and allocate memory twice.
#ifndef CARANDSPOT_H
#define CARANDSPOT_H

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

enum Color {RED, BLACK};

struct Car{
/* Holds info about specific car or user (part of rbNode struct) */
    time_t timeIn;        // Holds real time car enters parking lot.
    time_t timeOut;       // Holds real time car leaves parking lot.
    double totalTime;     // Holds total time car spent in parking lot.
    double price;         // Holds price charged to car calulated from totalTime.

    Car(){ //dtor
        timeIn = time(0); // Get real time.
    }; // 
    Car(time_t initTimeIn){
        timeIn = initTimeIn;
    }
};

struct Spot{
/* Holds info about spcific spot in parking lot (part of rbNode struct) */
    int spotNumber;       // Holds the spot number in the parking lot.
    bool reserved;        // 0 = reserved, 1 = not reserved.
    bool taken;           // 0 = taken, 1 = not taken.

    Spot(){}; // dtor
    Spot(int initSpotNum, bool initReserved, bool initTaken){ // Initialize all Spot values
        spotNumber = initSpotNum;
        reserved = initReserved;
        taken = initTaken;
    }
};

struct rbNode{
/* Node in red-black tree used to sort cars and parking spots in parking structure. */
    Car car;                      // Stores a Car struct.
    Spot spot;                    // Stores a Spot struct.

    rbNode* right;                // Pointer to node's right child.
    rbNode* left;                 // Pointer to node's left child.
    rbNode* parent;               // Pointer to node's parent.
    bool color;                   // Either red or black.

    rbNode(){};                   // dtor
    rbNode(rbNode* initParent){   // Initialize a leaf/Null node in Red-black tree.
        spot.spotNumber = -1;     // Used to tell if node is a leaf node.
        parent = initParent; 
        right = NULL;
        left = NULL;
        color = BLACK;
    }
    // Initialize full node in RB tree.
    rbNode(int initSpotNum, bool initReserved, bool initTaken, time_t initIn, rbNode* initRight, rbNode* initLeft, rbNode*initParent){
        Car car(initIn);
        Spot spot(initSpotNum, initReserved, initTaken);
        parent = initParent;
        right = initRight;
        left = initLeft;
        color = RED;
    }
};

class rbTree
/* Class for red-black tree for parking lot organization. */
{
    public:
        rbTree();                               // Default constructor.
        rbTree(int initNumSpots);               // Overloaded Constructor (defines parking lot size).
        ~rbTree();                              // Destructor.
        void carEnters(time_t in);              // Add car to RB tree.
        rbNode* carLeaves(rbNode leaving);      // Delete car from RB tree and charge customer.
        rbNode* search(int spotNum);            // Search for node in tree based on spot number.
        int getNumSpots();                      // Gets the number of spots in the parking lot.
        int getNumCars();                       // Gets the number of spots available.
        void printRBTree();                     // Prints the entire RB tree in order.
    private:
        rbNode* carEntersHelper(rbNode* root, time_t in);// Helper for carEnters (is a BST insert function).
        void fixTree(rbNode* root, rbNode* newCar);      // Main function used to balance the tree.
        void recolor(rbNode* parent, rbNode* uncle);     // Recolors based on RB tree rules.
        void rightRotate(rbNode* node);                  // Rotates a subtree (or the root) right (used for balancing).
        void leftRotate(rbNode* node);                   // Rotates a subtree (or the root) left used for balancing).
        void printRBTreeHelper(rbNode* node);            // Helper for recursive print.
        int assignSpot();                       // Used to randomly assign a spot to people entering the parking lot.
        void reserveSpot();                     // Used to reserve a spot in the parking lot.
        rbNode* root;                           // Points to the root of the RB tree.
        int numSpots;                           // Holds the number of spots in the parking lot.
        int numCars;                            // Holds the number of cars in the parking lot.
};
#endif