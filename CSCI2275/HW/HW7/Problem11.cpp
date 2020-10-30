struct TreeNode
{
int key;
TreeNode *left;
TreeNode *right;
TreeNode *parent;
};
void deleteNode(TreeNode *node, int key){
/*Write a C++ function to delete the given value from the binary search tree. 
The function takes two arguments, tree node and value of the node to be deleted. 
Also replace the node to be deleted with maximum value from left sub tree when the node has two children.*/

if(node == NULL){ 
        return;
    } 

    // If the called node's word value is the one we want...
    if(node->key == key){
        TreeNode *toDelete = new TreeNode;
        toDelete = node;

        if(node->left != NULL && node->right != NULL){
            node = node->left;
            while(node->right != NULL){
                node = node->right;
            }
            if(node->left == NULL){
                node->parent->right = NULL;
                toDelete->key = node->key;
                delete node;
            } else if(node->parent == toDelete){
                toDelete->key = node->key;
                toDelete->left = node->left;
                node->left->parent = node->parent;
                delete node;
            } else {
                node->parent->right = node->left;
                node->left->parent = node->parent;
                toDelete->key = node->key;
                delete node;
            }
        } else if (node->right == NULL && node->left == NULL){
            node->parent->right = NULL;
        } else if (node->right == NULL && node->left != NULL){
            node = node->left;
            while(node->right != NULL){
                node = node->right;
            }
            if(node->parent == toDelete){
                node->parent = toDelete->parent;
                toDelete->parent->right = node;
                delete toDelete;
            }
        } else if(node->right != NULL && node->left == NULL){
            toDelete->parent->right = toDelete->right;
            toDelete->right->parent = toDelete->parent;
            delete toDelete;
        } 
    }
    // If the called node's word value is greater than the one we want...
    if(node->key > key) {
        deleteNode(node->left, key);
    }

    // If the called node's word value is less than the one we want...
    if(node->key < key){
        deleteNode(node->right, key);
    } 
    
    // If the word is not in the tree..
    return;
}