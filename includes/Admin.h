#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include <ctime>
#include "Movie.h"

using namespace std;

class Admin {
public:
    // Constructor
    Admin(const string& email = "", const string& password = "");

    // Getters
    string getEmail() const;
    string getPassword() const;
    string getLastLogin() const;

    // Setters
    void setEmail(const string& email);
    void setPassword(const string& password);
    void setLastLogin();

    // Authentication and OTP login
    bool emailOtpLogin(const string& email, const string& otp);

    // Movie CRUD operations
    void createMovie(const string& filename, const Movie& movie);
    bool updateMovie(const string& filename, const string& targetTitle, const Movie& updatedMovie);
    bool deleteMovie(const string& filename, const string& targetTitle);
    vector<Movie> readMovies(const string& filename) const;

    // Sales report generation
    void generateSalesReport(const string& filename) const;

    // Admin management
    static void addAdmin(const string& filename, const Admin& newAdmin);
    static vector<Admin> loadAllAdmins(const string& filename);

private:
    string email;
    string password;
    time_t lastLogin;

    // Helper functions
    string generateOtp() const;
    bool validateOtp(const string& email, const string& otp) const;
};

#endif // ADMIN_H
