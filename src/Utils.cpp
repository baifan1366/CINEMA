#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>

static std::string generatedOTP;

bool sendOTP(const std::string& email) {
   // Simulate OTP generation
   srand(static_cast<unsigned>(time(0)));
   generatedOTP = std::to_string(100000 + rand() % 900000);

   // Simulate sending email
   std::cout << "Sending OTP to " << email << ": " << generatedOTP << std::endl;
   return true;
}

bool verifyOTP(const std::string& enteredOTP, const std::string& actualOTP) {
   return enteredOTP == actualOTP;
}

void clearScreen()
{
	system("CLS");
}

// Function to display a fake loading animation
void showLoadingAnimation(const string& message, int duration = 3) 
{
    cout<<endl << message;
    for (int i = 0; i < duration; i++) 
	{
        cout << ".";
        cout.flush(); // Force output to appear immediately
        this_thread::sleep_for(chrono::milliseconds(500)); // 500ms delay
    }
    cout << " Successful!" << endl << endl;
}

//show '-' loop
void showDashLoop() 
{
    for (int i = 0; i < 50; i++) 
	{
        cout << "-";
    }
}