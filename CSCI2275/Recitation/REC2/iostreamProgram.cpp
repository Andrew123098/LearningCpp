#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
int main(int argc, char* argv[]) {
    ifstream inFile;
    string data;
    inFile.open(argv[1]); //open the file
    if (inFile.is_open()) {  //error check
   	 cout << "opened successfully" << endl;
   	 while (getline(inFile, data)) {                      	 
   		 //read/get every line of the file and store it
   		 cout << data << endl;
          //can see the data (each line) printed
   		 stringstream ss(data);
          //create a stringstream variable from the string data
   		 int elementOne;
   		 ss >> elementOne;
   		 cout << elementOne << endl;
   		 string elementTwo;
   		 ss >> elementTwo;
   		 cout << elementTwo << endl;
   	 }
   	 inFile.close(); //close the file
    }   
    else {   
   	 cout << "File unsuccessfully opened" << endl;
    }   
    return 0;
}