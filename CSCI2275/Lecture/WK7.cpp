/*
 * Midterm this week:
 * pointers - how they work, why we need them
 * dynamic memory - how do we work with dynamic memory, why, 
 * linked list - features of a linked list, head pointer - why, tail poiinter - why?
 * node - what is it and why do we need thwm?
 * modify a list through instert, deleteing , traverse, store temp pointer
 * stacks and queues - what are they, how do they work, linked list and array implementations
 * peperations= - quizzes on canvas - think about concepts in your assignments
 * 
 * Format - canvas qiz, multiple choise, coding, fill in the blank, multiple versions for each recitation
 * open book, note, assignment, everything except other people
 *  - 1 attempt on multiple choice
 *  - Multiple attempts on coding problems
 * 
 */

/*
 * stack - first in, last out, last in, first out
 * top - position where datat is added
 * data - data structure that stores the information
 * maxSize - how big is the stack
 * push(value) - add value to top of stack
 * pop() - remove value at top of stack
 * array implementation:
 * when top = 0, stack is empty
 * top = maxSize, stack is full
 * top > maxSize, stack overflow
 * 
 * top = 0
 * push(4)
 * push(5)
 * push(6)
 * pop() = 6
 * pop() = 5
 * 
 * linked list implementation of stacks and queues
 *  - not necessarily a fixed size, but its necessary to resitrict size to avoid using all available memory.
 * 
 * array: head and tail are indeces
 * LL: head and tail are poiinters to nodes
 * circular queue: tail points to the head (do not need both directions)
 * double linked list: next and previous pointer
 * singly linked list: either next or a previous pointer but not both
 * implement LL queue  with a single LL
 * 
 * // Assumes the queue is not empty.
 * dequeue - remove the head node
 * temp = head
 * tail->next = head->next
 * head = head->next
 * return temp
 * 
 * enqueue - add new node at tail
 * n = new node(value)
 * n->next = head
 * tail->next = n
 * tail = n
 * 