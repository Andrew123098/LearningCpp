/* Implement a C++ function to build a new hash table from an existing hash table using a new hash function called hashSum2.  
In the new hash table, insert the movies at the front of the linked list when the movies hash to the same index.

Note: In the background, we handle building/inserting into the hash table by the hash function from your book. 
We also write the hashSum2 and you only will need to call it. You will need to use the newHashTable variable. 

void HashTable::createNewHashTable();   // You need to implement this function

int hashSum2(std::string x, int s);     // already defined. You will need to call this function in createNewHashTable()  */

#include <iostream>
#include <stdlib.h>
#include <string>

struct Movie{
	std::string title; 
	Movie *next;
	Movie(){};
	Movie(std::string in_title){
		title = in_title;
		next = NULL;
	}
};

class HashTable
{
	public:
		HashTable();
		~HashTable();
        void createNewHashTable();
	private:
		int hashSum(std::string x, int tablesize);
	      int hashSum2(std::string x, int s);
		int tableSize;
		Movie * hashTable[10];
	      Movie * newHashTable[10];
};
// Returns hashSum2 of input string x by summing every other letter in string
int HashTable::hashSum2(std::string inputString, int hashLen)
{
    int sum = 0;
    for (int i = 0; i < inputString.length(); i++){
	if(i%2==0)
	    sum = sum + inputString[i];
    }
    sum = sum % hashLen;
    return sum;
}

void HashTable::createNewHashTable(){
    int oldIndex = 0;
    int newIndex;
    Movie* crawler = hashTable[0];
    Movie* tmp;

    while(oldIndex != 10){
        while(crawler != NULL){                                  // Crawl through old hash table chains.
            newIndex = hashSum2(crawler->title, 10);             // Find new index using new hash.
            if(newHashTable[newIndex] != NULL){                  // If collision in new hash table ...
                tmp = newHashTable[newIndex];                    // Store old head in tmp pointer.
                Movie* newMovie = new Movie(crawler->title);     // Allocate memory for new movie
                newHashTable[newIndex] = newMovie;               // Add new head to new hash table
                newMovie->next = tmp;                            // Make old head the next value of the new head.
            } else {                                             // If no collision ...
                Movie* newMovie = new Movie(crawler->title);     // Allocate memory for new movie
                newHashTable[newIndex] = newMovie;               // Add new movie to the hash table.
            }
            crawler = crawler->next;                             
        }
        oldIndex++;
        crawler = hashTable[oldIndex];
    }
}

