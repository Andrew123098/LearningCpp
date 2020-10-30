
struct TreeNode
{
int key;
TreeNode *left;
TreeNode *right;
TreeNode *parent;
};
void deleteAndReplaceMinRight(TreeNode *root, int key){
/*Write a C++ function to delete the given value from the binary search tree. 
The function takes two arguments, tree node and value of the node to be deleted. 
You only need to consider the case where the node has two children. 
The node should be replaced by the minimum node in its right subtree.*/

if(root == NULL){ 
        return;
    } 

    // If the called node's word value is the one we want...
    if(root->key == key){
        TreeNode *toDelete = new TreeNode;
        toDelete = root;

        root = root->right;
        while(root->left != NULL){
            root = root->left;
        }
        if(root->right == NULL){
            root->parent->left = NULL;
            toDelete->key = root->key;
            delete root;
        } else if(root->parent == toDelete){
            toDelete->key = root->key;
            toDelete->right = root->right;
            root->right->parent = root->parent;
            delete root;
        } else {
            root->parent->left = root->right;
            root->right->parent = root->parent;
            toDelete->key = root->key;
            delete root;
        }
        
    }
    // If the called node's word value is greater than the one we want...
    if(root->key > key) {
        deleteAndReplaceMinRight(root->left, key);
    }

    // If the called node's word value is less than the one we want...
    if(root->key < key){
        deleteAndReplaceMinRight(root->right, key);
    } 
    
    // If the word is not in the tree..
    return;
}