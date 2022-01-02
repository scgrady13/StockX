//
// Created by Sean Grady on 4/5/2021.
//

#ifndef PROGRAM4_BIDS_H
#define PROGRAM4_BIDS_H
#include <string>
#include <vector>

using namespace std;

class bids {
private:
    //variables for a shoe in the bid class
    string shoeID, shoeName;
    double minBid;
    vector<double> bidsOnShoe;
    vector<int> bidderID;

public:
    //constructor
    bids();
    //imports shoe data
    void setShoeData(string, string, double);
    //reads file for bids on shoe
    void inputBids(string, string);
    //prints data on each shoe
    void printShoe();
    //sorts the bids in highest bid order
    void sortBids();
    //prints out shoe basic info

    //getters/setters used for giving information to the Sneaker class
    string getID();
    string getName();
    int getAmountOfBids();
    double getMinBid();

};


#endif //PROGRAM4_BIDS_H
