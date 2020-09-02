/* Andrew Brown / 9/1/2020 / HW1 / CSCI 2275 / Dr. Rhonda Hoenigman */

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

// Define person struct
struct person {
        int height;
        int weight;
    };
person circusTower[6] = {{65, 100}, {70, 150}, {56, 90}, {75, 190}, {60, 95}, {68, 110}};

void tower (person people[6]){
    int tallest = 0;
    int heaviest = 0;
    int tempTallest = 0;
    int tempHeaviest = 0;
    int index = 0;
    int count = 0;
    for (int j = 0 ; j < 6 ; j++){                                                      // Increase starting index of for loop i
        for (int i = j ; i < 6 ; i++){                                                  // Find the largest person above index j
            if ( j == 0){                                                               // If it is the first time through the loop ...
                if (people[i].height > tempTallest && people[i].weight > tempHeaviest){ // And if the curent person is taller and heavier than the previous person
                    tempTallest = people[i].height;                                     // Save tallest person.
                    tempHeaviest = people[i].weight;                                    // Save heaviest person.
                    index = i;                                                          // Save largest person index.
                }
            } else if (people[i].height < tallest && people[i].weight < heaviest){      // If the current person is lighter and shorter than the previous person...
                if (people[i].height > tempTallest && people[i].weight > tempHeaviest){ // And the current person is heavier and taller than the rest of the people in the list
                    tempTallest = people[i].height;                                     // Save tallest person.
                    tempHeaviest = people[i].weight;                                    // Save heaviest person.
                    index = i;                                                          // Save largest person index.
                }
            }
        }
        tallest = tempTallest;                      // Save the temporary values.
        heaviest = tempHeaviest;                    // Save the temporary values.

        // Swap largest person with first index in array.
        people[index].height = people[j].height;
        people[index].weight = people[j].weight;
        people[j].height = tallest;
        people[j].weight = heaviest;
        
        // If the person has not been terminated from the tower (aka skinny and tall or fat and short) increase the person count.
        if(tallest != 0 && heaviest != 0){count++; } 

        // Reset temporary values
        tempTallest = 0;
        tempHeaviest = 0;
    }

    // Format and print Max number of people and the people in the right order.
    std::cout<<"Maximum number of people: "<<count<<std::endl;
    for (int i = count-1 ; i >= 0 ; i--) {
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
    return 0;
}