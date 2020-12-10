/* Implement a C++ function to find all misplaced items in a hash table built using chaining and display their key values.
For example, if the movie "Se7en" has hashsum of 0 and it is misplaced at index 9, then the method you write should display "Se7en"
The hash table is build using the HashTable class definition shown here. Create a method called printMisplacedMovies. 
A method to calculate the hash value is provided for you, called hashSum. 
You can assume that tableSize and the hash table array are already created.
You can use the method printTableContents for debug purposes if you want to see all elements stored in the hash table. */

#include <iostream>
#include <stdlib.h>
#include <string>

struct Movie{
	std::string title; 
	Movie *next;
	Movie(){};
	Movie(std::string in_title)
	{
		title = in_title;
		next = NULL;
	}
	
};

class HashTable
{
	public:
		HashTable();
		~HashTable();
		void insertMovie(std::string name);
        void printTableContents();
		void printMisplacedMovies();
	private:
		int hashSum(std::string x, int tableSize);
		int tableSize;
		Movie * hashTable[10];

};

void HashTable::printMisplacedMovies(){
    int index = 0;
    int properIndex;
    Movie* crawler = hashTable[0];

    while(index != 10){
        while(crawler != NULL){
            properIndex = hashSum(crawler->title,10);
            if(properIndex != index){
                std::cout<<crawler->title<<std::endl;
            }
            crawler = crawler->next;
        }
        index++;
        crawler = hashTable[index];
    }
}