struct TreeNode
{
int key;
TreeNode *left;
TreeNode *right;
TreeNode *parent;
};

TreeNode* AddSubtree(TreeNode *root, int value, TreeNode *subtree){
    if(root == NULL){ 
        return NULL;
    } 

    // If the called node's word value is the one we want...
    if(root->key == value){
        root->left = subtree;
        while(root->parent != NULL){
            root = root->parent;
        }
        return root;
    } 

    // If the called node's word value is greater than the one we want...
    if(root->key > value) {
        return AddSubtree(root->left, value, subtree);
    }

    // If the called node's word value is less than the one we want...
    if(root->key < value){
        return AddSubtree(root->right, value, subtree);
    } 
    
    // If the word is not in the tree..
    return NULL;
}