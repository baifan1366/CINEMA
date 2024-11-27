#include "Customer.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

// Constructor
Customer::Customer(int id, const string& name, const string& password, 
                   const string& email, const string& phone, 
                   time_t last_login, int point, const string& ticket)
    : id(id), name(name), password(password), email(email), phone(phone), 
      last_login(last_login), point(point), ticket(ticket) {}

// Getters
int Customer::getId() const {
    return id;
}

string Customer::getName() const {
    return name;
}

string Customer::getPassword() const {
    return password;
}

string Customer::getEmail() const {
    return email;
}

string Customer::getPhone() const {
    return phone;
}

time_t Customer::getLastLogin() const {
    return last_login;
}

int Customer::getPoint() const {
    return point;
}

string Customer::getTicket() const {
    return ticket;
}

// Setters
void Customer::setId(int id) {
    this->id = id;
}

void Customer::setName(const string& name) {
    this->name = name;
}

void Customer::setPassword(const string& password) {
    this->password = password;
}

void Customer::setEmail(const string& email) {
    this->email = email;
}

void Customer::setPhone(const string& phone) {
    this->phone = phone;
}

void Customer::setLastLogin(time_t last_login) {
    this->last_login = last_login;
}

void Customer::setPoint(int point) {
    this->point = point;
}

void Customer::setTicket(const string& ticket) {
    this->ticket = ticket;
}

// Save customer data to a text file
void Customer::saveToFile(const string& filename) const {
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << id << "," << name << "," << password << "," << email 
                << "," << phone << "," << last_login << "," << point 
                << "," << ticket << endl;
        outFile.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

// Load customer data from a text file
vector<Customer> Customer::loadAllFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Customer> customers;

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string field;
            vector<string> fields;

            while (getline(ss, field, ',')) {
                fields.push_back(field);
            }

            if (fields.size() == 8) {
                Customer customer(
                    stoi(fields[0]), fields[1], fields[2], fields[3], 
                    fields[4], stoll(fields[5]), stoi(fields[6]), fields[7]
                );
                customers.push_back(customer);
            }
        }
        inFile.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
    }

    return customers;
}

// Update dashboard information
void Customer::updateDashboardInfo(const string& email, const string& phone) {
    setEmail(email);
    setPhone(phone);
    cout << "Dashboard information updated successfully." << endl;
}

// Password reset using OTP
bool Customer::resetPasswordWithOtp(const string& email, const string& otp) {
    if (this->email == email && validateOtp(email, otp)) {
        string newPassword;
        cout << "Enter your new password: ";
        cin >> newPassword;
        setPassword(newPassword);
        cout << "Password updated successfully." << endl;
        return true;
    }

    cout << "Failed to reset password. Invalid email or OTP." << endl;
    return false;
}

// Generate OTP
string Customer::generateOtp() const {
    srand(time(nullptr));
    string otp = to_string(100000 + rand() % 900000); // Generate 6-digit OTP
    cout << "Generated OTP: " << otp << endl; // For demonstration
    return otp;
}

// Validate OTP
bool Customer::validateOtp(const string& email, const string& otp) const {
    string generatedOtp = generateOtp();
    return generatedOtp == otp; // Simulate OTP validation
}

// Update the ticket when a customer buys a ticket
void Customer::purchaseTicket(const string& ticketDetails) {
    setTicket(ticketDetails); // Update the ticket property with the purchased movie details
    saveToFile("customers.txt"); // Save the updated customer data back to the file

    // Store the ticket purchase details in the ticket.txt file
    ofstream ticketFile("ticket.txt", ios::app);
    if (ticketFile.is_open()) {
        ticketFile << id << "," << ticketDetails << "," << time(nullptr) << endl; // Save purchase time as well
        ticketFile.close();
    } else {
        cerr << "Unable to open ticket file for writing." << endl;
    }

    cout << "Ticket purchased successfully and saved." << endl;
}

// Sales report for the admin (to fetch ticket details from the ticket file)
vector<string> Customer::generateSalesReport(const string& ticketFile) {
    ifstream inFile(ticketFile);
    vector<string> salesReport;

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            salesReport.push_back(line); // Each line contains a ticket purchase record
        }
        inFile.close();
    } else {
        cerr << "Unable to open ticket file for reading." << endl;
    }

    return salesReport;
}
