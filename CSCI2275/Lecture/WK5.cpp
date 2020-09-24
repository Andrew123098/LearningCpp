#include <iostream>

using namespace std;

int main (){

    //delete command, what does it mean to delete?
    //delete actually means to free up the memory for other uses
    int *p = new int[5];//creates a pointer p, that points to memory location and memory alloted for 5 integers
    delete []p; //free the memory that p points to. Variable p still exists
    p = new int[10]; //point p to something else, other memory now associated with p.
    int *p2 = new int[2]; //memory for 2 integers
    p2[0]=1; //assign some values
    p2[1]=2;
    // TODO: copy data into a new dynamically allocted array and then delete the p2 array
    // Order: create new array, copy data, dlete the old array.
    int *p3 = new int[3];
    p3[0]=p2[0];
    p3[1]=p2[1];
    delete []p2;
    //p2=nullptr; //No memory associated with that pointer (points to nothing)
    //p2[0]=2 //Will result in an error because no memory is allocated (pointed to) b/c p2 is a nullptr
    
    //common errors:
    int *p4=new int[2];
    int *p5=new int[2];
    //goal: copy p4 into p5 and delte p4
    delete []p4; //p4 memory becomes unreliable after this line
    p5[0] = p4[0]; //Unreliable memory
    // Deleting first and then copying is the incorrect order

    // MEMORY LEAK
    int *p6=new int[2]; //allocate memory that is accessed through p6
    p6 = p5; //Change what p6 points to (I have now lost access to the memory that was created on the previous line)
    delete []p6; //frees the memory associated with p5, not the memory from line 

    int *p7 = new int;
    delete p7;

    //shifting - want to statrt from the end of the array and move towards the beginning
    int a[5] = {1, 2, 4, 5, 6}; //array of 5 elements
    int index = 2;
    for(int i = 4; i >= index; i--){
        a[i+1] = a[i]; //first shift is a[4]=a[3], shifts the 5, second shift is a[3] = a[2]
    }
    //end of for loop a = {1, 2, 4, 4, 5}
}