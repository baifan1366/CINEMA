#ifndef TICKET_H
#define TICKET_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "qrcodegen.hpp" // Include the qrcodegen library

using namespace std;
using namespace qrcodegen;

class Ticket {
public:
    Ticket(int customerId, const string& movieDetails, const string& ticketID);

    // Getters
    int getCustomerId() const;
    string getMovieDetails() const;
    string getTicketID() const;
    string getTicketData() const;  // A helper method to combine customer and movie details

    // Setters
    void setCustomerId(int customerId);
    void setMovieDetails(const string& movieDetails);
    void setTicketID(const string& ticketID);

    // Save ticket data to a text file
    void saveToFile(const string& filename) const;

    // Generate a QR Code for the ticket
    void generateQRCode(const string& filename) const;

private:
    int customerId;
    string movieDetails;
    string ticketID;

    // Helper function to encode ticket data
    string encodeTicketData() const;
};

#endif // TICKET_H
