//
//  BST.h
//  Assignment-6    
//  CSCI 2275
//

#ifndef BST_H
#define BST_H

#include <string>

struct BSTNode{
    std::string word;
    int count;
    BSTNode* parent;
    BSTNode* leftChild;
    BSTNode* rightChild;
    
    BSTNode(std::string in_word, BSTNode *p, BSTNode *lc, BSTNode *rc)
    {
        word = in_word;
        count = 1;
        parent = p;
        leftChild = lc;
        rightChild = rc;
    };
};


class BST
{
    
public:
    BST();
    void printWord(std::string word);
    void printInOrderBST();
    int countBSTNodes();
    int countBSTWords();
    int addWordNode(std::string word);
    void findAlphaRange(std::string word1, std::string word2); //print the words in the tree between word1 and word2
    bool searchBST(std::string word); // Helper for private version of this function
    
protected:
    
private:
    BSTNode* addWordNodeHelper(BSTNode* node, std::string word, int &opCounter);
    int countBSTNodesHelper(BSTNode* node, int &nodeCount);
    int countBSTWordsHelper(BSTNode* node, int &nodeCount);
    void printInOrderBSTHelper(BSTNode* node);
    void findAlphaRangeHelper(string word1, string word2, BSTNode* node);
    BSTNode* searchBSTHelper(BSTNode* node, std::string word, int &opCounter); //use this function to find pointer to node in BST (you can make a pointer in the function that points to the given address)
        
    BSTNode* root;
};

#endif // BST_H
