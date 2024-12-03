#include <iostream>
#include <limits>

#include "Home.h"
#include "Utils.h"

using namespace std;

int showMainMenu() {
    int choice = 1;
	string role;
	showCinemaAnimation();
    showDashLoop();
    cout << "\nWELCOME TO XYZ CINEMA SYSTEM\n";
    showDashLoop();
    cout  << endl <<endl << "\t[0]\tAdministrator"<<endl<<"\t[1]\tCustomer"<<endl<<endl;
    cout << "Please enter your role to get started: ";
    
    // Read the input as a string
    cin >> role;
    
    // Check if the input is numeric and '0'
    if (role == "0") choice = 0;

    cin.clear(); // Clear the error state of cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return choice;
}

// Main function
int main() {
    int choice = showMainMenu();
	clearScreen();
	if (choice == 0) showAdminMenu();
    if (choice == 1) showCustomerMenu();
	
    return 0;
}