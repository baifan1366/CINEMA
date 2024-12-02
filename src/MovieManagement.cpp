#include <iostream>
#include <vector>
#include "MovieManagement.h"
#include "Movie.h"
#include "Home.h"
#include "Utils.h"

void displayMoviePage()
{
	int choice;
	string filename = "movies.txt";

	showDashLoop();
    cout << endl;
	cout << " ADMIN MENU | MOVIE MANAGEMENT"<<endl;
	showDashLoop();
	cout<<endl<<endl;
	cout<<"\t\tMOVIE MANAGEMENT"<<endl;
    cout<<endl;
	cout<<"\t[1]\tCreate New Movie"<<endl;
	cout<<"\t[2]\tRead Movie List"<<endl;
	cout<<"\t[3]\tUpdate Movie List"<<endl;
	cout<<"\t[4]\tDelete Movie"<<endl;
	cout<<"\t[5]\tGo Back to Admin Menu Page"<<endl;
	cout<<"\t[6]\tExit"<<endl<<endl;
	showDashLoop();
    cout << endl<<endl;
	cout<<"Please enter your choice: ";
	cin>>choice;
	//cin.fail() will returns true if the last input operation failed
	while (cin.fail() || choice < 1 || choice > 6)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<endl<<"Please re-enter a valid choice: ";
		cin>>choice;
	}
	cout<<endl;
	switch(choice)
	{
		case 1:
			clearScreen();
            createMovie();
            break;
            
		case 2:
		{
			clearScreen();
            // Read Movie List
            vector<Movie> movies = Movie::loadAllFromFile(filename);
            if (movies.empty()) {
//              cout << "No movies found." << endl;
                showLoadingAnimation("Movie not found",2);
            	system("pause");
            	system("cls");
            	showAdminMenu();
            } else {
                cout << "Movie List:" << endl;
                for (const auto& movie : movies) {
                    cout << "Title: " << movie.getTitle()
                        << ", Genre: " << movie.getGenre()
                        << ", Duration: " << movie.getDuration() << " mins"
                        << ", Price: $" << movie.getPrice() << endl;
                }
            }
            break;
        }
		case 3:
		{
			clearScreen();
            // Update Movie List
            string targetTitle, newTitle, newGenre, newClassification, newCast, newSynopsis, newSubtitles, newSpokenLanguage;
            int newDuration;
            double newPrice;

                cout << "Enter the title of the movie to update: ";
                cin.ignore();
                getline(cin, targetTitle);

                cout << "Enter new title: ";
                cin.ignore();
                getline(cin, newTitle);
                cout << "Enter new genre: ";
                getline(cin, newGenre);
                cout << "Enter new classification: ";
                getline(cin, newClassification);
                cout << "Enter new cast: ";
                getline(cin, newCast);
                cout << "Enter new synopsis: ";
                getline(cin, newSynopsis);
                cout << "Enter new subtitles: ";
                getline(cin, newSubtitles);
                cout << "Enter new spoken language: ";
                getline(cin, newSpokenLanguage);
                cout << "Enter new duration (minutes): ";
                cin >> newDuration;
                cout << "Enter new price: ";
                cin >> newPrice;

                Movie updatedMovie(newTitle, newGenre, newClassification, newCast, newSynopsis, newSubtitles, newSpokenLanguage, newDuration, newPrice);
                if (Movie::updateMovieInFile(filename, targetTitle, updatedMovie)) {
                    cout << "Movie updated successfully!" << endl;
                } else {
                   cout << "Movie not found." << endl;
                }
            break;
        }
		case 4:
		{
				clearScreen();
                // Delete Movie
                string targetTitle;
                cout << "Enter the title of the movie to delete: ";
                cin.ignore();
                getline(cin, targetTitle);

                if (Movie::deleteMovieFromFile(filename, targetTitle)) {
                    cout << "Movie deleted successfully!" << endl;
                } else {
                    cout << "Movie not found." << endl;
                }
            break;
        }
		case 5:
			clearScreen();
			showAdminMenu();
			break;
		case 6:
			clearScreen();
            cout << "Thank you for visiting! Goodbye!"<<endl;
			exit(1);
			break;
	}
}

void createMovie()
{
	string filename = "movies.txt";
	showDashLoop();
    cout << endl;
	cout << " ADMIN MENU | MOVIE MANAGEMENT | CREATE MOVIE "<<endl;
	showDashLoop();
	cout<<endl<<endl;
	cout<<"\t\tCREATE NEW MOVIE"<<endl;
    cout<<endl;	

	// Create New Movie
    string title, genre, classification, cast, synopsis, subtitles, spokenLanguage;
    int duration;
    double price;
    
    cout << "Movie Title: ";
    cin.ignore();
    getline(cin, title);
    
    cout << "Genre: ";
    getline(cin, genre);
    
    cout << "Classification: ";
    getline(cin, classification);
    
    cout << "Cast: ";
    getline(cin, cast);
    
    cout << "Synopsis: ";
    getline(cin, synopsis);
    
    cout << "Subtitles: ";
    getline(cin, subtitles);
    
    cout << "Spoken Language: ";
    getline(cin, spokenLanguage);
    
    cout << "Running Time (in minutes): ";
    cin.ignore();
	cin >> duration;
	
    cout << "Price: RM";
    cin.ignore();
    cin >> price;

	//class 
    Movie newMovie(title, genre, classification, cast, synopsis, subtitles, spokenLanguage, duration, price);
	newMovie.saveToFile(filename);
    cout << "Movie added successfully!" << endl;	
}