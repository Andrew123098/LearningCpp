
struct TreeNode
{
int key;
TreeNode *left;
TreeNode *right;
TreeNode *parent;
};
void deleteAndReplaceRight(TreeNode *root, int key){
/* Write a C++ function to delete the given value from the binary search tree. 
The function takes two arguments, tree node and value of the node to be deleted. 
Also replace the node to be deleted with its right child. 
Move its left subtree to the appropriate position in its right subtree to maintain the bst properties.*/

if(root == NULL){ 
        return;
    } 

    // If the called node's word value is the one we want...
    if(root->key == key){
        TreeNode *temp = new TreeNode;
        TreeNode *toDelete = new TreeNode;
        toDelete = root;
        temp = root->left;
        root = root->right;

        toDelete->key = root->key;
        toDelete->right = root->right;
        toDelete->left = root->left;

        delete root;
        root = toDelete;
        temp->parent = NULL;

        while(root->left != NULL){
            root = root->left;
        }

        if(root->right == NULL){
            if(root->key > temp->key){
                root->left = temp;
                temp->parent = root;
            } else {
                root->right = temp;
                temp->parent = root;
            }
        } else {
            root->left = temp;
            temp->parent = root;
        }

        
    } 

    // If the called node's word value is greater than the one we want...
    if(root->key > key) {
        deleteAndReplaceRight(root->left, key);
    }

    // If the called node's word value is less than the one we want...
    if(root->key < key){
        deleteAndReplaceRight(root->right, key);
    } 
    
    // If the word is not in the tree..
    return;
}