//
//  Assignment4.h
//  Assignment4
//
//

#ifndef TRAIN_H
#define TRAIN_H

#include <iostream>

struct trainCar{
    std::string name;
    int capacity;
    int occupancy;
    trainCar *next;
    trainCar *previous;
    trainCar(){}; // default constructor
    
    trainCar(std::string initName, int cap, int occup, trainCar *initNext, trainCar *initPrevious)
    {
        name = initName;
        capacity = cap;
        occupancy = occup;
        next = initNext;
        previous = initPrevious;
    }

};
class Train
{
public:
    Train();
    void buildTrain(std::string names[], int caps[], int trainSize);
    void printTrain();
    void addPassengers(std::string name, int numPassengers);
protected:
private:
    trainCar *engine;//head of the linked list
    trainCar *caboose;//tail of the linked list
    void addCar(std::string n, int c, int o, trainCar *p);
};

#endif // TRAIN_H


