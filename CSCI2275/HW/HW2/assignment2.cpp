/*input
garageSale.txt
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include "MessageBoard.h"

using namespace std;


// Main function run
int main(int argc, char *argv[])
{
	MessageBoard mb;
	string filename = argv[1];
    // TO DO
    // Get input from the user for the filename and process all items here
    // After file processed, print menu and wait for user input
	
	std::string dmenu = "======Main Menu=====\n"
					"1. Post item for sale\n"
					"2. Post item wanted\n"
                    "3. Print message board\n"
					"4. Quit";
    
    int choice;
    bool exit = false;
    
    cout << dmenu << endl;
    
    while(cin >> choice) {
        
        // flush the newlines and other characters
        cin.clear();
        cin.ignore();
        
        switch (choice) {
            case 1:
            {
				//get info for item for sale
                //call mb.PostItemToMessageBoard
                break;
            }
            
            case 2:
            {
				//get info for item wanted
                //call mb.PostItemToMessageBoard
                break;
            }
            case 3:
            {
                //print items in message board
                break;
            }
                
            case 4:
            {
                exit = true;
                break;
            }
        }
        
        if (exit) {
            break;
        }
        
        cout << dmenu << endl;
    }


	return 0;
}

