#include<sstream>
#include"MessageBoard.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream> //add to base code for students

using namespace std;

// Function to read in the file and populate the items array, return the number of items in the array
void MessageBoard::readFile(string filename)
{
    //TO DO
	// Cycle through each line of the file
    // create an item and call checkForMatch for each line as it is read from file

    string data;           // String will hold all the data read in from the file.

    ifstream inFile;       // Create a file stream for reading.
    inFile.open(filename); // Open the txt file for reading.

    if (inFile.is_open()){                   // Error Check.
        while(getline(inFile, data)){        // Run until out of data.
            stringstream ss(data);           // Make stringstream for file data.
            string ttype, tprice, tfor_sale; // Initialize temporary variables.
            getline(ss, ttype, ',' );        // Read the type of item into temporary variable.
            getline(ss, tfor_sale, ',');     // Read the status of item into temporary variable.
            getline(ss, tprice);             // Read the price of item into temporary variable.

            item temp;                   // Create temporary item struct to store line data and pass to cFM function
            temp.type = ttype;           // Store type
            temp.price = stoi(tprice);   // Store price 
            if(tfor_sale == "wanted") {  // If item is wanted, then status is 1.
                temp.for_sale = 1;       // Store status as 1.
            } else {                     // If item is for sale, then status is 0.
                temp.for_sale = 0;       // Store status as 0.
            }

            checkForMatch(temp);         // Check if current item matches a item on the message board.

        }
    } else { // If the file could not be opened for any reason...
        cout<<"Error: Could not open File"<<endl;
    }
}

void MessageBoard::checkForMatch(item it){
    //TO DO
    //determines if item passed in matches any item already in the items vector
    //if so, remove match from vector.
    //if no match is found, add item to the end of the vector
  
    bool addItemIndicator = 0;                     // If a match is found, indicates not to add the item to the vector os structs.
    for(int i = 0 ; i < items.size() ; i++){       // Loop through every struct in the vector.
        if(it.type == items[i].type){              // If the types are the same ...
            if(it.for_sale != items[i].for_sale){  // And if there is a want and a need for the item ... 
                                                   /* And if the person who wants the item is willing to pay equal to or more than
                                                    * the asked price, OR the person who is selling the item is willing to sell equal
                                                    * to or less than the buyer is willing to pay... */
                if((it.for_sale == 1 && it.price >= items[i].price) || (it.for_sale == 0 && it.price <= items[i].price)){
                    items.erase(items.begin()+i);  // Then erase the item from the vector.
                    addItemIndicator = 1;          // Indicate not to add the current item to the vector.
                    printItemsSold(it);            // Print the sold item.
                    break;                         // Break out of the for loop so we only match with one person.
                }
            }
        }
    }

    if(addItemIndicator == 0) { // If we could not find a match ...
        items.push_back(it);    // Add the item to the vector of items.   
    }
}

void MessageBoard::printItemsSold(item it){
    //TO DO
    //print type and price of item matched
    cout<<"SOLD: "<<it.type<<" FOR "<<it.price<<endl;


}
void MessageBoard::printItemsRemaining(){
    //TO DO
    //print all contents in items vector
    for(int i = 0 ; i < items.size() ; i++){
        cout<<items[i].type<<", ";
        if(items[i].for_sale == 1){
            cout<<"wanted, ";
            } else {
                cout<<"for sale, ";
            }
        cout<<items[i].price<<endl;
    }
}
void MessageBoard::postItemToMessageBoard(string itemType, int price, int forSale){
    //TO DO
    //create an item and pass it to checkForMatch to determine if there is a match 
    item newItem; 
    newItem.type = itemType;
    newItem.price = price;
    newItem.for_sale = forSale;
    MessageBoard::checkForMatch(newItem);
}


