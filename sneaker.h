//
// Created by Sean Grady on 4/5/2021.
//

#ifndef PROGRAM4_SNEAKER_H
#define PROGRAM4_SNEAKER_H


#include "bids.h"

class sneaker {
private:
    //holds all different shoes
    vector<bids> Sneakers;

public:
    //constructor
    sneaker();
    //used to print the shoes
    int printBids(string);
    //displays all the ids and shoes
    void displayAllIDS();
    //compares the entered shoes to the entire shoe list
    bool compareShoeList(string);
    //converts strings to uppercase
    static string toUpperCase(string);
};


#endif //PROGRAM4_SNEAKER_H
