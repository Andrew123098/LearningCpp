/* Assume I'm given 10 lists of people (Every list has names) and each list has 1 million rows.
 * Some people are on multiple lists.
 * We want one list of unique names.
 * Do this as efficiently as possible.
 */

// Set() will take in a data structure and return its unique elements.
// But how does this work?

# include <iostream>

using namespace std;

int main(){
    int nums[10] = {278, 279, 300, 278, 200, 187, 300, 301, 301, 280};
    //First thing to do is sort. (Bubble sort) -- simple but not super efficient
    int n = 10; 
    for (int x = 0 ; x < n-1 ; x++){
        for (int y = 0 ; y < n - x - 1 ; y++){
            if(nums[y] > nums[y+1]) {
                int tmp = nums[y+1];
                nums[y+1] = nums[y];
                nums[y] = tmp;
            }
        }
    }
    for(int x = 0 ; x < n ; x++){
        if(x == 0){
            cout<<nums[x]<<endl;
        } else {
            if( nums[x] != nums[x-1]){
                cout<<nums[x]<<endl;
            }
        }
        cout<<nums[x]<<endl;
    }

    //Our array is now sorted, but how do we now find the unique values?
    //What's next?
    // compare value nums[x] to numms[x+1], output if different.
    // Option 1: use nums[x] and nums[x-1], and start looping at x=1
    // Option 2: x=0 treated as special case and kept in the solution.


    // CONCLUSION: ALWAYS SORT YOUR DATA BEFORE TRYING TO GLEAN ANYTHING FROM IT. 
    // IT IS EASIER TO GET DATA FROM SORTED DATA.

    return 0;










}