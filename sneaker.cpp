//
// Created by Sean Grady on 4/5/2021.
//

#include "sneaker.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
sneaker :: sneaker() {
    //initialization of the sneaker object
    ifstream sneakerFile;
    sneakerFile.open("Sneakers.txt");
    int i = 0;
    if(!sneakerFile.is_open()) {cout << "File is not open" << endl;}
    //variables used for input from the file to fill out shoe information
    //used for shoe ID
    string idTemp;
    //used for name of shoe and bidder ID
    string nameTemp;
    //used for holding bid amounts
    string bidTemp;
    getline(sneakerFile, idTemp,',');
    //while loop to read the entire file that then fills the most recent shoe in the vector of bids objects
    while(!sneakerFile.eof()) {

        bids shoe;
        Sneakers.push_back(shoe);
        getline(sneakerFile, nameTemp, ',');
        getline(sneakerFile, bidTemp, '\n');
        Sneakers.at(i).setShoeData(idTemp, nameTemp, stod(bidTemp));
        //tracks what shoe the loop is on
        i++;
        getline(sneakerFile, idTemp,',');
    }
    //used to read the file for the bids

    ifstream bidsFile;
    bidsFile.open("Bidders.txt");
    if (!bidsFile.is_open()) {cout << "File is not open" << endl;}
    getline(bidsFile, idTemp, ',');
    while(!bidsFile.eof()) {
        getline(bidsFile, nameTemp, ',');
        getline(bidsFile, bidTemp, '\n');
        //searches for the sneaker in the Sneaker vector by ID
        //fills into the correct vector once it is found then breaks the for loop
        for (auto & Sneaker : Sneakers) {
            if (idTemp == Sneaker.getID()) {
                if (stod(bidTemp) >= Sneaker.getMinBid()) {
                    Sneaker.inputBids(nameTemp, bidTemp);
                    cout << idTemp << " ";
                    break;
                }
            }
        }
        getline(bidsFile, idTemp, ',');
    }
}

int sneaker :: printBids(string shoeIDin) {
        //searches for shoe that is supposed to be printed then calls the function to print it
        for (auto & Sneaker : Sneakers) {
            if (Sneaker.getID() == shoeIDin) {
                Sneaker.printShoe();
                return 1;
            }
        }
        return 0;
}
void sneaker :: displayAllIDS() {
    //prints out all sneakers

    cout << left << setw(30) << endl << "SNEAKER ID" << "SNEAKER NAME" << endl << "________________________________________________________________" << endl;
    for (auto & Sneaker : Sneakers) {
        cout << left << setw(20) << Sneaker.getID() << left << setw(20) << Sneaker.getName() << endl;
    }
}
bool sneaker :: compareShoeList(string userSneaker) {
    //takes the input from the user and checks if it matches any of the shoes in the catalog
    //if it does passes the shoe to the printBids method in the bids class
    //uses return statements to tell user if the shoe was found or not, if found prints all the data, else it tells them it wasn't a valid entry
    for(auto & Sneaker : Sneakers) {
        if (toUpperCase(userSneaker) == toUpperCase(Sneaker.getID())) {
            if (Sneaker.getAmountOfBids() > 0) {
            printBids(Sneaker.getID());
            return true;
            }
            else {
                cout << left << setw(Sneaker.getID().size() + 2) << "Shoe ID" << left << setw(Sneaker.getName().size() + 2) << "Shoe Name" << right << "Minimum Bid" << endl << "_______________________________________________________________" << endl;
                cout << left << setw(Sneaker.getID().size() + 2) << Sneaker.getID() << left << setw(Sneaker.getName().size() + 2) << Sneaker.getName() << right << "$" << Sneaker.getMinBid() << endl;
                cout << endl << "NO BIDS PRESENTED ON " << Sneaker.getName();
                return true;
            }
        }
    }
    return false;
}
string sneaker :: toUpperCase(string convert) {
    //used to test shoe entered across the entire list with out case sensitive information by making each fully uppercase while testing
    for (char & i : convert) {
        if (i >= 'a' && i <= 'z') {
            i -= 32;
        }
    }
    return convert;
}
