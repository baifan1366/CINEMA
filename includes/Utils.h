#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

bool sendOTP(const std::string& email);
bool verifyOTP(const std::string& enteredOTP, const std::string& actualOTP);
void showDashLoop();
void showLoadingAnimation(const string&, const string&, int);
void clearScreen();
string truncate(const string& str, size_t width);

#endif // UTILS_H
