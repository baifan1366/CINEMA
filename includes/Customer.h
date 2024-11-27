#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <fstream>
#include <vector>
#include <ctime>
using namespace std;

class Customer {
public:
    Customer(int id = 0, const string& name = "", const string& password = "", 
             const string& email = "", const string& phone = "", 
             time_t last_login = 0, int point = 0, const string& ticket = "");

    // Getters
    int getId() const;
    string getName() const;
    string getPassword() const;
    string getEmail() const;
    string getPhone() const;
    time_t getLastLogin() const;
    int getPoint() const;
    string getTicket() const;

    // Setters
    void setId(int id);
    void setName(const string& name);
    void setPassword(const string& password);
    void setEmail(const string& email);
    void setPhone(const string& phone);
    void setLastLogin(time_t last_login);
    void setPoint(int point);
    void setTicket(const string& ticket);

    // Save customer data to a text file
    void saveToFile(const string& filename) const;

    // Load customer data from a text file
    static vector<Customer> loadAllFromFile(const string& filename);

    // Dashboard setup
    void updateDashboardInfo(const string& email, const string& phone);

    // Password reset using OTP
    bool resetPasswordWithOtp(const string& email, const string& otp);

    // Update the ticket when a customer buys a ticket
    void purchaseTicket(const string& ticketDetails);

    // Sales report for the admin (to fetch ticket details from the ticket file)
    static vector<string> generateSalesReport(const string& ticketFile);

private:
    int id;
    string name;
    string password;
    string email;
    string phone;
    time_t last_login; // Stored as Unix timestamp
    int point;
    string ticket;

    // Helper function to generate OTP
    string generateOtp() const;

    // Helper function to validate OTP
    bool validateOtp(const string& email, const string& otp) const;
};

#endif // CUSTOMER_H
