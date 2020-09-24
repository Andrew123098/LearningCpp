#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


// struct to store word+count combinations
struct wordItem
{
    std::string word;
    int count;    
};

class TextAnalyzer{
    private:
        wordItem *words;
        wordItem *ignoreWords;
        int numIgnoreWords = 50;
        int numDoublings = 0; // stores the times we double the array
        int numUniqueWords = 0;// stores the total number of unique words in the document, not counting stop words
        int arrLoc = 0;         // stores the location of the last element in the arr
        int arrCapacity = 100;   // stores the initial capacity of the array

        void buildStopWordsArray(std::string ignoreWordsFileName, int numIgnoreWords){ //read file and populate stopWords array
            //ignoreWords = new wordItem[numIgnoreWords]; //Allocate memory for ignored words in struct.

            // Initialize and open file for reading.
            std::string data;                 // String to hold data temporarily.
            std::ifstream inFile;             // Create stream for file reading.
            inFile.open(ignoreWordsFileName); // Open file in file stream.
            
            // If the file opens, read its contents to an array.
            if (inFile.is_open()){                         // Error check.
                int i = 0;                                 // Counting variable.
                while(std::getline(inFile, data)){         // Run until out of lines.
                    std::stringstream ss(data);            // Make stringstream for file data.
                    std::getline(ss, ignoreWords[i].word); // Add words to array.
                    i++;                                   // Increment.
                }
            }
        }

        bool isIgnoreWord(std::string word){ //read stopWords array and return true if word is in array, false otherwise
            for(int i = 0; i < numIgnoreWords; i++){
                if(word == ignoreWords[i].word){
                    return true;
                }
            }
            return false;
        }

        void insertAt(std::string word, int index){ //call in the insert method to add a word at specified index and shift rest of array
            // Double array size if need be.
            if(index >= arrCapacity){                       // If index is greater than or equal to the number of avaailable indexes...
                arrCapacity*=2;                             // Double the array capacity variable.
                numDoublings++;                             // Increment numDoublings.
                wordItem *temp = new wordItem[arrCapacity]; // Create new array twice the size of previous array.
                for(int i = 0; i < arrCapacity/2; i++){     // Copy array contents to temporary array.
                    temp[i].word = words[i].word;
                    temp[i].count = words[i].count;
                }
                delete []words;                             // Delete array at original memory address.
                words = temp;                               // Assign words pointer to new memory address.
            }

            // Insert new word into array and shift array.
            wordItem *temp = new wordItem[arrCapacity];     // Create temporary array
            for(int i = arrCapacity-1; i > index; i--){     // Loop through array contents starting at the end until index for insertion.
                    words[i].word = words[i-1].word;        // Shift all values up the array.
                    words[i].count = words[i-1].count;
                }
            words[index].word = word;                       // Set given word index to new word.
            words[index].count = 1;                         // Set count variable to 1.
            numUniqueWords++;                               // Increment the number of unique words.
        }

    public:
        TextAnalyzer(){}; 
        //in constructor, allocate memory for ignoreWords and words arrays and populate ignoreWords
        TextAnalyzer(std::string ignoreWordsFile, int numIgnoreWords){
            words = new wordItem[arrCapacity];           // Allocate memory for words struct.
            ignoreWords = new wordItem[numIgnoreWords];  // Allocate memory for ignoreWords struct.
            buildStopWordsArray(ignoreWordsFile, numIgnoreWords); // Populate ignoreWords array.
        }
        bool insertWord(std::string word){ //add word to words array in alphabetical order. Returns true
        //if word inserted or count increased and false if the word is a stop word
            int index = 0;                             // Index where to insert the new word.
            if(!isIgnoreWord(word)){                   // If the word is not ignored...
                for(int i = 0; i < arrCapacity; i++){  // Loop through all values of word struct until...
                    if(word == this->words[i].word){   // If word is not new...
                        this->words[i].count++;        // Increase the word count...
                        return true;                   // And return true.
                    }
                }                                      // Otherwise ...
                while(word > this->words[index].word){ // Find index of where to add the word (sort in alphabetical order).
                    index++;                           
                }
                insertAt(word, index);                 // Insert new word at the needed index.
                return true; 
            } else {
                return false;
            }
        }

        void sortByWordCount(){ // Sorts the array by count instead of alphabetically.
            wordItem temp;                                          // Create temporary wordItem.
            for(int i = 0; i < arrCapacity; i++){                   // Loop throuhg all values in words array.
                if(this->words[i].count < this->words[i+1].count){  // If next value is greater than current value ...
                    temp = this->words[i];                          // Swap the structs.
                    this->words[i] = this->words[i+1];
                    this->words[i+1] = temp;
                }
            }
        }
        void printTopN(int topN){ // Prints the number most used words specified by the input.
            for(int i = 0; i < topN; i++){
                std::cout<<this->words[i].count<<" - "<<this->words[i].word<<std::endl;
            }
        }
        
        int getNumberOfUniqueWords(){
            return numUniqueWords;
        }
        int getNumDoublings(){
            return numDoublings;
        }

        int getTotalNonCommonWords(){ //output the sum of counts for each non-common word
            int countTotal = 0;
            for(int i = 0; i < arrCapacity; i++){
                countTotal = countTotal + this->words[i].count;
            }
            return countTotal;
        }


};