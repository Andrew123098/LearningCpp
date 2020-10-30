
struct TreeNode
{
int key;
TreeNode *left;
TreeNode *right;
TreeNode *parent;
};

TreeNode* AddLeftSubtree(TreeNode *root1, int value, TreeNode *root2){
/*Find a value in a tree and paste the subtree rooted at its left child into another tree.
Given a value, find the node (node1) in a tree(a) which has the same key as value (node1->key==value). 
Then add the left subtree of node1 into the most-right located node (node2: it won't have children) of another tree (b). 
If node1’s left child is less than the node2->key, then paste node1's left subtree as a left child of node2, otherwise, paste it as a right child of node2. 
After you finish it, return the root pointer of tree root2.*/
    
    if(root1 == NULL){ 
        return NULL;
    } 

    // If the called node's word value is the one we want...
    if(root1->key == value){
        while(root2->right != NULL){ //Find the rightmost leaf of root2
            root2 = root2->right;
        }
        if(root1->left->key < root2->key){ //If node1’s left child is less than the node2->key, then paste node1's left subtree as a left child of node2
            while(root1->left != NULL){
                root2->left = root1->left;
                root2 = root2->left;
                root1 = root1->left;
            }
        } else {
            while(root1->left != NULL){
                root2->right = root1->left;
                root2 = root2->right;
                root1 = root1->left;
            }
        }
        while(root2->parent != NULL){
            root2 = root2->parent;
        }
        return root2;
    } 

    // If the called node's word value is greater than the one we want...
    if(root1->key > value) {
        return AddLeftSubtree(root1->left, value, root2);
    }

    // If the called node's word value is less than the one we want...
    if(root1->key < value){
        return AddLeftSubtree(root1->right, value, root2);
    } 
    
    // If the word is not in the tree..
    return NULL;
}
