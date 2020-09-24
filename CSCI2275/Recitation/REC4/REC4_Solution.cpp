#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;


int main(int argc, char* argv[]){
    ifstream inFile(argv[1]); //open the file
    string line;

    int len = stoi(argv[2]);
    int *nums = new int[len]; //dynamically allocate array of ints
    int index = 0;

    while (getline(inFile,line)){
        //cout << stoi(line) << endl;
        nums[index++] = stoi(line);

        if(index == len){
            //double array
            //1. create a temp array of size len * 2
            len = len * 2;
            int *temp = new int[len];
            //2. copy ints from original to temp
            for(int i=0;i<(len/2);i++){
                temp[i] = nums[i];
            }
            //3. delete array at original
            delete [] nums;
            //4. point original towards temp
            nums = temp;
        }
    }
    inFile.close();
    //print nums
    for(int i=0;i<index;i++){
        cout << nums[i] << endl;
    }
}