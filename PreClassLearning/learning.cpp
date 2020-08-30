// Comment
/*
 * Multiline comment
 */

#include <iostream> // Allows us to use cout and a bunch of othe rimportant things
#include <vector>   // used for vectors
#include <string>   // use for Strings
#include <fstream>  // used for file input/output

using namespace std; // No longer have to use std::cout, just cout

// Functions in C++ (appear BEFORE MAIN)
int addNumbers(int firstNum, int secondNum = 0) {
    int combinedValue = firstNum + secondNum;
    return combinedValue;
}

// Recursive Function (calls itself inside of itself)
int getFactorial(int number){
    int sum;
    if(number == 1) sum = 1;
    else sum = getFactorial(number - 1) * number;
    return sum;
}

//Fucntiosn can have the same names if they have differnt arguments
int addNumbers(int firstNum, int secondNum, int thirdNum) {
    int combinedValue = firstNum + secondNum + thirdNum;
    return combinedValue;
}


//Pointers with functions
void makeMeYoung(int *age){
    cout <<"I used to be " << *age << endl;
    *age = 21;
}

void actYourAge(int& age) {
    age = 39;
}


//CLASSES
    
    class Animal{

        private: // Only can be changed by functions inside my class (called encapsulation)
            int height;
            int weight;
            string name;
            
            static int numOfAnimals; //Static type variables value is shared by all objects of type animal that is created
        
        public: // Fucntions (methods) that can access the private values
            int getHeight(){ return height; }
            int getWeight(){ return weight; }
            string getName(){ return name; }
            void setHeight(int cm){ height = cm; }
            void setWeight(int kg){ weight = kg; }
            void setName(string animalName){ name = animalName; }

            void setAll( int, int, string);

            //Constructor
            Animal(int, int, string);

            //Destructor
            ~Animal();

            //Overloaded Constructor
            Animal();

            static int getNumOfAnimals() { return numOfAnimals; }

            void toString(); //prints out all information we have on the animals
    };

    int Animal::numOfAnimals = 0;
    void Animal::setAll(int height, int weight, string name){
        this -> height = height;
        this -> weight = weight;
        this -> name = name;
        Animal::numOfAnimals++;
    }
    //Constructor
    Animal::Animal(int height, int weight, string name){
        this -> height = height;
        this -> weight = weight;
        this -> name = name;
        Animal::numOfAnimals++;
    }

    //Deconstructor
    Animal::~Animal(){
        cout << "Animal " << this -> name << " destroyed" << endl;
    }

    //Overloaded constructor
    Animal::Animal(){
        Animal::numOfAnimals++;
    }

    // Declare toString
    void Animal::toString(){
        cout << this-> name << " is" <<< this -> height << " cms tall and " << this -> weight << " kgs in weight" << endl;
    }

    //INHERITANCE
    class Dog : public Animal{
        private:
            string sound = "Woof";

        public:
            void getSound(){ cout << sound << endl; }

        Dog(int, int, string);

        Dog() : Animal(){};

        void toString();
        
    };

    Dog::Dogint height, int weight, string name, string bark) : Animal(height, weight, name){
        this -> sound = bark;
    }

    void Dog::toString(){
        cout<< this -> getName() << " is" << this -> getHeight() << " cms tall and " << this -> getWeight() << "kgs in wieght and says " << this -> sound << endl;
    }

// All code is held in main function
int main() {

    //std::cout // 
    cout << "Hello World" << endl;

    const double PI = 3.1415926535;
    char myGrade = 'A';
    bool isHappy = true;
    int myAge = 39;
    float favNum = 3.14159;
    double otherFaveNum = 1.6180339877;

    cout << "Favorite Number " << favNum << endl;

    cout << "Size of int: " << sizeof(myAge) << " bytes" << endl;

    cout << "4 / 5 = " << (float) 4/5 << endl;


    int age = 70;
    int ageAtLastExam = 16;
    bool isNotIntoxicated = true;

    if((age >= 1) && (age <= 16)){
        cout << "You cannot drive!" << endl;
    } else if (! isNotIntoxicated) {
        cout << "You cannot drive!" << endl;
    } else if ((age >= 80) && ((age > 100) || ((age - ageAtLastExam) > 5))){
        cout << "You cannot drive!" << endl;
    } else {
        cout << "You can drive!" << endl;
    }


    int greetingOption = 2;

    switch(greetingOption){
        case 1:
            cout << "bonjour" << endl;
            break;
        case 2:
            cout << "Hola" << endl;
            break;
        case 3:
            cout << "Hallo" << endl;
            break;
        default:
            cout << "Hello" << endl;
    }


    // Ternary operators

    // variable = (condition) ? true : false

    int largestNumber = (5>2) ? 5 : 2; // If true, stores 5, if false, stores 2

    int myFavNums[5];

    int badNums[5] = {4, 13, 14, 24, 34};

    cout << "Bad Number 1: " << badNums[0] << endl;

    char myName[2][6] = {{'A', 'n', 'd', 'r', 'e', 'w'},
                        {'B', 'r', 'o', 'w', 'n', ' '}};

    cout << "2nd letter in 2nd array: " << myName[1][1] << endl;


    for(int i =1; i <= 10; i++){

        cout << i << endl;
    }

    for(int j = 0; j < 6; j++){
        for(int k = 0; k < 6; k++){
            cout << myName[j][k];
        }
    cout << endl;
    }


    int randNum = (rand() % 100) + 1;
    while(randNum != 100){
    cout << randNum << ", ";
    randNum = (rand() % 100) + 1;
    }
    cout << endl;
    
    // do while loops are loops used when you want to gurantee the loop runs at least one time (it checks condition at the end)

    string numberGuessed;
    int intNumberGuessed;
    do {
        cout << "Guess between 1 and 10: ";

        getline(cin, numberGuessed);

        intNumberGuessed = stoi(numberGuessed);

        cout << intNumberGuessed << endl;
    
    } while(intNumberGuessed != 4);

    cout << "You Win" << endl;

    char happyArray[6] = {'H', 'a', 'p', 'p', 'y', '\0'}; //how strings are made in C
    string birthdayString = " Birthday"; // How strings are made in C++

    cout << happyArray + birthdayString << endl; //how to concantenate

    double eulersConstant = 0.57721;
    string eulerGuess;
    double eulerGuessDouble;

    cout << "What is Euler's Constant? ";
    getline(cin, eulerGuess);

    eulerGuessDouble = stod(eulerGuess);

    if(eulerGuessDouble = eulersConstant){
        cout << "You are right!" << endl;
    } else {
        cout << "You are wrong!" << endl;
    }
    
    cout << "Size of String: " << eulerGuess.size() << endl;
    cout << "Is string empty? " << eulerGuess.empty() << endl;
    cout << eulerGuess.append(" was your guess") << endl;

    string dogString = "dog";
    string catString = "cat";

    cout << dogString.compare(catString) << endl;
    cout << dogString.compare(dogString) << endl;
    cout << catString.compare(dogString) << endl;

    string yourName;
    cout << "What is your name? ";
    getline(cin, yourName);

    cout << "hello " << yourName << endl;

    string wholeName = yourName.assign(yourName);
    cout << wholeName << endl;

    string firstName = wholeName.assign(wholeName, 0, 6);
    cout << firstName << endl;

    int lastNameIndex = yourName.find("Brown", 0);
    cout << "Index for last name " << lastNameIndex << endl;

    yourName.insert(6, " Michael");
    cout << yourName << endl;
   
    yourName.erase(6,7);
    cout << yourName << endl;

    yourName.replace(6, 5, "Maximus");
    cout << yourName << endl;

    //A vector is the same as an array except its size can change 

    vector <int> lotteryNumVect(10);  //Vector named lotteryNumVect stores integers. Initially stores only 10 integers

    int lotteryNumArray[5] = {4, 13, 14, 24, 34};

    lotteryNumVect.insert(lotteryNumVect.begin(), lotteryNumArray, lotteryNumArray+3);

    lotteryNumVect.insert(lotteryNumVect.begin()+5, 44);

    cout << lotteryNumVect.at(5) << endl;

    lotteryNumVect.push_back(64);

    cout << "Final Value: " lotteryNumVect.back() << endl;

    lotteryNumVect.pop_back();

    cout << "Final Value: " lotteryNumVect.back() << endl;
    
    cout << "First Value: " lotteryNumVect.front() << endl;
    
    cout << "Size of Vector: " lotteryNumVect.size() << endl;

    cout << "Is vector empty? " lotteryNumVect.empty() << endl;


    // Functions

    cout << addNumbers(1) << endl;

    cout << addNumbers(1,5,6) << endl;

    cout << "The factorial of 3 is " << getFactorial(3) << endl;


    // File input/output

    string steveQuote = "A day without sunshine is like, you know, night";

    ofstream writer("stevequote.txt")
    if(! writer){
        cout << "Error opening file" << endl;
        return -1;
    } else {
        writer << steveQuote << endl;
        writer.close();
    }

    // ios::app    : Open a stream to appened whats there
    // ios::binary : Treat a file as binary
    // ios::in     : Open a file to read input
    // ios::out    : Open a file to write output
    // ios::trunc  : Default


    ofstream writer2("stevequote.txt", ios::app)

    if(! writer2){
        cout << "Error opening file" << endl;
        return -1;
    } else {
        writer2 << "\n -Steve Martin" << endl;
        writer2.close();
    }

    char letter;

    ifstream reader("stevequote.txt");
     if(! reader){
        cout << "Error opening file" << endl;
        return -1;
    } else {
        for(int i = 0; ! reader.eof(); i++){
            reader.get(letter);
            cout << letter;
        }
    }

    // Error handling

    try{
        if(number != 0){
            cout << 2/number << endl;
        } else throw(number);
    }
    catch(int number){ 
        cout << number << " is not valid" << endl;
    }

    // Pointers

    int myAge = 39;
    int myGrade = 'A';

    cout << "Size of int: " << sizeof(myAge) << endl;
    cout << "Size of char: " << sizeof(myGrade) << endl;

    cout << "myAge is located at " << &myAge << endl;

    int *agePtr = &myAge;

    cout << "Address of pointer: " << agePtr << endl;
    cout << "Data at memory address: " << *agePtr << endl;

    int badNums[5] = {4, 13, 14, 24, 34};
    int *numArrayPtr = badNums;

    cout << "Address: " << numArrrayPtr << " Value: " << *numArrayPtr << endl;

    cout << "Address: " << badNums << " Value: " << *badNums << endl;

    makeMeYoung(&myAge);

    cout << "I'm " << myAge << " years old now" << endl;


    int& ageRef = myAge;

    cout << "myAge : " << myAge << endl;

    ageRef++;
    
    cout << "myAge : " << myAge << endl;

    actYourAge(ageRef);

    cout << "myAge : " << myAge << endl;

    // Passing by reference vs passing by pointer:
    // Use pointers if you donnt want to have to initialize at declaration
    // With a pointer you can change what you are pointing at where as with references you cannot


    //CLASSES
     Animal fred;

     fred.setHeight(33);
     fred.setWeight(10);
     fred.setName("Fred");

     cout << fred.getName() << " is" << fred.getHeight() << " cms tall and " << fred.getWeight() << " kgs in weight" << endl;

     Animal tom(36, 15, "Tom");
     cout << tom.getName() << " is" << tom.getHeight() << " cms tall and " << tom.getWeight() << " kgs in weight" << endl;
    
     Dog spot(38, 16, "Spot", "Woof");

     cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;

     spot.getSound();
     
     tom.toString();
     spot.toString();
     
     spot.Animal::toString();

    return 0;

}