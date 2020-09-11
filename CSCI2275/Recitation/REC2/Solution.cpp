#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct car{
	string model;
	string make;
	string year;
};

int main(int argc, char* argv[]) {
    ifstream inFile;
	ofstream outputFile; //create ofstream for the output file
    string data;

    inFile.open(argv[1]); //open the file

	car cars[stoi(argv[2])]; //create array of structs from second argument

	outputFile.open(argv[3]); //create output file from third argument

	int index=0;

    if (inFile.is_open()) {  //error check
   		while (getline(inFile, data)) {
   		stringstream ss(data);
   		
		string make, model, year;
		ss >> make;
		ss >> model;
		ss >> year;

		/*
		* Alternate way to read through a string stream.
		* ss >> make will take from ss up until a space and place it in make
		* The same thing is accomplished by getline(ss, make, ' ')
		* However you can change whatever character is in ' ', it will read up until that delimiter and store it in make
		* getline(ss, year) will read up until the end of the line and store it in year. since year is the last text in the line here you don't exactly need a delimiter
		string make, model, year;
		getline(ss, make, ' ');
		getline(ss, model, ' ');
		getline(ss, year);*/

		cars[index].make = make;
		cars[index].model = model;
		cars[index].year = year;
		index++;
   	 }
   	 inFile.close(); //close the file
    }   
    else {   
   		cout << "File unsuccessfully opened" << endl;
    }   

	//cars[] has been populated with all the cars from the txt file
	for(car c : cars){
		outputFile << "I am a " + c.model + " " + c.make + " from " + c.year + "\n";
	}
	outputFile.close();

    return 0;
}