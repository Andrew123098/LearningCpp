#include <iostream>

using namespace std;

#define SEPARATOR "#<ab@17943918#@>#"

/* DO NOT MODIFY */
struct headNode;
struct DLLNode{
    int key;
    DLLNode *next;
    DLLNode *previous;
    headNode *head;
    DLLNode(DLLNode *n, DLLNode *p, headNode *hn, int k){
        next = n;
        previous = p;
        key = k;
        head = hn;
    }
};
struct SLLNode{
    int key;
    SLLNode *next;
    SLLNode(SLLNode *sll, int k){
        next = sll;
        key = k;
    }
};

struct headNode{
    SLLNode *nextSLL = nullptr;
    DLLNode *nextDLL = nullptr;
    string name;
    headNode(SLLNode *sll, DLLNode *dll, string n){
        nextSLL = sll;
        nextDLL = dll;
        name = n;
    }
};


/* DO NOT MODIFY */
class LinkedList{
   private:
      headNode *hn;
      //Node *search(int val);
   public:
      LinkedList(){
         hn = new headNode(nullptr, nullptr, "head node");
      };
      void insertSLLNode(int leftVal, int newVal);
      void insertDLLNode(int leftVal, int newVal);
      SLLNode* searchSLL(int val);
      DLLNode* searchDLL(int val);

      void printSLLList();
      void printDLLList();
      void findMinAndAddAfter(int val);
};

/* DO NOT MODIFY */
void LinkedList::insertSLLNode(int leftValue, int value) {
   SLLNode* left = searchSLL(leftValue);
   SLLNode* node = new SLLNode(nullptr, value);
   
   if (left == nullptr) { /* inserting a new head node */
      if(hn->nextSLL == nullptr){
         hn->nextSLL = node;
      }else{
         node->next = hn->nextSLL;
         hn->nextSLL = node;
      }
   }
   else if (left->next == nullptr) { /* inserting a new tail node */
      left->next = node;
      if (hn->nextSLL == nullptr) 
         hn->nextSLL = node;
   }
   else { /* inserting a node in the middle */
      node->next = left->next;
      left->next = node;
   }
}

/* DO NOT MODIFY */
void LinkedList::insertDLLNode(int leftVal, int value) {
   DLLNode* left = searchDLL(leftVal);
   DLLNode* node = new DLLNode(nullptr, left, nullptr, value);
   
   if (left == nullptr) { /* inserting a new head node */
      if(hn->nextDLL == nullptr){
         hn->nextDLL = node;         
      }else{
         node->next = hn->nextDLL;
         hn->nextDLL = node;
      }
   }else if (left->next == nullptr) { /* inserting a new tail node */
      left->next = node;
      node->previous = left;
      if (hn->nextDLL == nullptr) {
         hn->nextDLL = node;
         node->head = hn;
      }
   }
   else { /* inserting a node in the middle */
      node->next = left->next;
      left->next->previous = node;
      left->next = node;
      node->previous = left;
   }
}

/* DO NOT MODIFY */
SLLNode* LinkedList::searchSLL(int val) {
   SLLNode* current = hn->nextSLL;
   while (current != nullptr) {
      if (current->key == val)
         return current;
      current = current->next;
   }
   return nullptr;
}

/* DO NOT MODIFY */
DLLNode* LinkedList::searchDLL(int val) {
   DLLNode* current = hn->nextDLL;
   while (current != nullptr) {
      if (current->key == val)
         return current;
      current = current->next;
   }
   return nullptr;
}

/* DO NOT MODIFY */
void LinkedList::printSLLList()
{
   SLLNode *current = hn->nextSLL;
   
   while (current != nullptr)
   {
      cout << current->key << " ";
      current = current->next;
   }
}
/* DO NOT MODIFY */
void LinkedList::printDLLList()
{
   DLLNode *current = hn->nextDLL;
   
   while (current != nullptr)
   {
      cout << current->key << " ";
      current = current->next;
   }
}

void LinkedList::findMinAndAddAfter(int value){
//{{STUDENT_ANSWER}}

   DLLNode *tempD = new DLLNode(hn->nextDLL->next, hn->nextDLL->previous, hn->nextDLL->head, hn->nextDLL->key); // Used to move through the list
   SLLNode *tempS = new SLLNode(hn->nextSLL, hn->nextSLL->key); //Used to move through the list

   DLLNode *minNodeD = new DLLNode(hn->nextDLL->next, hn->nextDLL->previous, hn->nextDLL->head, hn->nextDLL->key); // Used to store the minimum node
   SLLNode *minNodeS = new SLLNode(hn->nextSLL, hn->nextSLL->key); // Used to store the minimum node

   //tempD->head = hn->nextDLL;  // Set the crawler = to the head of the DLL
   //tempS = hn->nextSLL;        // Set the crawler = to the head of the SLL

   //minNodeD->head = hn->nextDLL; // Set the min node equal to the beginning of the list
   //minNodeS = hn->nextSLL;       // Set the min node equal to the bwginning of the list

   // Find the minimum of the DLL
   while(tempD->next != nullptr){
      if(tempD->key < minNodeD->key){
         minNodeD = tempD;
      }
      tempD = tempD->next;
   }
   // Find if the last value of the DLL is the minimum.
   if(tempD->next == nullptr){
      if(tempD->key < minNodeD->key){
         minNodeD = tempD;
      }
   }

   // Find the minimum of the SLL
   while(tempS->next != nullptr){
      if(tempS->key < minNodeS->key){
         minNodeS = tempS;
      }
      tempS = tempS->next;
   }
   // Find if the last value of the SLL is the minimum
   if(tempS->next == nullptr){
      if(tempS->key < minNodeS->key){
         minNodeS = tempS;
      }
   }

   // Add node after minimum value in tree
   if(minNodeD->key < minNodeS->key){ // If DLL is smaller
      insertDLLNode(minNodeD->key, value);
   } else if(minNodeS->key < minNodeD->key){
      insertSLLNode(minNodeS->key, value);
   } else {
      cout<<"There is no minimum node"<<endl;
   }
}

int main()
{
   LinkedList *ll = new LinkedList();
   //Test cases
   //Test case 1
   //SLL = 1-2-3-4, and DLL = 10-20-30-40, add node with 5
   //output 1-5-2-3-4 for SLL, DLL unchanged

   //Test case 2
   //DLL = 1-2-3-4, and SLL = 10-20-30-40, add node with 5
   //output 1-5-2-3-4 for DLL, DLL unchanged

   //Test case 3
   //SLL = 4-3-2-15, and DLL = 5-6-3-20, add node with 10
   //output 4-3-2-10-15 for SLL, and DLL unchanged

   //Test case 4
   //DLL = 4-3-2-15, and SLL = 5-6-3-20, add node with 10
   //output 4-3-2-10-15 for DLL, and SLL unchanged

   //Test case 5
   //SLL = 4-3-2-1, and DLL = 12-13-14-15, add node with 20
   //output 4-3-2-1-20 for SLL, and DLL unchanged
   
   //Example of how to build test cases.
   //Test case code to build the SLL and DLL
   //Test case #1
   for(int i=1;i < 5;i++){
      ll->insertSLLNode(i-1,i);
   }
   ll->printSLLList();
   
   for(int i=10; i < 50; i+=10){
      ll->insertDLLNode(i-10,i);
   }
   ll->printDLLList();
   
   cout << endl;

   //Test case 3
   ll->insertSLLNode(0, 4);
   ll->insertSLLNode(4, 3);
   ll->insertSLLNode(3, 2);
   ll->insertSLLNode(2, 15);

   ll->insertDLLNode(0, 5);
   ll->insertDLLNode(5, 6);
   ll->insertDLLNode(6, 3);
   ll->insertDLLNode(3, 20);
   
   ll->findMinAndAddAfter(99);

   ll->printSLLList();
   ll->printDLLList();

   

   
  
 
   return 0;
}