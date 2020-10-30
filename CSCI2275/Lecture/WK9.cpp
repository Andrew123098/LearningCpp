/* Tree Traversals:
 * We want to evaluate each node in the tree exactly once.
 *  - Recall that a BST is ordered
 *  - Traversal that produces and ordered evaluation, or ordered list of all values is called an "in-order traversal"
 *  - EX: leftchicld, parent, rightchild.
 * Pattern for in-order traversal: Left, parent, right*/
inOrderPrint(node){
    if(node->leftChild != NULL){
        inorderPrint(node->leftchild);
    } else {
        cout<<node->value<<endl;
    }
    if(node->rightchild != NULL){
        inOrderPrint(node->rightchild){
        }
    }
}
 
/* Pre-order and Post-order:
 * - Pre Order evaluates the parents before the children
 * - PPost order valuates the parents after the children
 * 
 * Deleting Nodes from a BST:
 * - Rule: Still needs to be a valid BST after the node is delted
 *   - Leaf node Case: no additional changes are needed.
 *   - One child case (right or left): 
 *       - Is the child node a lft or right?
 *       - Is the node being deleted left or right of parent?
 *       - Move one child into delted node's position
 *       - EX Right Child: 
 *             - node->parent->leftchild = node->rightchild
 *             - node->rightchild->parent = node->parent
 *   - Two child case: Eithere left or right, or a node further down in the tree needs to replace the deleted node.
 *       - Replacement node will be somewhere in the subtree
 *       - Need to restructure the tree
 */      