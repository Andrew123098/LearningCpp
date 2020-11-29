/* Tree balancing:
 * Worst case for unbalanced BST with n nodes is O(n) for insert, search, and delete operations
 * Worst case for balanced BST with n nodes is O(log2n)
 * This is a good reason to have tree balancing algorithms.
 * 
 * Tree Balancing Algorithms:
 * AVL Tree - simple but not used much in practice
 * Red-Black Trees - not simple, but used in many commercial applications.
 * Splay trees -
 * 
 * AVL amnd Red-Black trees add additional properties added to the tree.
 * 
 * 
 * What is a Red-Black Tree?
 * - BST where each node in the tree is assigned a color (red or black).
 * Node:
 *  Key
 *  LeftChild
 *  RightChild
 *  Parent
 *  Color
 * 
 * - Red-Black is arbitrary. It is just a binary property for the node.
 * 
 * Properties of a Red-Black Tree:
 * - A node is either red or black
 * - the root node is black
 * - each leaf node is black
 * - if a node is red, both of its children must be black
 * - For each node, all paths to the leaf nodes must contain the same number of black nodes (same is true for root node)
 * 
 *  Leaf Nodes:
 *  - In a regulare BST, leaf nodes are regular nodes that have NULL for both left and right children
 *  - Leaf nodes in a Red-Black tree, leaf nodes are empty nodes, called a null node.
 * 
 * Red-Black Tree Operations: To maintain the red-black properties
 * - Recolor - change node color
 * - Rotation - changes height of a subtree 
 *      - Recolor and rotation happen as a part of insert and delete operations on a tree.
 * 
 * Rotations:
 * - Common in tree balancing algorithms.
 * - Have left and right rotation (invereses of e/o).
 * 
 * LeftRotate 
 *                           x
 *                          / \
 *                         a   y
 *                            / \
 *                           b   c
 */   

// leftRotate(x)
// y = x->RightChild
// x->rightChild = y->leftChild
// if(y->leftChild != nullnode)
//     y->leftChild->parent = x;
//     y->parent = x->parent
// if(x->parent == nullnode)
//     root = y
// else
//     x->parent->rightChild = y

// y->leftChild = x
// x->parent = y


// Insering a node into a red-black tree:
// - same as inserting into a BST w/ a few additions.
//      - Replace nullptr w/ null node in our insert.
//      - set color of new node to red
//      - Resolve any violations of RB properties using recoloring and rotation.
// - If adding node to empty tree, broken rule that root is black, so fix by making root black.
// - If add 5 (b), 3 (r) and 2 (r), this violates the rule that a root of a subtree must have an equal number of blac nodes in al paths
//      - if we rotate, and 

