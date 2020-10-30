#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "LinkedList.h"
#include "BST.h"

using namespace std;

BST::BST(){
    root = NULL;
}

void BST::printWord(string word){
/*Print	the	word, the count for the word, and the parent, leftChild, and rightChild	words. Output format should be:
Word: <word>
Count: <count>
Parent: <parent	word>
Left Child: <left child word>
Right Child: <right child word>
*/
int opCounter = 0;
// Call search
bool inTree = searchBST(word);                                  // Find if the word exists in the tree.
if(inTree){                                                     // If the word exists in the tree...
    BSTNode* toPrint = searchBSTHelper(root, word, opCounter); // Make a temporary node to print.
    cout<<"Word: "<<toPrint->word<<endl;                        // Print the word at the node.
    cout<<"Count: "<<toPrint->count<<endl;                      // Print the count of the node.
    if(toPrint->parent == NULL){                                     // If the parent doesn't exist...
        cout<<"Parent: NULL"<<endl;                                  // Print that the parent is NULL.
    } else {                                                         // Otherwise...
        cout<<"Parent: "<<toPrint->parent->word<<endl;               // Print the parent's word.
    }
    if(toPrint->leftChild == NULL){                                  // If the left child doesn't exist...
        cout<<"Left Child: NULL"<<endl;                              // Print that the left child is NULL.
    } else {                                                         // Otherwise...
        cout<<"Left Child: "<<toPrint->leftChild->word<<endl;        // Print the left child's word.
    }
    if(toPrint->rightChild == NULL){                                 // If the right child doesn't exist...
        cout<<"Right Child: NULL"<<endl;                             // Print that the right child is NULL.
    } else {                                                         // Otherwise...
        cout<<"Right Child: "<<toPrint->rightChild->word<<endl;      // Print the right child's word.
    }
} else {                                                         // Otherwise...
    cout<<"Word does not exist in tree."<<endl;                  // Print that the word does not exist in the tree.
}
return;                                                          // Return.
}


				
int	BST::countBSTNodes(){
/*Counts the total number of nodes in the tree and returns that number. */
    int nodeCount = 1;
    
    // Base Case: If the tree is empty ...
    if(root == NULL){
        return 0;
    }
    nodeCount = countBSTNodesHelper(root, nodeCount);
    cout<<"BST Nodes: "<<nodeCount<<endl;
    return nodeCount;
}

int BST::countBSTNodesHelper(BSTNode* node, int &nodeCount){
/* Gets called by countBSTNodes to recursively count the nodes in the BST. */
    int *pnodeCount;
    pnodeCount = &nodeCount;
    
    if(node->leftChild != NULL){
        (*pnodeCount)++;
        countBSTNodesHelper(node->leftChild, *pnodeCount);
    }
    if(node->rightChild != NULL){
        (*pnodeCount)++;
        countBSTNodesHelper(node->rightChild, *pnodeCount);
    }
    return *pnodeCount;
}

int	BST::countBSTWords(){
/*Counts the total number of words in the tree and returns that number. */
    int wordCount = 1;
    
    // Base Case: If the tree is empty ...
    if(root == NULL){
        return 0;
    }
    countBSTWordsHelper(root, wordCount);
    cout<<"BST Words: "<<wordCount<<endl;
    return wordCount;
}

int BST::countBSTWordsHelper(BSTNode* node, int &wordCount){
/* Gets called by countBSTNodes to recursively count the nodes in the BST. */
    wordCount+=node->count;
    
    if(node->leftChild != NULL){
        countBSTWordsHelper(node->leftChild, wordCount);
    }
    if(node->rightChild != NULL){
        countBSTWordsHelper(node->rightChild, wordCount);
    }
    return 1;
}
				
BSTNode* BST::addWordNodeHelper(BSTNode* node, string word, int &opCounter){

    // If equal, increase count.
    if(node->word == word){
        opCounter++;
        node->count++;
        return node;
    }
    
    // Consider right subtree
    if(word > node->word){
        opCounter++;
        // Empty right subtree
        if(node->rightChild == NULL){
            node->rightChild = new BSTNode(word, node, NULL, NULL);
            return node->rightChild;
        
        // Not Empty
        } else {
             return addWordNodeHelper(node->rightChild, word, opCounter);
        }
    
    // Consider Left subtree
    } else {
        opCounter++;
        // Empty left subtree
        if(node->leftChild == NULL){
            node->leftChild = new BSTNode(word, node, NULL, NULL);
            return node->leftChild;
       
        // Not empty
        } else {
            return addWordNodeHelper(node->leftChild, word, opCounter);
        }
    }
}

int BST::addWordNode(string word){
/*Add a new node to the tree. If node already exists in the tree, update the count for
the	node. Function returns the number of comparisons in the search. */
    BSTNode *newNode = new BSTNode(word, NULL, NULL, NULL);
    int opCounter = 0;
    // Base Case: If the tree is empty...
    if(root == NULL){
        root = newNode; // Set the new node as the tree's root.
        return -1;
    }
    // If we pass the base case, start recursing through the tree to find where to add the node.
    addWordNodeHelper(root, word, opCounter);
    return opCounter;
}
			
void BST::findAlphaRange(string word1, string word2){
/*Find and print all the words in the tree between word1 and word2 in alphabetical order. 
If either word1 or word2 don’t exist in the tree, print an error message, such as
“one or more words doesn’t exist in tree”.*/

// Base Cases (throw error message):

    if(!searchBST(word1) || !searchBST(word2)){ // If either word does not exist in the tree ...
        cout<<"One or more words doesn't exist in tree."<<endl;
        return;
    } else if(word1 == word2){                  // If words 1 and 2 are the same ...
        cout<<"You entered the same word twice. Learn how to read."<<endl;
        return;
    } else if(word1 > word2){                   // If word 1 is greater than word 2 ...
        cout<<"PLEASE ENTER YOUR WORDS ALPHABETICALLY!!!!!!"<<endl;
        return; 
    } else if(root == NULL){                    // If the tree is empty ...
        cout<<"Tree is empty"<<endl;
        return;
    }
    // If we pass all of our base cases, then begine recursion throguh the tree.
    findAlphaRangeHelper(word1, word2, root);
}

void BST::findAlphaRangeHelper(string word1, string word2, BSTNode* node){
    // If reached a leaf node...
    if(node == NULL){
        return;
    }

    // If node's word is greater than the word we want...
    if(node->word > word1){
        findAlphaRangeHelper(word1, word2, node->leftChild);
    } 
    
    // If node's word is between words 1 and 2 (inclusive), then print that node's word...
    if(node->word >= word1 && node->word < word2){
        cout<<node->word<<":"<<node->count<<"-->";
    } else if(node->word == word2){
        cout<<node->word<<":"<<node->count<<endl;
    }

    // If node's word is less than the word we want...
    if(node->word < word2){
        findAlphaRangeHelper(word1, word2, node->rightChild);
    } 

    return;
}
								
				
void BST::printInOrderBSTHelper(BSTNode* node){
/*Method called in the public printInOrderBST, starting at the root.*/
    if(node == NULL){                   // If no node found...
        return;                         // Return.
    }

    printInOrderBSTHelper(node->leftChild);   // Get the smallest word first.
    
    cout<<node->word<<":"<<node->count<<"-->";

    printInOrderBSTHelper(node->rightChild);  // Then get the largest word.
}

void BST::printInOrderBST(){
/*Prints the nodes in the BST using an in-order traversal. */
    cout<<"Print In Order BST:"<<endl;
    printInOrderBSTHelper(root);
    cout<<endl;
}

BSTNode* BST::searchBSTHelper(BSTNode* node, string word, int &opCounter){ 
/*use this function to find pointer to node in BST*/
    int *popCounter;
    popCounter = &opCounter;

    // If the called node is NULL...
    if(node == NULL){ 
        return NULL;
    } 

    // If the called node's word value is the one we want...
    if(node->word == word){
        (*popCounter)++;
        cout<<"BST Operations: "<<*popCounter<<endl;
        return node;
    } 

    // If the called node's word value is greater than the one we want...
    if(node->word > word) {
        (*popCounter)++;
        return searchBSTHelper(node->leftChild, word, opCounter);
    }

    // If the called node's word value is less than the one we want...
    if(node->word < word){
        (*popCounter)++;
        return searchBSTHelper(node->rightChild, word, opCounter);
    } 
    
    // If the word is not in th tree..
    return NULL;
}

bool BST::searchBST(string word){
    int opCounter = 0;
    BSTNode* toRet = searchBSTHelper(root, word, opCounter);
    return toRet == NULL ? false:true; 
}