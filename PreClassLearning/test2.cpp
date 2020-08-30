/* Write a function
 * int countSeparation(string s, char c);
 * Which takes in a string and a character to split on and returns the number of tokens separated by that character. 
 * e.g cout<<countSeparation("dog,wolf,cat", ',')
 * would print
 * 3
 * You must use a stringstream. Your function logic should be <= 6 lines of code.
 */

#include <iostream>
#include <sstream>
using namespace std;


int countSeparation(string s, char c){
    stringstream ss.str(s)
    return ss.find(c);

    

}


int main(){

    cout<<countSeparation("dog,wold,cat", ',');

}

