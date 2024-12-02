#include <chrono>
#include <iostream>

#include "Home.h"
#include "Utils.h"

using namespace std;

int showMainMenu() {
    int choice;

    showDashLoop();
    cout << endl;
    cout << "WELCOME TO XYZ CINEMA SYSTEM";
    cout << endl;
    showDashLoop();
    cout << endl<<endl;
    cout << "\t[0]\tAdministrator"<<endl<<"\t[1]\tCustomer"<<endl<<endl;
    cout << "Please choose your role to get started: ";

    // Read the input as a string
    string input;
    cin >> input;
    

    // Check if the input is numeric and '0'
    if (input == "0") {
        choice = 0;
    } else {
        choice = 1;  // Any other input will be treated as a Customer
    }
    cin.clear(); // Clear the error state of cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return choice;
}

// Main function
int main() {
    int choice;

    choice = showMainMenu();

    if (choice == 0) 
	{
    	clearScreen();
        showAdminMenu();
	}else{	
	    clearScreen();    	
    	showCustomerMenu();
}	
    return 0;
}