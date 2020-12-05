#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include "CarAndSpot.h"

using namespace std;

//enum color {RED, BLACK};

rbTree::rbTree(){};
rbTree::~rbTree(){};

rbTree::rbTree(int initNumSpots){
/* Constructor */
    numSpots = initNumSpots;
    root = NULL;
    for(int i = 0; i < numSpots; i++){
        taken.push_back(false);
    }
}

void rbTree::carEnters(time_t in){
/* Add car to RB tree. */
    rbNode* newCar = carEntersHelper(root, in); // BST insert
    //fixTree(root,newCar);
} 

rbNode* rbTree::carEntersHelper(rbNode* node, time_t in){
/* Recursively BST insert the new car into the RB Tree */
    
    // If the tree is empty, make new node the root and return the new node.
    if(root == NULL){
        cout<<"New Root"<<endl;
        numCars++;
        int spotNum = assignSpot();
        root = new rbNode(spotNum,0,1,in,NULL,NULL,NULL);
        string st;
        st = ctime(&root->car.timeIn);
        cout<<st<<endl;
        return NULL;
    }

    // Consider right subtree.
    if(difftime(in,node->car.timeIn) > 0){  
        // Empty right subtree.
        if(node->right == NULL){
            node->right = new rbNode(assignSpot(),0,1,in,NULL,NULL,node);
            //taken[node->right->spot.spotNumber] = true;
            cout<<node->right->spot.spotNumber<<endl;
            numCars++;
            return node->right;
       
        // Not Empty.
        } else {
            return carEntersHelper(node->right,in);
        }      
   
    // Consider left subtree.
    } else {
        // Empty left subtree.
        if(node->left == NULL){
            node->left = new rbNode(assignSpot(),0,1,in,NULL,NULL,node);
            //taken[node->left->spot.spotNumber] = true;
            numCars++;
            return node->left;

        // Not Empty.
        } else {
            return carEntersHelper(node->left,in);
        }               
    }
}

float rbTree::carLeaves(int numSpot){
/* Delete car from RB tree and charge customer. */

    return 0;
}    


rbNode* rbTree::search(int spotNum){
/* Search for node in tree based on spot number. */

    return NULL;
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
    if(node == NULL){                   // If no node found...
        return;                         // Return.
    }

    printRBTreeHelper(node->right);     // Then get the largest node.
    
    string st;
    st = ctime(&node->car.timeIn);
    cout<<"Spot #"<<node->spot.spotNumber<<" : "<<"Time In: "<<st<<"-->";

    printRBTreeHelper(node->left);      // Get the smallest node first.

}

void rbTree::fixTree(rbNode* root, rbNode* newCar){     
/* Main function used to balance the tree. */
    rbNode* uncle = NULL;  // Uncle node.

    // Base case where new car is the root.
    if(root == newCar){
        newCar->color = BLACK;
        return;
    }

    while(newCar->parent != NULL && newCar->parent->color == RED){
        rbNode* grandParent = newCar->parent->parent;
        
        // CASE 1: Parent of newCar is left child of grandparent.
        if(grandParent->left == newCar->parent){
            
            // Check if uncle node exists.
            if(grandParent->right != NULL){ 
                uncle = grandParent->right;
                
                // CASE 1-A: The uncle of newCar is red. (Only recoloring required)
                if(uncle->color == RED){
                    recolor(newCar,uncle);
                    newCar = grandParent;
                }
            } else { // If uncle node does not exist
                
                // CASE 1-B: newCar is right child of its parent. (Rotation and recoloring required)
                if(newCar->parent->right == newCar){
                    newCar = newCar->parent;
                    leftRotate(newCar);
                } // This is supposed to be case 1-C: newCar is left child of its parent. Why does it happen regardless?
                  // Shouldnt the setup be one big if with 3 nested if statements? 
                  // Why to I check if things are NULL? Shouldn't I check if they have a null leaf node?
                newCar->parent->color = BLACK;
                grandParent->color = RED;
                rightRotate(grandParent);
            }
        // CASE 2: Parent of NewCar is right child of grandparent.
        } else {
            
            // Check if uncle node exists.
            if(grandParent->left != NULL){
                uncle = grandParent->left;

                // CASE 2-A: The uncle of newCar is red. (Only recoloring required)
                if(uncle->color == RED){
                    recolor(newCar,uncle);
                    newCar = grandParent;
                }
            } else { // If uncle node does not exist
                
                // CASE 2-B: NewCar is left child of parent.
                if(newCar->parent->left == newCar){
                    newCar = newCar->parent;
                    rightRotate(newCar);
                } // This is supposed to be case 2-C: newCar is right child of its parent. Why does it happen regardless?
                newCar->parent->color = BLACK;
                grandParent->color = RED;
                leftRotate(grandParent);
            }
        }
        root->color = BLACK;
    }
}

void rbTree::recolor(rbNode* node,rbNode* uncle){
    node->parent->parent->color = RED;  // Make grandparent red.
    node->parent->color = BLACK;        // Make parent black.
    uncle->color = BLACK;               // Make uncle black.
}

void rbTree::rightRotate(rbNode* node){
/* Rotates a subtree (or the root) right (used for balancing). */

   // Base Case: Left child is NULL 
    if(node->left == NULL){
        return;
    }

    rbNode* tmp = node->left;  // Temporary node for rotating.

    // Begin rotation.
    if(tmp->right != NULL){              // Check if tmp has a right child ...
        node->left = tmp->right;         // Rotate right.
        tmp->right->parent = node;       // Rotate right.
    } else {                             // If tmp has no right child ...
        node->left = NULL;               // Make the left node NULL.
    }

    // Check if rotating at root.
    if(node->parent != NULL){            // If not at root ... 
        tmp->parent = node->parent;      // Set tmp parent to node's parent.
    } 

    // Finish rotation.
    if(node->parent == NULL){            // If at the root ...
        root = tmp;                      // Make the new root at tmp.
    } else {                             // Otherwise ...
        if(node == node->parent->left){  // If node is a left child ...  ** This entire if statement seems pointless. Just say node = tmp.
            node->parent->left = tmp;    // Set node to tmp. (why not just say node = tmp?)
        } else {                         // If node is a right child ...
            node->parent->right = tmp;   // Set node to tmp (why not just set node to tmp)
        }
    }                                    
    tmp->right = node;                   // Finish rotation by setting tmp's right child to node.
    node->parent = tmp;                  // and setting node's parent to tmp.
}

void rbTree::leftRotate(rbNode* node){
/* Rotates a subtree (or the root) left used for balancing). */
    
    // Base Case: Right child is NULL 
    if(node->right == NULL){
        return;
    }

    rbNode* tmp = node->right;  // Temporary node for rotating.

    // Begin rotation.
    if(tmp->left != NULL){               // Check if tmp has a left child ...
        node->right = tmp->left;         // Rotate left.
        tmp->left->parent = node;        // Rotate left.
    } else {                             // If tmp has no left child ...
        node->right = NULL;              // Make the right node NULL.
    }

    // Check if rotating at root.
    if(node->parent != NULL){            // If not at root ... 
        tmp->parent = node->parent;      // Set tmp parent to node's parent.
    } 

    // Finish rotation.
    if(node->parent == NULL){            // If at the root ...
        root = tmp;                      // Make the new root at tmp.
    } else {                             // Otherwise ...
        if(node == node->parent->left){  // If node is a left child ...  ** This entire if statement seems pointless. Just say node = tmp.
            node->parent->left = tmp;    // Set node to tmp. (why not just say node = tmp?)
        } else {                         // If node is a right child ...
            node->parent->right = tmp;   // Set node to tmp (why not just set node to tmp)
        }
    }                                    
    tmp->left = node;                    // Finish rotation by setting tmp's left child to node.
    node->parent = tmp;                  // and setting node's parent to tmp.
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

void rbTree::reserveSpot(){
/* Used to reserve a spot in the parking lot. */


}                

// int main(){

//     int initNumSpots = 40;
//     rbTree rb(initNumSpots);

//     time_t t;
//     time(&t);
//     rb.carEnters(t);
//     rb.printRBTree();
// }