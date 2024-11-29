#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

// Function to display a fake loading animation
void showLoadingAnimation(const string& message, int duration = 3) {
    cout << message;
    for (int i = 0; i < duration; ++i) {
        cout << ".";
        cout.flush(); // Force output to appear immediately
        this_thread::sleep_for(chrono::milliseconds(500)); // 500ms delay
    }
    cout << " Done!" << endl << endl;
}

//show '-' loop
void showDashLoop() {
    for (int i = 0; i < 50 < i++;) {
        cout << "-";
    }
}


int showMainMenu(){
    int choice;

    showDashLoop();
    cout << endl;
    cout << "Welcome to XYZ Cinema System";
    showDashLoop();
    cout << endl;
    cout << "Please Choose Your Role [0 for admin, any other number for Customer]: ";
    cin >> choice;

    return choice;
}


//customer menu
void showCustomerMenu() {
    int choice;

    do {
        //Menu options
        showDashLoop();
        cout << endl;
        cout << "Customer Menu"<<endl;
        cout << "1. View Available Movies"<<endl;
        cout << "2. Book Tickets" << endl;
        cout << "3. Check Booking Status" << endl;
        cout << "4. Exit" << endl;
        showDashLoop();
        cout << endl;
        cout << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showLoadingAnimation("Fetching movie list");
                system("pause");
                system("cls");
                break;

            case 2:
                showLoadingAnimation("Booking tickets");
                system("pause");
                system("cls");
                break;

            case 3:
                showLoadingAnimation("Checking booking status");
                system("pause");
                system("cls");
                break;

            case 4:
                cout << "Thank you for visiting! Goodbye!"<<endl;
                showMainMenu();
                cout << endl;
        }

    }while (choice != 4);

}

//admin menu
void showAdminMenu() {
    int choice;
    do {
        showDashLoop();
        cout << endl;
        cout << "1. Add Admin"<<endl;
        cout << "2. Manage Movies" << endl;
        cout << "3. Generate Sales Report" << endl;
        cout << "4. Exit" << endl;
        showDashLoop();
        cout << endl;
        cout << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            showLoadingAnimation("Fetching movie list");

            system("pause");
            system("cls");
            break;

        case 2:
            showLoadingAnimation("Booking tickets");

            system("pause");
            system("cls");
            break;

        case 3:
            showLoadingAnimation("Checking booking status");

            system("pause");
            system("cls");
            break;

        case 4:
            cout << "Thank you for visiting! Goodbye!" << endl;
            showMainMenu();
            cout << endl;
            system("pause");
            system("cls");
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            system("pause");
            system("cls");
            cout << "Enter Your Choice: ";
            cin >> choice;
    }
    } while (choice != 4);}

    // Main function
int main() {
    int choice;

    choice = showMainMenu();

    if (choice == 0) {
        showAdminMenu();
    }else {
        showCustomerMenu();
    }
    
    return 0;
}