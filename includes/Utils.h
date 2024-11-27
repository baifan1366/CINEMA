#ifndef UTILS_H
#define UTILS_H

#include <string>

bool sendOTP(const std::string& email);
bool verifyOTP(const std::string& enteredOTP, const std::string& actualOTP);

#endif // UTILS_H
