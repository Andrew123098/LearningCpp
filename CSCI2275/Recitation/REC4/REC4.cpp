#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;




int main(int argc, char** argv){
    string filename = argv[1];   // Read command line argument into variable.
    int len = stoi(argv[2]);           // Read initial array length.

    int *p = new int[len];       //

    string data;

    ifstream infile;
    infile.open(filename);
    if(infile.is_open()){
        stringstream ss(data);
        
        int i = 0;
        while(getline(infile, data)){
            //doubleArraySize(i, len, p);
            if (i > len){
                len = len*2;
                int *temp = new int[len];
                for(int j = 0 ; j < i ; j++){
                     temp[j] = p[j];
                }
                delete [] p;
                p = temp;
            }
            p[i] = stoi(data);
            i++;
        }
    }



    return 0;
}
