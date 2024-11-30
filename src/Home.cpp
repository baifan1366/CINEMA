#include <iostream>
#include <limits>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Home.h"
#include "MovieManagement.h"

void showCustomerMenu() 
{
    int choice;
    // Menu options
    showDashLoop();
    cout << endl;
    cout << "\t--- Customer Menu ---" << endl;
    cout << "1. View Available Movies" << endl;
    cout << "2. Book Tickets" << endl;
    cout << "3. Check Booking Status" << endl;
    cout << "4. Exit" << endl;
    showDashLoop();
    cout << endl;
    cout << "Enter Your Choice: ";
    // Input validation and checking
    cin >> choice;
    // Check if the input is valid
    while (cin.fail() || choice < 1 || choice > 4)
    {
    	cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining invalid characters
        cout << "Please re-enter a valid option [1 | 2 | 3 | 4]: ";
        cin>>choice;
	}
    // Switch block to handle the user's choice
    switch (choice) {
        case 1:
            showLoadingAnimation("Fetching movie list", 2);
            system("pause");
            clearScreen();
            break;
        case 2:
            showLoadingAnimation("Booking tickets", 2);
            system("pause");
            clearScreen();
            break;
        case 3:
            showLoadingAnimation("Checking booking status", 2);
            system("pause");
            clearScreen();
            break;
        case 4:
            clearScreen();
            cout << "Thank you for visiting! Goodbye!" << endl;
            exit(0); // Exit the program
            break;
    }
}

void clearScreen()
{
	system("CLS");
}

// Function to display a fake loading animation
void showLoadingAnimation(const string& message, int duration = 3) 
{
    cout << message;
    for (int i = 0; i < duration; ++i) 
	{
        cout << ".";
        cout.flush(); // Force output to appear immediately
        this_thread::sleep_for(chrono::milliseconds(500)); // 500ms delay
    }
    cout << " Done!" << endl << endl;
}

//show '-' loop
void showDashLoop() 
{
    for (int i = 0; i < 50; i++) 
	{
        cout << "-";
    }
}

//admin menu
void showAdminMenu() 
{
    int choice;
    showDashLoop();
    cout << endl;
    cout << "\t--- Admin Menu ---"<<endl;
    cout << "1. Add Admin"<<endl;
    cout << "2. Movie Management" << endl;
    cout << "3. Generate Sales Report" << endl;
    cout << "4. Exit" << endl;
    showDashLoop();
    cout << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;
    while (cin.fail() || choice < 1 || choice > 4)
    {
    	cin.clear(); // Clear the error state of cin
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining invalid characters
        cout << "Please re-enter a valid option [1 | 2 | 3 | 4]: ";
        cin>>choice;
	}
    switch (choice) 
	{
        case 1:
            showLoadingAnimation("Fetching movie list",2);
            system("pause");
            system("cls");
            break;

        case 2:
            showLoadingAnimation("Loading",2);
            system("pause");
            clearScreen();
            displayMovie();
            break;

        case 3:
            showLoadingAnimation("Checking booking status",2);
            system("pause");
            system("cls");
            break;

        case 4:
            clearScreen();
            cout << "Thank you for visiting! Goodbye!"<<endl;
			exit(0);
            break;
    } 
}