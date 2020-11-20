#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include "priorityQueueHeap.h"
#include "priorityQueueLL.h"

using namespace std;

int main(int argc, char *argv[]){
    ifstream raw;
    raw.open(argv[1]);

    // throw an error if we couldn't open the file
    if (!raw){
        cout << "Error: Could not open file for reading" << endl;
        return 0;
    }

    pqHP hp;
    pqLL ll;



}