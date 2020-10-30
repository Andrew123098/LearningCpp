/* Deleting Nodes in a BST
 * - Zero Child Case:
 * - One Child Case:
 * - Two Child Case: (More complicated b/c we have to restructure the tree)
 *      - Something has to replace the deleted node
 *          - Typically use min value in right branch of deleted node
 *          - Can also use max value in left branch of deleted node
 *      - How do we find the min value in a branch?
 *          - Start at root of the branch. In this, root is right child of node to delete. Go left. 
 *          - tmp = node->rightchild
 *          - while (tmp->leftchild!=nullptr)
 *              - tmp = tmp->leftchild
 *          - min = tmp
 *      - Assume min is the right child
 * 
 *          
 * 