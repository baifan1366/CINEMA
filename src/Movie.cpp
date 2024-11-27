#include "Movie.h"

// Constructor
Movie::Movie(const string& title, const string& genre, int duration, double price)
    : title(title), genre(genre), duration(duration), price(price) {}

// Getter for title
string Movie::getTitle() const {
    return title;
}

// Getter for genre
string Movie::getGenre() const {
    return genre;
}

// Getter for duration
int Movie::getDuration() const {
    return duration;
}

// Getter for price
double Movie::getPrice() const {
    return price;
}

// Setter for title
void Movie::setTitle(const string& title) {
    this->title = title;
}

// Setter for genre
void Movie::setGenre(const string& genre) {
    this->genre = genre;
}

// Setter for duration
void Movie::setDuration(int duration) {
    this->duration = duration;
}

// Setter for price
void Movie::setPrice(double price) {
    this->price = price;
}

// Save movie data to a text file
void Movie::saveToFile(const string& filename) const {
    ofstream outFile(filename, ios::app); // Append mode
    if (outFile.is_open()) {
        outFile << title << "," << genre << "," << duration << "," << price << endl;
        outFile.close();
    } else {
        throw runtime_error("Unable to open file for writing.");
    }
}

// Load all movie data from a text file
vector<Movie> Movie::loadAllFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<Movie> movies;

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            size_t pos = 0;
            string title, genre;
            int duration;
            double price;

            pos = line.find(",");
            title = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            genre = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            duration = stoi(line.substr(0, pos));
            line.erase(0, pos + 1);

            price = stod(line);

            movies.emplace_back(title, genre, duration, price);
        }
        inFile.close();
    } else {
        throw runtime_error("Unable to open file for reading.");
    }

    return movies;
}

// Update movie data in the file
bool Movie::updateMovieInFile(const string& filename, const string& targetTitle, const Movie& updatedMovie) {
    vector<Movie> movies = loadAllFromFile(filename);
    bool found = false;

    for (auto& movie : movies) {
        if (movie.getTitle() == targetTitle) {
            movie = updatedMovie; // Update the movie data
            found = true;
            break;
        }
    }

    if (found) {
        ofstream outFile(filename, ios::trunc); // Overwrite file
        if (outFile.is_open()) {
            for (const auto& movie : movies) {
                outFile << movie.getTitle() << "," << movie.getGenre() << "," << movie.getDuration() << "," << movie.getPrice() << endl;
            }
            outFile.close();
        } else {
            throw runtime_error("Unable to open file for writing.");
        }
    }

    return found;
}

// Delete movie data from the file
bool Movie::deleteMovieFromFile(const string& filename, const string& targetTitle) {
    vector<Movie> movies = loadAllFromFile(filename);
    auto it = remove_if(movies.begin(), movies.end(), [&targetTitle](const Movie& movie) {
        return movie.getTitle() == targetTitle;
    });

    if (it != movies.end()) {
        movies.erase(it, movies.end()); // Remove the movie(s)
        ofstream outFile(filename, ios::trunc); // Overwrite file
        if (outFile.is_open()) {
            for (const auto& movie : movies) {
                outFile << movie.getTitle() << "," << movie.getGenre() << "," << movie.getDuration() << "," << movie.getPrice() << endl;
            }
            outFile.close();
        } else {
            throw runtime_error("Unable to open file for writing.");
        }
        return true;
    }

    return false; // Movie not found
}
