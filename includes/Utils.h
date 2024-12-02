#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

bool sendOTP(const std::string& email);
bool verifyOTP(const std::string& enteredOTP, const std::string& actualOTP);
void showDashLoop();
void showLoadingAnimation(const string& , int);
void clearScreen();

#endif // UTILS_H
