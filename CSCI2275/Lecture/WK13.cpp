/* HEAPS & PRIORITY QUEUES:
 * Highest priority item is at the head. 
 * PQ is typically implemented with a heap data structure.
 * min-heap : priority is min value
 * max-heap : priority is max value
 * 
 * Heap: partially ordered complete (all levels are full until the bottom) binary tree.
 * - push(int k) // add to heap and move to correct position
 * - if(currentSize == capacity){
 * -    cout<<"FULL"<<endl;
 * - } else {
 * -    int i = CurrentSize;
 * -    heap[i] = k; // add new value @ index i
 * -    while(i > 1 && floor(heap[i/2]) > heap[i]{
 * -        swap(heap[i], heap[i/2]);
 * -        i = i/2;
 * -    }
 * - }
 * 