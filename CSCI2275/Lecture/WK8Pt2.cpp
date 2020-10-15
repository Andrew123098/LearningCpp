/* Binary Search Tree (BST):
 * - Has 0, 1, or 2 children
 * - Tree is ordered
 * - Left branch is < node
 * - Right brnahc is >= node
 * - Why use a BST?
 *   - Efficient operations if the tree is balanced?
 * 
 * If the data is already orded, this leads ot an unbalanced tree.
 * - ex. 1,2,3,4,5 would result in a tree 1-2-3-4-5 
 * 
 * BST Operations:
 * - insert a node
 * - search for a value
 * - print the contents of the tree
 * - delete a node
 * 
 * Inserting a node:
 * - Iterative and recursive approaches
 * - Iterative:
 *     private
 *       node *root // Only way to access tree is through root
 *       insert(value)
 *       node *parent = nullptr
 *       node *tmp = root
 *       node *n = new node(value) // Allocate memory for new node
 *     
 *     while(tmp != nullptr){
 *          parent = tmp
 *          if(n->key < tmp->key){
 *              tmp = tmp->leftchild
 *          } else {
 *              tmp = tmp->rightchild
 *          }
 *      } 
 *      if(parent == nullptr){  // Empty tree
 *          root = n
 *      } else if(n->key < parent->key) {
 *          parent->leftchild = n
 *          n->parent = parent
 *      } else {
 *          parent->rightchild = n
 *          n->parent = n
 *      }
 * 
 * Searching for a Value:
 *      // Similar approach but not adding anything
 *      node *tmp = root
 *      while(tmp !=  nullptr){
 *          if(tmp->ky>value){
 *              tmp = tmp->leftchild
 *          } else if(tmp->key < value){
 *              tmp = tmp->rightchild
 *          } else {
 *              return tmp;
 *          }
 *      }
 * 
 * Trees and Subtrees:
 * - Nodes are roots of smaller subtrees
 * - Self-similarity: an object is similar to a part of itself
 * - Computationally, we can examine smaller and smaller subtrees
 * - Trees have a recursive structure - defined in terms of itself. Tree defined by the subtrees within it.
 * - Recursive algorithm is one that calls itself on smaller and smaller input until we reach a base case.
 *   - smallest unit of input is the leaf node
 * 
 * What if we wanted to print all nodes in the tree?
 *  - We needs recursion!
 *      
 *      print(node *n) // n = root to start
 *      cout<<n->key<<endl
 *      if(n->leftchild != nullptr){
 *          print(n->leftchild)
 *      }
 *      if(n->rightchild !=nullptr){
 *          print(n->rightchild)
 *      }
 *  Output: 1, 2,4,5,3,6,7 
 *  
 * This works really well for binary trees.