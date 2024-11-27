#include "Utils.h"
#include <iostream>
#include <cstdlib>
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
