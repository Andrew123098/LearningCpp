#include <string>
#include <iostream>
using namespace std;

struct node {
    int value;
    node *parent;
    node *left;
    node *right;

    node() {
        value = INT32_MIN;
        parent = NULL;
        left = NULL;
        right = NULL;
    }

    node(int input) {
        value = input;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

class Tree {
    private:
        node* root;
    public:
        Tree();
        Tree(int);
        void  iterativeInsert(int); 
        node* iterativeSearch(int); 
        void  recursiveInsert(int); //TODO
        node* recursiveSearch(int); //TODO
        void  printInOrder();       //TODO
};