#include <iostream>
#include "MovieManagement.h"
#include "Movie.h"
#include "Home.h"
#include "Utils.h"

void displayMoviePage()
{
	int opt;
	string filename = "movies.txt";
	
	do
	{
		cout<<"\t--- Movie Management ---"<<endl;
		cout<<"1. Create New Movie"<<endl;
		cout<<"2. Read Movie List"<<endl;
		cout<<"3. Update Movie List"<<endl;
		cout<<"4. Delete Movie"<<endl;
		cout<<"5. Go Back to Home Page"<<endl;
		cout<<"6. Exit"<<endl<<endl;
		
		cout<<"Enter your option: ";
		cin>>opt;
		while (cin.fail() || opt < 1 || opt > 6)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"Please re-enter a valid option [1 | 2 | 3 | 4 | 5 | 6]: ";
			cin>>opt;
		}
		switch(opt)
		{
			case 1:
			{
				clearScreen();
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
                break;
            }
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
	}while (opt != 6);
}

