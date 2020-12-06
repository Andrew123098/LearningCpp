#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <math.h>
#include "CarAndSpot.h"

using namespace std;

//enum color {RED, BLACK};

rbTree::rbTree(){};
rbTree::~rbTree(){};

rbTree::rbTree(int initNumSpots, double initRate){
/* Constructor */
    numSpots = initNumSpots;            // Define size of parking lot.
    rate15min = initRate;               // Define rate charged by parking lot per 15 minutes.
    numCars = 0;                        // Initialize number of cars in lot.
    revenue = 0;
     
    TNULL = new rbNode;                 // Make NIL leaf node.
    TNULL->color = BLACK;
    TNULL->left = NULL;
    TNULL->right = NULL; 
    root = TNULL;                       // Make root a NIL leaf node.
    
    for(int i = 0; i < numSpots; i++){  // Initialize all values in taken vector to not taken.
        taken.push_back(false);
    }
}

void rbTree::carEnters(time_t in){
/* Add car to RB tree. */
    
    // Base Case: Parking Lot is Full
    if(getNumCars() == getNumSpots()){
        cout<<"This Parking Lot is Full."<<endl;
        return;
    }

    // Create new node.
    rbNode* newCar = new rbNode;
    newCar->parent = NULL;
    newCar->right = TNULL;
    newCar->left = TNULL;
    newCar->color = RED;
    newCar->spot.spotNumber = assignSpot();
    newCar->car.timeIn = in;
    newCar->spot.taken = 0;
    newCar->spot.reserved = 1;

    // Make helper nodes for insertion.
    rbNode* helper1 = NULL;
    rbNode* helper2 = root;

    // Find proper place to insert new node into RB tree.
    while(helper2 != TNULL){
        helper1 = helper2;
        if(difftime(in,helper2->car.timeIn) <= 0){
            helper2 = helper2->left;
        } else {
            helper2 = helper2->right;
        }
    }

    // Find if need to insert as left node, right node, or root node.
    newCar->parent = helper1;
    if(helper1 == NULL){
        root = newCar;
    } else if (difftime(in,helper1->car.timeIn) <= 0){
        helper1->left = newCar;
    } else {
        helper1->right = newCar;
    }

    // If new node is root node, make it black and return.
    if(newCar->parent == NULL){
        newCar->color = BLACK;
        return;
    }

    // If tree is too small, do not try to fix the tree.
    if(newCar->parent->parent == NULL){
        return;
    }

    // Otherwise, fix the tree.
    fixEnter(newCar);
} 

void rbTree::fixEnter(rbNode* newCar){     
/* Main function used to balance the tree. */
    
    rbNode* uncle;
    while(newCar->parent->color == RED){
        
        // CASE 1: Node's parent is right child.
        if(newCar->parent == newCar->parent->parent->right){
            uncle = newCar->parent->parent->left;

            // CASE 1-A: Uncle is Red. (Only recoloring required)
            if(uncle->color == RED){
                recolor(newCar,uncle);
                newCar = newCar->parent->parent;
            
            // CASE 1-B: Uncle is black.
            } else {
                // CASE 1-B.1: New car is left child. (right-left rotate).
                if(newCar == newCar->parent->left){
                    newCar = newCar->parent;
                    rightRotate(newCar);
                }
                // CASE 1-B.2: New car is right child (left rotate only).
                newCar->parent->color = BLACK;
                newCar->parent->parent->color = RED;
                leftRotate(newCar->parent->parent);
            }
        
        // CASE 2: Node's parent is left child.
        } else {
            uncle = newCar->parent->parent->right;

            // CASE 2-A: Uncle color is red. (Only recoloring required)
            if(uncle->color == RED){
                recolor(newCar,uncle);
                newCar = newCar->parent->parent;

            // CASE 2-B: Uncle is black.
            } else {
                // CASE 2-B.1: New car is right child. (left-right rotate)
                if(newCar == newCar->parent->right){
                    newCar = newCar->parent;
                    leftRotate(newCar);
                }
                // CASE 2-B.2: New car is left child. (right rotate only)
                newCar->parent->color = BLACK;
                newCar->parent->parent->color = RED;
                rightRotate(newCar->parent->parent);
            }
        }
        // No need to fix anything if the new car is the root.
        if(newCar == root){
            break;
        }
    }
    // Root is always black.
    root->color = BLACK;
}

void rbTree::carLeaves(int numSpot){
/* Delete car from RB tree and charge customer. */
    rbNode* leaving = leaveHelper(root, numSpot); // Delete the car from the rbTree and store its data locally.
    if(leaving == NULL){                          // If the car did not exist in the tree ...
        cout<<"Spot is not taken."<<endl;         // Print the error message.
        return;                                   // And return.
    }                                              
    time_t timeOut;
    time(&timeOut);                               // Get the current time the car is leaving.
    leaving->car.timeOut = timeOut;               // Store time out for the car leaving in the node.
    leaving->car.price = calculatePrice(leaving->car.timeIn,leaving->car.timeOut); // Calculate the price.
    cout<<"Price charged to car: $"<<leaving->car.price<<endl; // Print the price charged to the car.
    revenue += leaving->car.price;                // Add the price charged to the car to the total revenue.
    delete leaving;                               // Clear the data held in the node to prevent memory leak.
}   

rbNode* rbTree::leaveHelper(rbNode* node, int spotNum){
/* Moves in order through all nodes in the tree to find car to delete. */
    
    // Find if node exists in the tree.
    rbNode* toDel = search(root, spotNum);
    
    // If spot has not been taken, return null.
    if(toDel == NULL){
        cout<<"ToDel is NULL"<<endl;
        return NULL;
    }

    // Make 2 helper nodes for deleting and swapping.
    rbNode* helper1 = NULL;
    rbNode* helper2 = toDel;

    // Save OG color of node to delete.
    bool toDelOGColor = toDel->color;

    // Perform proper swapping where we replace deleted node with smallest node in right tree.
    if(toDel->left == TNULL){                   // If the node to delete has a NIL left child ...
        helper1 = toDel->right;                 // Set helper1 to its right child.
        rbMove(toDel,toDel->right);             // And move the tree up into place.
    } else if(toDel->right == TNULL){           // Or if the node to delete has a NIL right child ...
        helper1 = toDel->left;                  // Set helper1 to its left child.
        rbMove(toDel,toDel->left);              // And move the tree up into place.
    } else {                                    // Otherwise, if neither left or right child is NIL ...
        helper2 = minimum(toDel->right);        // Set helper2 to the minimum node in the right subtree.
        toDelOGColor = helper2->color;          // Set the OG color to the color of the minimum node.
        helper1 = helper2->right;               // Set helper1 to be helper2's right child.
        if(helper2->parent == toDel){           // If helper2 is the child of the node to delete ...
            helper1->parent = helper2;          // **This might not make sense. Set helper1's parent to be helper2.
        } else {                                // Otherwise, if helper2 (the minimum node) is not a child of the node to delete ...
            rbMove(helper2,helper2->right);     // Swap the minimum node with its right child.
            helper2->right = toDel->right;      // Make the minimum node's right child the right child of the node to delete.
            helper2->right->parent = helper2;   // And set the parent node of the right child of the minimum node.
        }                                       // Then ..

        rbMove(toDel,helper2);                  // Make the node to delete equal to helper2 (the minimum node).
        helper2->left = toDel->left;            // Set the left child of the new node to be the left child of the old node.
        helper2->left->parent = helper2;        // Set the parent node of the left child of the previous node to the new node (the minimum node).
        helper2->color = toDel->color;          // Set the color of the new node to the color of the old node.
    }
    if(toDelOGColor == BLACK){                  // If the old color was black ...
        fixLeave(helper1);                      // Fix the tree.
    }
    return toDel;                               // Return the node to delete.
}

void rbTree::fixLeave(rbNode* node){   
/* Fixes the tree to make sure it fllows the rules of an RB Tree. Takes in the Node that replaced the deleted node. */           
    rbNode* helper;

    // Run while the node is not the root and the color is BLACK.
    while(node != root && node->color == BLACK){
        
        // CASE 1: Node is left child.
        if(node == node->parent->left){
            helper = node->parent->right; // Sibling node.
            
            // CASE 1-A: Sibling node is RED.
            if(helper->color == RED){
                helper->color = BLACK;
                node->parent->color = RED;
                leftRotate(node->parent);
                helper = node->parent->right;
            }
            
            // CASE 1-B: Sibling node has 2 black children.
            if(helper->left->color == BLACK && helper->right->color == BLACK){
                helper->color == RED;
                node = node->parent;

            // CASE 1-C: Sibling node has a red child.
            } else {

                // CASE 1-C.1: Sibling node has a red left child.
                if(helper->right->color == BLACK){
                    helper->left->color = BLACK;
                    helper->color = RED;
                    rightRotate(helper);
                    helper = node->parent->right;
                }
                // CASE 1-C: Sibling node has a red child.
                helper->color = node->parent->color;
                node->parent->color = BLACK;
                helper->right->color = BLACK;
                leftRotate(node->parent);
                node = root;
            }

        // CASE 2: Node is right child.
        } else {
            helper = node->parent->left; // Sibling node.

            // CASE 2-A: Sibling node is red.
            if(helper->color == RED){
                helper->color = BLACK;
                node->parent->color = RED;
                rightRotate(node->parent);
                helper = node->parent->left;
            }

            // CASE 2-B: Sibling node has 2 black children.
            if(helper->right->color == BLACK && helper->left->color == BLACK){
                helper->color = RED;
                node = node->parent;

            // CASE 2-C: Sibling node has a red child.
            } else {

                // CASE 2-C.1: Sibling node has a red right child.
                if(helper->left->color == BLACK){
                    helper->right->color = BLACK;
                    helper->color = RED;
                    leftRotate(helper);
                    helper = node->parent->left;
                }
                
                // CASE 2-C: Sibling node has a red child.
                helper->color = node->parent->color;
                node->parent->color = BLACK;
                helper->left->color = BLACK;
                rightRotate(node->parent);
                node = root;
            }
        }
    }
    node->color = BLACK; // Make sure the replacement node is black.
}

rbNode* rbTree::minimum(rbNode* rootST){
/* Finds the minimum value of a given subtree. */
    while(rootST->left != TNULL){  // While next node is not NIL ...
        rootST = rootST->left;     // Move to left child.
    }                              // Then ...
    return rootST;                 // Return leftmost child of given root.
}

void rbTree::rbMove(rbNode* node1, rbNode* node2){
/* Moves value of node2 into node1. */
    if(node1->parent == NULL){               // If node1 is the root ...
        root = node2;                        // Set the root equal to node2. 
    } else if(node1 == node1->parent->left){ // If node1 is a left child ...
        node1->parent->left = node2;         // Make node2 the left child of node1's parent.
    } else {                                 // If node1 is a right child ...
        node1->parent->right = node2;        // Make node2 the right child of node1's parent.
    }                                        // Then ...
    node2->parent = node1->parent;           // Set node2's parent to node1's parent.
}

double rbTree::calculatePrice(time_t in, time_t out){
/* Calculates price to charge car that is leaving. */
    double timeInLot = difftime(out,in);  // Gives time in seconds.
    timeInLot = round(timeInLot/(60*15)); // Gives number of 15 minute intervals spent in lot.
    double price = timeInLot*rate15min;   // Price to charge customer.
    return price;                         // Return price to charge.
}


rbNode* rbTree::search(rbNode* node, int spotNum){
/* Search for node in tree based on spot number. */
// This recursive search doesnt work. I either need to do an iterative inorder traversal to search, or, 
// make a vector that holds all node values in order of spot number and then search the tree normally using the time in value from the vector.
    if(node != TNULL){                  
        search(node->left, spotNum);         // Get the smallest node first.
        
        if(node->spot.spotNumber == spotNum){  // If node has same spot number as searching for ...
            return node;                       // Return that node.
        }

        search(node->right, spotNum);        // Then get the largest node.
    }
    return NULL;
} 

void rbTree::display(int spotNum){
/* Displays info about that spot in the rbTree. */

}

int rbTree::getNumSpots(){
/* Gets the number of spots in the parking lot. */
    return numSpots;
}                  

int rbTree::getNumCars(){
/* Gets the number of cars in the parking lot. */
    return numCars;
}     

void rbTree::printRBTree(){
/* Prints the entire RB tree in order. */
    cout<<"Print In Order RBTree:"<<endl;
    printRBTreeHelper(root);
    cout<<endl;
}

void rbTree::printRBTreeHelper(rbNode* node){
/* Helper for recursive print. */  
    if(node != TNULL){                  
        
        printRBTreeHelper(node->left);      // Get the smallest node first.
        
        // Convert time_t type to string and print w/ spot number.
        string st;
        st = ctime(&node->car.timeIn);
        cout<<"Spot #"<<node->spot.spotNumber<<" : "<<"Time In: "<<st;

        printRBTreeHelper(node->right);     // Then get the largest node.
    }
}

void rbTree::prettyPrint(){
/* Print the RB tree file-style */
    if(root){
        cout<<endl<<"Pretty Print:"<<endl;
        prettyPrintHelper(root,"",true);
    }
}

void rbTree::prettyPrintHelper(rbNode* root, string indent, bool last){
    if(root != TNULL){
        cout<<indent;
        if(last){
            cout<<"R----";
            indent += "     ";
        } else {
            cout<<"L----";
            indent += "|    ";
        }
        string sColor;
        if(root->color == RED){
            sColor = "RED";
        } else {
            sColor = "BLACK";
        }
        string st;
        st = ctime(&root->car.timeIn);
        st.pop_back();
        st.erase(0,10);
        st.erase(st.length()-4,st.length());
        cout<<st<<"("<<sColor<<")"<<endl;
        prettyPrintHelper(root->left, indent, false);
        prettyPrintHelper(root->right, indent, true);
    }
}

void rbTree::recolor(rbNode* node,rbNode* uncle){
    node->parent->parent->color = RED;  // Make grandparent red.
    node->parent->color = BLACK;        // Make parent black.
    uncle->color = BLACK;               // Make uncle black.
}

void rbTree::rightRotate(rbNode* node){
/* Rotates a subtree (or the root) right (used for balancing). */
    rbNode* helper = node->left;
    node->left = helper->right;
    if(helper->right != TNULL){
        helper->right->parent = node;
    }
    helper->parent = node->parent;
    if(node->parent == NULL){
        root = helper;
    } else if(node = node->parent->right){
        node->parent->right = helper;
    } else {
        node->parent->left = helper;
    }
    helper->right = node;
    node->parent = helper;
}

void rbTree::leftRotate(rbNode* node){
/* Rotates a subtree (or the root) left used for balancing). */
    rbNode* helper = node->right;
    node->right = helper->left;
    if(helper->left != TNULL){
        helper->left->parent = node;
    }
    helper->parent = node->parent;
    if(node->parent == NULL){
        root = helper;
    } else if(node = node->parent->left){
        node->parent->left = helper;
    } else {
        node->parent->right = helper;
    }
    helper->left = node;
    node->parent = helper;
}

int rbTree::assignSpot(){
/* Used to randomly assign a spot to people entering the parking lot. */
    int randomSpot;
    do{
    srand((unsigned) time(0));           // Make sure new number generated is different pattern each time program is run.
    randomSpot = rand()%numSpots;        // Generate random spot between 0 and total number of spots -1 (0-indexed).
    }while(taken[randomSpot]);           // Check if spot is already taken.
    taken[randomSpot] = true;            // Mark the spot as taken in taken vector.
    cout<<"Assigning "<<randomSpot<<endl;
    return randomSpot;                   // Return spot.
}            

// int main(){

//     int initNumSpots = 40;
//     rbTree rb(initNumSpots);

//     time_t t;
//     time(&t);
//     rb.carEnters(t);
//     time(&t);
//     rb.carEnters(t);
//     time(&t);
//     rb.carEnters(t);
//     time(&t);
//     rb.carEnters(t);
//     time(&t);
//     rb.carEnters(t);
//     time(&t);
//     rb.carEnters(t);
//     rb.printRBTree();
// }