// Make sure we do not compile and allocate memory twice.
#ifndef CARANDSPOT_H
#define CARANDSPOT_H

#include <iostream>
#include <ctime>
#include <string>
#include <vector>

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
    };  
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
    // Initialize full node in RB tree.
    rbNode(int initSpotNum, bool initReserved, bool initTaken, time_t initIn, rbNode* initRight, rbNode* initLeft, rbNode*initParent){
        Car car(initIn);
        Spot* pSpot = &spot;
        spot.spotNumber = initSpotNum;
        spot.reserved = initReserved;
        spot.taken = initTaken;
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
        rbTree();                                        // Default constructor.
        rbTree(int initNumSpots, double rate);           // Overloaded Constructor (defines parking lot size).
        ~rbTree();                                       // Destructor.
        
        int getNumSpots();                               // Gets the number of spots in the parking lot.
        int getNumCars();                                // Gets the number of spots available.
        double getRevenue();                             // Gets the total revenue the parking lot has made.
        void carEnters(time_t in);                       // Add car to RB tree iteratively.
        void carLeaves(int numSpot);                     // Delete car from RB tree and charge customer.
        void printRBTree();                              // Prints the entire RB tree in order.
        void prettyPrint();                              // Prints RB tree file-style.
        void display(int spotNum);                       // Displays info about that spot in the rbTree.
        void dispAllSpots();                             // Displays all spots in order of spot number and their time in.

    private:
        int assignSpot();                                // Used to randomly assign a spot to people entering the parking lot.
        double calculatePrice(time_t in, time_t out);    // Calculates price to charge car that is leaving.
        void fixEnter(rbNode* newCar);                   // Main function used to balance the tree.
        void fixLeave(rbNode* node);                     // Fixes the rbTree tree when needed after a car leaves.
        void recolor(rbNode* parent, rbNode* uncle);     // Recolors based on RB tree rules.
        void rightRotate(rbNode* node);                  // Rotates a subtree (or the root) right (used for balancing).
        void leftRotate(rbNode* node);                   // Rotates a subtree (or the root) left used for balancing).
        void rbMove(rbNode* node1, rbNode* node2);       // Moves value of node2 into node1.
        void printRBTreeHelper(rbNode* node);            // Helper for iterative print.
        void prettyPrintHelper(rbNode* root, string indent, bool last); // Recursive helper for pretty print.
        rbNode* leaveHelper(rbNode* node, int spotNum);  // Helper for carLeaves.
        rbNode* search(int spotNum);                     // Search for node in tree based on spot number.
        rbNode* minimum(rbNode* rootST);                 // Finds the minimum value of a given subtree.
        
        rbNode* root;                                    // Points to the root of the RB tree.
        rbNode* TNULL;                                   // Used for NULL Leaf Nodes.
        int numSpots;                                    // Holds the number of spots in the parking lot.
        int numCars;                                     // Holds the number of cars in the parking lot.
        double rate15min;                                // Holds the amount of money charged per 15 minutes.
        double revenue;                                  // Holds total revenue made from parking lot.
        vector<bool> taken;                              // Vector that stores all taken values for easy access (0 = taken, 1 = not taken).
        vector<rbNode*> allSpots;                        // Holds all spots in order of spot number (index is spot number).
};
#endif