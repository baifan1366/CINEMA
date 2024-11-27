#include "Admin.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <ctime>

// Constructor
Admin::Admin(const string& email, const string& password)
    : email(email), password(password), lastLogin(0) {}

// Getters
string Admin::getEmail() const {
    return email;
}

string Admin::getPassword() const {
    return password;
}

string Admin::getLastLogin() const {
    if (lastLogin == 0) {
        return "Never logged in";
    }

    char buffer[80];
    struct tm* timeinfo = localtime(&lastLogin);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}

// Setters
void Admin::setEmail(const string& email) {
    this->email = email;
}

void Admin::setPassword(const string& password) {
    this->password = password;
}

void Admin::setLastLogin() {
    time(&lastLogin);
}

// OTP Login
bool Admin::emailOtpLogin(const string& email, const string& otp) {
    if (this->email == email && validateOtp(email, otp)) {
        setLastLogin();
        cout << "Login successful. Last login time updated." << endl;
        return true;
    }

    cout << "Login failed. Invalid email or OTP." << endl;
    return false;
}

string Admin::generateOtp() const {
    srand(time(nullptr));
    string otp = to_string(100000 + rand() % 900000); // Generate 6-digit OTP
    cout << "Generated OTP: " << otp << endl; // For demonstration purposes
    return otp;
}

bool Admin::validateOtp(const string& email, const string& otp) const {
    string generatedOtp = generateOtp();
    return generatedOtp == otp; // Simulate OTP validation
}

// Movie CRUD operations
void Admin::createMovie(const string& filename, const Movie& movie) {
    movie.saveToFile(filename);
    cout << "Movie created successfully." << endl;
}

bool Admin::updateMovie(const string& filename, const string& targetTitle, const Movie& updatedMovie) {
    if (Movie::updateMovieInFile(filename, targetTitle, updatedMovie)) {
        cout << "Movie updated successfully." << endl;
        return true;
    }

    cout << "Movie not found." << endl;
    return false;
}

bool Admin::deleteMovie(const string& filename, const string& targetTitle) {
    if (Movie::deleteMovieFromFile(filename, targetTitle)) {
        cout << "Movie deleted successfully." << endl;
        return true;
    }

    cout << "Movie not found." << endl;
    return false;
}

vector<Movie> Admin::readMovies(const string& filename) const {
    return Movie::loadAllFromFile(filename);
}

// Sales report
void Admin::generateSalesReport(const string& filename) const {
    ifstream inFile(filename);
    double totalSales = 0.0;

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            size_t pos = line.rfind(",");
            if (pos != string::npos) {
                totalSales += stod(line.substr(pos + 1));
            }
        }
        inFile.close();
    } else {
        cerr << "Unable to open sales file." << endl;
        return;
    }

    cout << "Total Sales Report: $" << fixed << setprecision(2) << totalSales << endl;
}

// Admin management
void Admin::addAdmin(const string& filename, const Admin& newAdmin) {
    ofstream outFile(filename, ios::app); // Append mode
    if (outFile.is_open()) {
        outFile << newAdmin.getEmail() << "," << newAdmin.getPassword() << endl;
        outFile.close();
        cout << "Admin added successfully." << endl;
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

vector<Admin> Admin::loadAllAdmins(const string& filename) {
    ifstream inFile(filename);
    vector<Admin> admins;

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            size_t pos = line.find(",");
            string email = line.substr(0, pos);
            string password = line.substr(pos + 1);

            admins.emplace_back(email, password);
        }
        inFile.close();
    } else {
        cerr << "Unable to open admin file." << endl;
    }

    return admins;
}
