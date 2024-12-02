#include <iostream>
#include "MovieManagement.h"
#include "Movie.h"
#include "Home.h"
#include "Utils.h"

void displayMoviePage()
{
	int choice;
	string filename = "movies.txt";

	do
	{
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
		cout<<"\t[5]\tGo Back to Home Page"<<endl;
		cout<<"\t[6]\tExit"<<endl<<endl;
		showDashLoop();
    	cout << endl<<endl;
		cout<<"Please enter your choice: ";
		cin>>choice;
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
//                    cout << "No movies found." << endl;
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
                string targetTitle, newTitle, newGenre;
                int newDuration;
                double newPrice;

                cout << "Enter the title of the movie to update: ";
                cin.ignore();
                getline(cin, targetTitle);

                cout << "Enter new title: ";
                getline(cin, newTitle);
                cout << "Enter new genre: ";
                getline(cin, newGenre);
                cout << "Enter new duration (minutes): ";
                cin >> newDuration;
                cout << "Enter new price: ";
                cin >> newPrice;

                Movie updatedMovie(newTitle, newGenre, newDuration, newPrice);
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
	}while (choice != 6);
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
    string title, genre;
    int duration;
    double price;
    
    cout << "Enter movie title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter genre: ";
    getline(cin, genre);
    cout << "Enter duration (minutes): ";
	cin >> duration;
    cout << "Enter price: ";
    cin >> price;

    Movie newMovie(title, genre, duration, price);
    newMovie.saveToFile(filename);
    cout << "Movie added successfully!" << endl;	
}