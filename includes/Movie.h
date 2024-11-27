#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Movie {
public:
    Movie(const string& title = "", const string& genre = "", int duration = 0, double price = 0.0);

    // Getters
    string getTitle() const;
    string getGenre() const;
    int getDuration() const;
    double getPrice() const;

    // Setters
    void setTitle(const string& title);
    void setGenre(const string& genre);
    void setDuration(int duration);
    void setPrice(double price);

    // File operations
    void saveToFile(const string& filename) const;
    static vector<Movie> loadAllFromFile(const string& filename);

    // Filtering and sorting functions
    static vector<Movie> filterByGenre(const vector<Movie>& movies, const string& genre);
    static vector<Movie> filterByPriceRange(const vector<Movie>& movies, double minPrice, double maxPrice);
    static vector<Movie> sortByTitle(const vector<Movie>& movies, bool ascending = true);
    static vector<Movie> sortByDuration(const vector<Movie>& movies, bool ascending = true);
    static vector<Movie> sortByPrice(const vector<Movie>& movies, bool ascending = true);

    // Modify and delete movie functions
    static bool updateMovieInFile(const string& filename, const string& targetTitle, const Movie& updatedMovie);
    static bool deleteMovieFromFile(const string& filename, const string& targetTitle);

private:
    string title;
    string genre;
    int duration; // in minutes
    double price; // ticket price
};

#endif // MOVIE_H