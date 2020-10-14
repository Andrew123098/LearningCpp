/* Binary Trees:
 * Each parent has 0, 1, or 2 children (max num of children is 2)
 * 
 * Node Properties:
 * 3 pointers:
 * - parent
 * - left child
 * - right child
 * data
 * 
 * Tree Features:
 * - Top of the tree is called the root
 *      - Parent of the root is NULL
 * - If the node doesn't have a left child, then left child = NULL
 *      - Same is true for the right child
 * - The bottom of a branch is called the leaf node
 *      - Both left and right children are NULL
 *
 * Traversing the Tree:
 * - We can know when we are at the bottom of a branch when both left and right children are NULL so we know to move to another branch
 * 
 * Binary Search Tree (BST):
 * - Special case of binary tree where data is ordered
 * - nodes in the left branch have values (all child values as well) less than that node
 * - nodes in the right branch have values (all child values as well) greater than or equal to the node value
 *
 * How to Build a BST:
 * - simplest: trees is constructed as the data is read.
 *      - Same data in a different order could produce a differently constructed tree
 * 
 *                           10 
 *                          /  \
 *                         3    12
 *                        / \  /  \
 *                       1   4 11  NULL
 *                            /
 *                           10
 *                               