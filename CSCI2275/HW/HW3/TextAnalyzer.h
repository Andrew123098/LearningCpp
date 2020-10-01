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
        int numWordsIgnored = 0;
        int numDoublings = 0; // stores the times we double the array
        int numUniqueWords = 0;// stores the total number of unique words in the document, not counting stop words
        int arrLoc = 0;         // stores the location of the last element in the arr
        int arrCapacity = 100;   // stores the initial capacity of the array

        void buildStopWordsArray(std::string ignoreWordsFileName, int numIgnoreWords){ //read file and populate stopWords array            
            // Initialize and open file for reading.
            std::string data;                 // String to hold data temporarily.
            std::ifstream inFile;             // Create stream for file reading.
            inFile.open(ignoreWordsFileName); // Open file in file stream.
            // If the file opens, read its contents to an array.
            if (inFile.is_open()){                         // Error check.
                int i = 0;                                 // Counting variable.
                while(std::getline(inFile, data)){         // Run until out of lines.
                    std::stringstream ss(data);            // Make stringstream for file data.
                    std::getline(ss, ignoreWords[i].word, '\n'); // Add words to array.
                    ignoreWords[i].count = 0;
                    i++;                                   // Increment.
                }
            }
        }

        bool isIgnoreWord(std::string word){ //read stopWords array and return true if word is in array, false otherwise
            for(int i = 0; i < numIgnoreWords; i++){
                if(word == ignoreWords[i].word){
                    numWordsIgnored++;
                    return true;
                }
            }
            return false;
        }

        void insertAt(std::string word, int index){ //call in the insert method to add a word at specified index and shift rest of array
            // Double array size if need be.
            if(numUniqueWords >= arrCapacity){              // If index is greater than or equal to the number of available indexes...
                //arrCapacity*=2;                             // Double the array capacity variable.
                numDoublings++;                             // Increment numDoublings.
                std::cout<<"Doublings: "<<numDoublings<<std::endl;
                wordItem *temp = new wordItem[arrCapacity*2]; // Create new array twice the size of previous array.
                for(int i = 0; i < arrCapacity; i++){     // Copy array contents to temporary array.
                //std::cout<<"Double for loop: "<<i<<std::endl;
                    temp[i].word = words[i].word;
                    temp[i].count = words[i].count;
                }
                //std::cout<<"Out of double for Loop"<<std::endl;
                arrCapacity*=2;                             // Double the array capacity variable.
                delete []words;                             // Delete array at original memory address.
                words = temp;                               // Assign words pointer to new memory address.
            }

            // Insert new word into array and shift array.
            wordItem *temp = new wordItem[arrCapacity];     // Create temporary array
            for(int i = numUniqueWords-1; i > index; i--){  // Copy values until index into temporary array.
                temp[i+1].word = words[i].word;
                temp[i+1].count = words[i].count;
            }
            temp[index].word = word;                        // Copy values of index into temporary array.
            temp[index].count = 1;
            
            for(int i = index - 1; i >= 0; i--){            // Copy values into temporary array until begining of array.
                temp[i].word = words[i].word;
                temp[i].count = words[i].count;
            }
            delete []words;                                 // Delete previous array.
            words = temp;                                   // Point to new array.
            //std::cout<<words[index].word<<std::endl;
            
            
            // for(int i = arrCapacity-1; i > index; i--){     // Loop through array contents starting at the end until index for insertion.
            //     //std::cout<<"Insert For Loop: "<<i<<std::endl;
            //         words[i].word = words[i-1].word;        // Shift all values up the array.
            //         words[i].count = words[i-1].count;
            //     }
            // //std::cout<<"Word Placed at: "<<index<<std::endl;
            // words[index].word = word;                       // Set given word index to new word.
            // words[index].count = 1;                         // Set count variable to 1.
            numUniqueWords++;                               // Increment the number of unique words.
            arrLoc++;
            //std::cout<<numUniqueWords<<std::endl;
        }

    public:
        TextAnalyzer(){}; 
        //in constructor, allocate memory for ignoreWords and words arrays and populate ignoreWords
        TextAnalyzer(std::string ignoreWordsFile){
            words = new wordItem[arrCapacity];                          // Allocate memory for words struct.
            ignoreWords = new wordItem[this->numIgnoreWords];           // Allocate memory for ignoreWords struct.
            buildStopWordsArray(ignoreWordsFile, this->numIgnoreWords); // Populate ignoreWords array.
        }
        
        bool insertWord(std::string word){ //add word to words array in alphabetical order. Returns true
        //if word inserted or count increased and false if the word is a stop word
            if(!isIgnoreWord(word)){                        // If the word is not ignored...
                if(arrLoc == 0){                            // If there is nothing in the array...
                    words[arrLoc].word = word;              // Add word to the array.
                    words[arrLoc].count = 1;                // Set count to 1.
                    arrLoc++;                               // Increase index.
                    numUniqueWords++;                       // Increase number of unique words.
                    return true;
                } else {
                    for(int i = 0; i < arrLoc; i++){        // Loop through all current values of word struct until...
                        //std::cout<<"For Loop: "<<i<<std::endl;
                        if(word == this->words[i].word){    // If word is not new...
                            this->words[i].count++;         // Increase the word count...
                            return true;                    // And return true.
                        }   
                    } 
                    //std::cout<<"Done with for loop"<<std::endl;
                    //arrLoc = 0;                                         // Otherwise ...        
                    int jaredIndex = 0;                  
                    for(int i = 0; i < arrLoc; i++){            // Find index of where to add the word (sort in alphabetical order).
                        if(word < this->words[i].word){
                            jaredIndex = i;
                            break;
                        }
                    }
                    
                    //std::cout<<"Place word at: "<<arrLoc<<std::endl;
                    insertAt(word, jaredIndex);                     // Insert new word at the needed index.
                    //if(arrLoc == 0){arrLoc = 1; }
                    return true;
                } 
            } else {
                return false;
            }
        }

        void sortByWordCount(){ // Sorts the array by count instead of alphabetically.

        // wordItem *temp = new wordItem[numUniqueWords];
        // for(int i = 0; i < numUniqueWords; i++){
        //     temp[i].word = words[i].word;
        //     temp[i].count = words[i].count;
        // }
        // int index = 0;
        // for(int i = 0; i < numUniqueWords; i++){
        //     if(temp[i].word == ' '){
        //     numUniqueWords--;
        //     wordItem *temp2 = new wordItem[numUniqueWords];
        //     }
        //     for(int j = 0; j < i; i++){
        

        //     }
        // }
        


        for(int i = 0; i < numUniqueWords; i++){
                std::cout<<words[i].word<<", ";
                if(i%50 == 0){std::cout<<std::endl; }
            }


            wordItem temp;                                          // Create temporary wordItem.
            std::cout<<arrCapacity<<std::endl;
            std::cout<<numUniqueWords<<std::endl;
            std::cout<<arrLoc<<std::endl;
            for(int i = 0; i < numUniqueWords; i++){                   // Loop throuhg all values in words array.
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
            for(int i = 0; i < numUniqueWords; i++){
                countTotal = countTotal + this->words[i].count;
                //std::cout<<this->words[i].count<<std::endl;
            }
            return countTotal;
            
        }


};