/* RB Tree Insert Algorithm:
 * - 6 possible configurations that RB tree can take on.
 *  - 3 of these configurations are symetric to other 3. (depends on whether the parent of the new node is a right or left child of its parent.)
 * - First, identify thr "uncle" node in the tree (parent of new node's sibling)
 *  - Case 1: Uncle node is a red node.
 *  - Case 2: New node is a right child and uncle node is a black node.
 *  - Case 3: New node is a left child and uncle node is a black node.
 * 
 * Algorithm for RB Insert:
 */

RBInsert(value){
    node *x = insert(value); //bst insert
    while(x != root and x->parent->color == red){
        if(x-parent == x->parent->parent->left){
            node* uncle = x->parent->parent->right;
            if(uncle->color == red){
                x->parent->color = black;
                uncle->color = black;
                x->parent->parent->color = red;
                x = x->parent->parent;
            } else {
                if(x == x->parent->right){
                    x = x->parent;
                    leftRotate(x);
                    // x is now a left child
                } else {
                    x->parent->color = black;
                    x->parent->parent->color = red;
                    rightRotate(x->parent->parent);
                }
            } // end if x is a right child
        } // end uncle if
    } // end if x->parent is left child
}