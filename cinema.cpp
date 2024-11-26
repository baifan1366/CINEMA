#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

// Helper functions
string currentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    string result(dt);
    result.pop_back(); // Remove newline
    return result;
}

// User class
class User {
public:
    int id;
    string name;
    string password;
    string lastLogin;
    int points;

    User() : id(0), points(0) {}

    void resetPassword(const string& newPassword) {
        password = newPassword;
        cout << "Password reset successful.\n";
    }

    void loadUserFromFile(const string& filename);
    void saveUserToFile(const string& filename);
};

// Cart class
class Cart {
public:
    int userId;
    vector<string> tickets;

    Cart(int uid) : userId(uid) {}

    void addItem(const string& ticket) {
        tickets.push_back(ticket);
    }

    void removeItem(const string& ticket) {
        tickets.erase(remove(tickets.begin(), tickets.end(), ticket), tickets.end());
    }

    void displayCart() {
        cout << "Cart items for user " << userId << ":\n";
        for (const auto& item : tickets) {
            cout << "- " << item << endl;
        }
    }
};

// Ticket class
class Ticket {
public:
    int userId;
    string movieName;
    string time;
    float price;

    Ticket(int uid, const string& name, const string& t, float p)
        : userId(uid), movieName(name), time(t), price(p) {}

    void saveTicketToFile(const string& filename);
    void loadTicketsFromFile(const string& filename, vector<Ticket>& tickets);
};

// Admin class
class Admin {
public:
    string name;
    string password;
    string lastLogin;

    void createMovie();
    void manageUsers();
    void generateSalesReport();
};

// Hall class
class Hall {
public:
    int hallNum;
    int seats[5][5][5] = {}; // 3D array for seats

    void crudSeat(int x, int y, int z, int status) {
        if (x >= 0 && x < 5 && y >= 0 && y < 5 && z >= 0 && z < 5) {
            seats[x][y][z] = status;
            cout << "Seat updated.\n";
        } else {
            cout << "Invalid seat position.\n";
        }
    }
};

// Movie class
class Movie {
public:
    string name;
    string time;
    float price;
    int hallNum;

    Movie(const string& n, const string& t, float p, int h)
        : name(n), time(t), price(p), hallNum(h) {}

    void saveMovieToFile(const string& filename);
    void loadMoviesFromFile(const string& filename, vector<Movie>& movies);
};

// Function implementations for saving/loading
void User::loadUserFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        file >> id >> name >> password >> lastLogin >> points;
        file.close();
    } else {
        cout << "Unable to open file for reading: " << filename << endl;
    }
}

void User::saveUserToFile(const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << id << " " << name << " " << password << " " << lastLogin << " " << points << endl;
        file.close();
    } else {
        cout << "Unable to open file for writing: " << filename << endl;
    }
}

void Ticket::saveTicketToFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << userId << " " << movieName << " " << time << " " << price << endl;
        file.close();
    } else {
        cout << "Unable to open file for writing: " << filename << endl;
    }
}

void Ticket::loadTicketsFromFile(const string& filename, vector<Ticket>& tickets) {
    ifstream file(filename);
    if (file.is_open()) {
        int uid;
        string name, t;
        float p;
        while (file >> uid >> name >> t >> p) {
            tickets.emplace_back(uid, name, t, p);
        }
        file.close();
    } else {
        cout << "Unable to open file for reading: " << filename << endl;
    }
}

void Movie::saveMovieToFile(const string& filename) {
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << name << " " << time << " " << price << " " << hallNum << endl;
        file.close();
    } else {
        cout << "Unable to open file for writing: " << filename << endl;
    }
}

void Movie::loadMoviesFromFile(const string& filename, vector<Movie>& movies) {
    ifstream file(filename);
    if (file.is_open()) {
        string n, t;
        float p;
        int h;
        while (file >> n >> t >> p >> h) {
            movies.emplace_back(n, t, p, h);
        }
        file.close();
    } else {
        cout << "Unable to open file for reading: " << filename << endl;
    }
}

// Main function
int main() {
    User user;
    user.id = 1;
    user.name = "John Doe";
    user.password = "12345";
    user.lastLogin = currentDateTime();
    user.points = 100;
    user.saveUserToFile("user.txt");

    Cart cart(user.id);
    cart.addItem("Movie Ticket A");
    cart.addItem("Movie Ticket B");
    cart.displayCart();

    Ticket ticket(user.id, "Avengers", "10:00 AM", 10.0f);
    ticket.saveTicketToFile("tickets.txt");

    Movie movie("Avengers", "10:00 AM", 10.0f, 1);
    movie.saveMovieToFile("movies.txt");

    return 0;
}
