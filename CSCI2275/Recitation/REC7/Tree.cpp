#include "Tree.h"



//default constructor
Tree::Tree() {
    root = NULL;
}

//parametrized constructor
Tree::Tree(int init) {
    root = new node(init);
}

void Tree::iterativeInsert(int toIns) {
    node *insNode = new node(toIns);
    
    if (root == NULL) {
        root = insNode;
        return;
    }

    node *prober = root;
    node *lagger;
    while (prober != NULL) {
        lagger = prober;

        if (toIns < prober->value) {
            prober = prober->left; 
        } else {
            prober = prober->right;
        }
    }

    if (toIns < lagger->value) {
        lagger->left = insNode;
        insNode->parent = lagger;
    } else {
        lagger->right = insNode;
        insNode->parent = lagger;
    }


}

node* Tree::iterativeSearch(int toFind) {
    node *finder = root;

    while(finder->value != toFind && finder != NULL) {
        if (toFind < finder->value) {
            finder = finder->left;
        } else if (toFind > finder->value) {
            finder = finder->right;
        }
    }

    return finder;
}

//TODO
void recInsHelper(node *root, node *toIns) {
    //check right subtree
    if(toIns->value > root->value){
        //if right subtree is empty
        if(root->right == NULL){
            root->right = toIns;
            toIns->parent = root;
            return;
        } else { //If right subtree is not empty
            recInsHelper(root->right, toIns);
        }
    } else { //Else left subtree
        // Check if left subtree is empty
        if(root->left == NULL){
            root->left = toIns;
            toIns->parent = root;
            return;
        } else {
            recInsHelper(root->left, toIns);
        }
    }
    
}

//TODO
void Tree::recursiveInsert(int toIns) {
    node *newNode = new node(toIns);

    if(root == Null){
        root = newNode;
    }else {
        recInsHelper(root, newNode);
    }
}

//TODO
node *recSearchHelper(node *root, int want) {
    //either we're at the node w/ value == want OR there in no node
    if(root == NULL || root->value == want){
        return root;
    } else if(root->value > want){ // traverse left subtree
        return recSearchHelper(root->left, want);
    } else if(root->value < want){ // traverse right subtree
        return recSearchHelper(root->right, want);
    }
    return NULL;


}

//TODO
node* Tree::recursiveSearch(int toFind) {
    return recSearchHelper(root, toFind); //Just pass in root

}

//TODO
void pioHelper(node *root) {
    //base case - check if root equals NULL
    if(root == NULL){
        return;
    } 
    //as long as not null, go down left tree. print root. go down right tree
    //ie. left, root, right
    pioHelper(root->left);
    pioHelper(root);
    pioHelper(root->right)
    }

    // if(root != NULL){
    //     pioHelper(root->left);
    // }
}

//TODO
void Tree::printInOrder() {
    //Call the helper function starting at the root.
    pioHelper(root);
}

int main() {
    Tree myTree(5);

    //excercise!

    //insert 5
    //insert 2
    //insert 7
    //insert 4
    //insert 6
    myTree.recursiveInsert(5);
    myTree.recursiveInsert(2);
    myTree.recursiveInsert(7);
    myTree.recursiveInsert(4);
    myTree.recursiveInsert(6);
    //search 2
    node *return = 
    //^ verify node containing '2' was found
    //insert 1
    //print the inorder traversal
}