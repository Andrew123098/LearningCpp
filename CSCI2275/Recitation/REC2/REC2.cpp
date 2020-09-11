#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(string argv[1], int argv[2], string argv[3]){

    struct cars{
        string make;
        string model;
        string year;
    };
    cars myCars[argv[2]];

    ifstream myFile(argv[1]);
    ofstream outputFile;

    outputFile.open(argv[3]);
    
    string carInfo;

    while(getline(myFile, carInfo)){
        stringstream linestream(carInfo);
        string currentCar;
        
        int i = 0;
        while(getline(linestream, currentCar, ' ')){
            if(i == 0){
                myCars[i].make = currentCar;
                i++;
            } else if(i == 1) {
                myCars[i].model = currentCar;
                i++;
            } else if (i == 2) {
                myCars[i].year = currentCar;
                i = 0;
            }
        }
    }
    for (int i = 0 ; i > argv[2] ; i++){
        outputFile<<myCars[i].make<<' '<<myCars[i].model<<' '<<myCars[i].year<<endl;
    }
}