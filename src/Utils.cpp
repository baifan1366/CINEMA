#include "Utils.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <ctime>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
    #include <sys/ioctl.h>
#endif

//static std::string generatedOTP;
//
//bool sendOTP(const std::string& email) {
//    // Simulate OTP generation
//    srand(static_cast<unsigned>(time(0)));
//    generatedOTP = std::to_string(100000 + rand() % 900000);
//
//    // Simulate sending email
//    std::cout << "Sending OTP to " << email << ": " << generatedOTP << std::endl;
//    return true;
//}
//
//bool verifyOTP(const std::string& enteredOTP, const std::string& actualOTP) {
//    return enteredOTP == actualOTP;
//}

void clearScreen()
{
	system("CLS");
}

// Function to display a fake loading animation
void showLoadingAnimation(const string& message, const string& status, int duration = 3) 
{
    cout<<endl << message;
    for (int i = 0; i < duration; i++) 
	{
        cout << ".";
        cout.flush(); // Force output to appear immediately
        this_thread::sleep_for(chrono::milliseconds(500)); // 500ms delay
    }
    cout<<" "<< status << endl << endl;
}

//show '-' loop
void showDashLoop() {
    int width = getTerminalWidth();
    for (int i = 0; i < width; ++i) {
        cout << "-";
    }
    cout << endl;
}

// Function to get terminal width
int getTerminalWidth() {
    #ifdef _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int columns;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        return columns;
    #else
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_col;
    #endif
}

//truncate strings
string truncate(const string& str, size_t width) 
{
    if (str.length() > width) {
        return str.substr(0, width - 3) + "...";
    }
    return str;
}


void showCinemaAnimation() {
    string title = "XYZ CINEMA SYSTEM";
    string animation;
    
    for (size_t i = 0; i <= title.size(); ++i) {
        clearScreen();
        animation = title.substr(0, i);  // Gradually reveal the title
        cout << "\n\n\n\n";              // Add some vertical padding
        cout << "\t\t\t\t\t\t" << animation << endl;
        this_thread::sleep_for(chrono::milliseconds(50)); // Delay for animation effect
    }

    this_thread::sleep_for(chrono::milliseconds(1000)); // Pause after full reveal
    clearScreen();
}