#include <iostream>

void lockers(){
    bool lockerVals[100]; // Holds the values of the locker, 0 = open and 1 = closed
    for(int i = 0 ; i < 100 ; i++){ lockerVals[i] = 1; } //Initialize lockers to closed (clear memory)
    
    for (int i = 0 ; i < 100 ; i++){ // Changes the starting value and the increment value of the locker toggler.
        for (int j = i ; j < 100 ; j = j + i + 1){ // Toggles the lockers.
            if (lockerVals[j] == 0) {
                lockerVals[j] = 1;
                // std::cout<<"Locker # "<<j+1<<" is closed."<<std::endl;
            } else {
                lockerVals[j] = 0;
                // std::cout<<"Locker # "<<j+1<<" is open."<<std::endl;
            }
        }
    }
    
    // Find the number of open lockers.
    int count = 0;
    for (int i = 0 ; i < 100 ; i++){
        if (lockerVals[i] == 0) {
            count++;
        }
    }

    // Find which lockers are open and store their 1-based indexes in an array.
    int openedLockers[count]; // Which lockers are open.
    int counter = 0; //Tempeorary counter variable.
    for (int i = 0 ; i < 100 ; i++){
        if (lockerVals[i] == 0){
            openedLockers[counter] = i+1;
            counter++;
        }
    }
    openedLockers[count] = '\0'; //Define terminating array value.

    // Print out the number of opened lockers and the 1-based indexes of the lockers.
    std::cout<<"The number of open lockers is: "<<count<<std::endl;
    std::cout<<"The open locker indexes are ";
    
    // Loop through array of opened lockers indexes.
    for (int i = 0 ; i < count-1 ; i++){
        std::cout<<openedLockers[i]<<", ";
    }
    std::cout<<"and "<<openedLockers[count-1]<<"."<<std::endl;
}

struct person {
        int height;
        int weight;
    };
person circusTower[6] = {{65, 100}, {70, 150}, {56, 90}, {75, 190}, {60, 95}, {68, 110}};

void tower (person people[6]){
    int tallest = 0;
    int heaviest = 0;
    int index = 0;
    int count = 0;
    for (int j = 0 ; j < 6 ; j++){ // Increase starting index of for loop i
        for (int i = j ; i < 6 ; i++){ // Find the largest person above index j
            if (people[i].height > tallest && people[i].weight > heaviest){
                tallest = people[i].height; // Save tallest person.
                heaviest = people[i].weight; // Save heaviest person.
                int index = i; // Save largest person index.
            }
        }
        // Swap largest person with first index in array.
        people[index].height = people[j].height;
        people[index].weight = people[j].weight;
        people[j].height = tallest;
        people[j].weight = heaviest;
        count++;
    }
    std::cout<<"Maximum number of people: "<<count<<"."<<std::endl;
    for (int i = 0 ; i < count ; i++) {
        std::cout<<"Person "<<i+1<<" -- "<<"Height: "<<people[i].height<< " Weight: "<<people[i].weight<<std::endl;
    }

}



int main(){

    lockers(); /* PART B: All the opened lockers' 1-based indexes are perfect squares.
                * This is because the algorithm used to open and close the lockers toggles every locker by their own factors. 
                * For example, locker number 48 gets toggles on passes 1, 2, 3, 4, 6, 8, 12, 16, 24, and 48 -- which is 10 toggles --
                * open-closed-open-closed-open-closed-open-closed-open-closed. Every locker whose 1-based index has an even number of
                * factors will be closed, while those with an odd number of factors (aka only perfect squares) will end being opened.
                * For example, locker number 36 has 9 factors -- 1, 2, 3, 4, 6, 9, 12, 18, 36.
                */
    
    
    
    tower(circusTower);

    //people[0].height = 65;
    //people[0].weight = 100;
    //people[1].height = 70;
    //people[1].weight = 150;
    //people[2].height = 56;
    //people[2].weight = 90;
    //people[3].height = 75;
    //people[3].weight = 190;
    //people[4].height = 60;
    //people[4].weight = 95;
    //people[5].height = 68;
    //people[5].weight = 110;



    

            
    

    return 0;
}