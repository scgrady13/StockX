#include <iostream>
#include "sneaker.h"
#include <string>

using namespace std;
int main() {
    //creates sneaker object which creates a vector of bids based off the file inputed
    sneaker sneakers;
    //tracks what user chooses to do
    //made a string to allow to track all incorrect responces
    string userOption;
    //user entered shoeID to look up information
    string shoeID;
    //print statements
    cout << "STOCKX SNEAKER SYSTEM";
    cout << "SELECT AN OPTION\n(1)\tDISPLAY ALL IDS\n(2)\tDISPLAY SPECIFIC SHOE\n(3)\tQUIT\nENTER OPTION: ";
    //user input prior to while loop
    cin >> userOption;
    //while loop to prompt user with a menu that they can choose an option by entering the number corrisponding to the option
    while(userOption != "3") {
        if(userOption == "1") sneakers.displayAllIDS();
        else if(userOption == "2") {
            cout << "ENTER SHOE ID: ";
            cin >> shoeID;
            if(!sneakers.compareShoeList(shoeID)){
                cout << "INVALID SHOE ID RETURNING TO MAIN MENU" << endl;
            }
        }
        else cout << "INVALID RESPONSE\nPLEASE ENTER NUMBER OPTION\n" << endl;
        cout << endl << "SELECT AN OPTION\n(1)\tDISPLAY ALL IDS\n(2)\tDISPLAY SPECIFIC SHOE\n(3)\tQUIT\nENTER OPTION: ";
        cin >> userOption;
    }
    //closing statement
    cout << "STOCKX SNEAKER SYSTEM FINISHED RUNNING";
    return 0;
}
