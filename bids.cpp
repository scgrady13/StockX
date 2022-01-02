//
// Created by Sean Grady on 4/5/2021.
//

#include "bids.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

bids :: bids(){
    //used when object initaly created to be pushed into vector of objects
    shoeID = "";
    shoeName = "";
    minBid = 0.0;
}
void bids :: setShoeData(string idin, string namein, double bidin){
    //sets data for each shoe from the Sneakers file being read
    shoeID = idin;
    shoeName = namein;
    minBid = bidin;
}
void bids :: inputBids(string bidderIDs, string bidAmount) {
    bidsOnShoe.push_back(stod(bidAmount));
    bidderID.push_back(stod(bidderIDs));
}
    //reads the bidders file and imports the shoe bids for each shoe
//    ifstream shoeInput;
//    shoeInput.open("Bidders.txt");
//    if (!shoeInput.is_open()) {
//        cout << "File did not open" << endl;
//    }
//    string bidderTemp;
//    string shoeIDTemp;
//    string bidTemp;
//    getline(shoeInput, shoeIDTemp, ',');
//    while(!shoeInput.eof()) {
//        getline(shoeInput, bidderTemp, ',');
//        getline(shoeInput, bidTemp, '\n');
//        if (shoeIDTemp == shoeID){
//            if (stod(bidTemp) >= minBid) {
//                bidsOnShoe.push_back(stod(bidTemp));
//                bidderID.push_back(stod(bidderTemp));
//            }
//        }
//        getline(shoeInput, shoeIDTemp, ',');
//    }
//
//}
string bids :: getID() {return shoeID;}
string bids :: getName() {return shoeName;}
int bids :: getAmountOfBids() {return bidsOnShoe.size();}
double bids :: getMinBid() {return minBid;}
void bids :: printShoe() {
    //sorts bids in declinging order
    sortBids();
    //print statements with formating to make a table
    cout << left << setw(shoeID.size() + 2) << "Shoe ID" << left << setw(shoeName.size() + 2) << "Shoe Name" << right << "Minimum Bid" << endl << "_______________________________________________________________" << endl;
    cout << left << setw(shoeID.size() + 2) << shoeID << left << setw(shoeName.size() + 2) << shoeName << right << "$" << minBid << endl;
    cout << left << setw(15) << endl <<"Bidder ID" << left <<  "Bid Amount" << endl << "_________________________" << endl;
    //iteratores over bids
    for (int i = 0; i < bidsOnShoe.size(); i++) {
            cout << left << setw(7) << bidderID[i] << right << setw(7) << fixed << setprecision(2) << "$" << bidsOnShoe[i] << endl;
    }
}
void bids :: sortBids() {
    //sorts bids into largest bid to smallest bid
    int i, j;
    double tempD;
    for (i = 0; i < bidsOnShoe.size() - 1; i++) {
        for (j = i + 1; j < bidsOnShoe.size(); ++j) {
            if (bidsOnShoe.at(j) > bidsOnShoe.at(i)) {
                //swaps bid and bidderid at the same time if they are larger then the one infront of them
                tempD = bidsOnShoe.at(i);
                bidsOnShoe.at(i) = bidsOnShoe.at(j);
                bidsOnShoe.at(j) = tempD;

                tempD = bidderID.at(i);
                bidderID.at(i) = bidderID.at(j);
                bidderID.at(j) = tempD;
            }
        }
    }
}
