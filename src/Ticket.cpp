#include "Ticket.h"
#include "qrcodegen.hpp" // Include the qrcodegen library
#include <iostream>
#include <sstream>
#include <fstream>

using namespace qrcodegen;
using namespace std;

// Constructor
Ticket::Ticket(int customerId, const string& movieDetails, const string& ticketID)
    : customerId(customerId), movieDetails(movieDetails), ticketID(ticketID) {}

// Getters
int Ticket::getCustomerId() const {
    return customerId;
}

string Ticket::getMovieDetails() const {
    return movieDetails;
}

string Ticket::getTicketID() const {
    return ticketID;
}

string Ticket::getTicketData() const {
    return encodeTicketData();
}

// Setters
void Ticket::setCustomerId(int customerId) {
    this->customerId = customerId;
}

void Ticket::setMovieDetails(const string& movieDetails) {
    this->movieDetails = movieDetails;
}

void Ticket::setTicketID(const string& ticketID) {
    this->ticketID = ticketID;
}

// Encode the ticket data to a string
string Ticket::encodeTicketData() const {
    stringstream ss;
    ss << "Customer ID: " << customerId << "\n"
       << "Movie Details: " << movieDetails << "\n"
       << "Ticket ID: " << ticketID;
    return ss.str();
}

// Save ticket data to a text file
void Ticket::saveToFile(const string& filename) const {
    ofstream outFile(filename, ios::app);
    if (outFile.is_open()) {
        outFile << customerId << "," << movieDetails << "," << ticketID << endl;
        outFile.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
    }
}

// Generate QR Code for the ticket
void Ticket::generateQRCode(const string& filename) const {
    string ticketData = encodeTicketData();

    // Use the qrcodegen library to generate the QR code
    const QrCode qr = QrCode::encodeText(ticketData.c_str(), QrCode::Ecc::LOW);

    // Save QR code as an image (in PPM format, for simplicity)
    ofstream outFile(filename, ios::binary);
    if (outFile.is_open()) {
        outFile << "P6\n";
        outFile << qr.getSize() << " " << qr.getSize() << "\n";
        outFile << "255\n";
        
        // Iterate through each module (pixel) and write it as RGB
        for (int y = 0; y < qr.getSize(); ++y) {
            for (int x = 0; x < qr.getSize(); ++x) {
                unsigned char color = qr.getModule(x, y) ? 0 : 255; // Black or White
                outFile.write(reinterpret_cast<char*>(&color), sizeof(color));
                outFile.write(reinterpret_cast<char*>(&color), sizeof(color));
                outFile.write(reinterpret_cast<char*>(&color), sizeof(color));
            }
        }

        outFile.close();
        cout << "QR Code generated and saved to " << filename << endl;
    } else {
        cerr << "Unable to open file for saving QR code." << endl;
    }
}
