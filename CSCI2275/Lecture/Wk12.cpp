/* PRIORITY QUEUES:
 * - Same as a regular queue except each element has a priority score that determines its position in the queue.
 * - Priority queues are used in computer processing to prioritize the most important functions. User-facing tasks could have highest priority.
 * 
 * 
 * HEAP:
 * - data structure heap, not a memory heap.
 * - partially ordered complete binary tree.
 * - Implement our Priority Queue using a heap.
 * 
 * Min Heap:
 * - highest priority element is at the root. (Parent <= children)
 * - lowest values are the highest priority.
 * 
 * Max Heap:
 * - highest priority element is still at the root. (Parent >= children)
 * - highest values are the highest priority.
 * 
 * Building a Heap:
 * - stroe data in an array
 * - start indexing at array[i]
 * - for array[i], left child of array[i] = array[2i], right child of array[i] = array[2i+1]
 * - root at array[1]
 */

MinHeap:
public:
    minHeap(int capacity); //define size
    push(int); //add to heap
    pop(); // remove
    printHeap();
private:
    int *heap; // heap data in array
    int capacity;
    int countSize; // how many elelments stored
    void minHeapify(int); // argument is array index