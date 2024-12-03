#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

#include "MovieManagement.h"
#include "Movie.h"
#include "Home.h"
#include "Utils.h"

static const int width = 25;

void displayMoviePage()
{
	int choice;
	clearScreen();
	showDashLoop();
    cout << endl;
	cout << "\033[90m ADMIN MENU\033[0m >> MOVIE MANAGEMENT"<<endl;
	showDashLoop();
	cout<<endl<<endl;
//	cout<<"\t\tMOVIE MANAGEMENT"<<endl;
//    cout<<endl;
	cout<<"\t[1]\tCreate New Movie"<<endl;
	cout<<"\t[2]\tRead Movie List"<<endl;
	cout<<"\t[3]\tUpdate Movie List"<<endl;
	cout<<"\t[4]\tDelete Movie"<<endl;
	cout<<"\t[5]\tGo Back to Previous Page"<<endl;
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
	switch(choice)
	{
		case 1:
			showLoadingAnimation("Loading create movie form", "Successful",2);
			system("pause");
			clearScreen();
            createMovie();
            break;
            
		case 2:
			clearScreen();
            readMovie();
            break;
		case 3:
			clearScreen();
            updateMovie();
            break;
		case 4:
			clearScreen();
            deleteMovie();
            break;
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
	cout << "\033[90m ADMIN MENU >> MOVIE MANAGEMENT\033[0m >> CREATE MOVIE "<<endl;
	showDashLoop();
	cout<<endl<<endl;
//	cout<<"\t\tCREATE NEW MOVIE"<<endl;
//    cout<<endl;	

	string title, genre, classification, cast, synopsis, subtitles, spokenLanguage;
    int duration;
    double price;
    
    cout <<left<<setw(width)<< "Movie Title"<<": ";
    cin.ignore();
    getline(cin, title);
	while (title.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Title cannot be empty. Please re-enter a valid movie title.\033[0m"<<endl;
	    cout <<left<<setw(width)<<"Movie Title"<<": ";
	    getline(cin, title); // Re-read input only if it's empty
	}
    cout <<left<<setw(width)<< "Genre"<<": ";
    getline(cin, genre);
	while (genre.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Genre cannot be empty. Please re-enter a valid genre. \033[0m"<<endl;
	    cout <<left<<setw(width)<<"Genre"<<": ";
	    getline(cin, genre); // Re-read input only if it's empty
	}
    cout <<left<<setw(width)<<"Classification"<<": ";
    getline(cin, classification);
	while (classification.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Classification cannot be empty. Please re-enter a valid classification. \033[0m"<<endl;
	    cout <<left<<setw(width)<<"Classification"<<": ";
	    getline(cin, classification); // Re-read input only if it's empty
	}
    cout <<left<<setw(width)<<"Cast"<<": ";
    getline(cin, cast);
	while (cast.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Cast cannot be empty. Please re-enter a valid cast. \033[0m"<<endl;
	    cout <<left<<setw(width)<<"Cast"<<": ";
	    getline(cin, cast); // Re-read input only if it's empty
	}
    cout <<left<<setw(width)<<"Synopsis"<<": ";
    getline(cin, synopsis);
	while (synopsis.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Synopsis cannot be empty. Please re-enter a valid synopsis. \033[0m"<<endl;
	    cout <<left<<setw(width)<<"Synopsis"<<": ";
	    getline(cin, synopsis); // Re-read input only if it's empty
	}
    cout <<left<<setw(width)<< "Subtitles"<<": ";
    getline(cin, subtitles);
	while (subtitles.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Subtitles cannot be empty. Please re-enter a valid subtitles. \033[0m"<<endl;
	    cout <<left<<setw(width)<<"Subtitles"<<": ";
	    getline(cin, subtitles); // Re-read input only if it's empty
	}
    cout <<left<<setw(width)<< "Spoken Language"<<": ";
    getline(cin, spokenLanguage);
	while (spokenLanguage.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Spoken language cannot be empty. Please re-enter a valid spoken language. \033[0m"<<endl;
	    cout <<left<<setw(width)<<"Spoken Language"<<": ";
	    getline(cin, spokenLanguage); // Re-read input only if it's empty
	}
    cout <<left<<setw(width)<<"Running Time (in minutes)"<<": ";
    cin.ignore();
    cin >> duration;
    //cin.fail() will returns true if the last input operation failed
	while (cin.fail() || duration < 30 || duration > 180) //not too long not too short
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\033[31m**Please re-enter a valid running time (Time Range: 30min - 180min)\033[0m"<<endl; //change to red color
		cout <<left<<setw(width)<<"Running Time (in minutes)"<<": ";
		cin>>duration;
	}	
    cout <<left<<setw(width)<< "Price"<<": RM";
    cin.ignore();
    cin >> price;
    //cin.fail() will returns true if the last input operation failed
	while (cin.fail() || price < 5 || price > 30) //only accept friendly price
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\033[31m**Please re-enter a valid price (Price Range: RM5 - RM30)\033[0m"<<endl;
		cout <<left<<setw(width)<< "Price"<<": RM";
		cin>>price;
	}	

    Movie newMovie(title, genre, classification, cast, synopsis, subtitles, spokenLanguage, duration, price);
	newMovie.saveToFile(filename);
	cout<<endl;
	showDashLoop();
	cout<<endl;
    showLoadingAnimation("Creating new movie", "Successful",2);
    system("pause");
    displayMoviePage();
}

void readMovie()
{
	string filename = "movies.txt";
	int choice;
	
	showDashLoop();
    cout << endl;
	cout << "\033[90m ADMIN MENU >> MOVIE MANAGEMENT\033[0m >> READ MOVIE "<<endl;
	showDashLoop();
	cout<<endl<<endl;
//	cout<<"\t\tREAD MOVIE LIST"<<endl;
//    cout<<endl;		
	
	string title, genre, classification, cast, synopsis, subtitles, spokenLanguage;
    int duration;
    double price;
    
    vector<Movie> movies = Movie::loadAllFromFile(filename);
    if (movies.empty()) 
	{	
		showLoadingAnimation("Searching movie(s)", "Fail",2);
		cout << "\033[31m**Movie not found. Please create a movie first.\033[0m"<<endl<<endl;
		system("pause");
        clearScreen();
        displayMoviePage();
    } 
	else 
	{
    	//make the font weight bold, and align with space
    	cout << left << setw(20 + 8) << "\033[1mTitle\033[0m"
		     << setw(15 + 8) << "\033[1mGenre\033[0m"
		     << setw(20 + 8) << "\033[1mClassification\033[0m"
		     << setw(15 + 8) << "\033[1mCast\033[0m"
		     << setw(30 + 8) << "\033[1mSynopsis\033[0m"
		     << setw(20 + 8) << "\033[1mSubtitles\033[0m"
		     << setw(20 + 8) << "\033[1mSpoken Language\033[0m"
		     << setw(10 + 8) << "\033[1mDuration\033[0m"
		     << setw(10 + 8) << "\033[1mPrice\033[0m" << endl;
    	showDashLoop();
    	cout<<endl;
		for (const auto& movie : movies) 
		{
            cout << left
             << setw(20) << truncate(movie.getTitle(), 15)
             << setw(15) << truncate(movie.getGenre(),10)
             << setw(20) << truncate(movie.getClassification(),15)
             << setw(15) << truncate(movie.getCast(), 10)
             << setw(30) << truncate(movie.getSynopsis(), 25)
             << setw(20) << truncate(movie.getSubtitles(),15)
             << setw(20) << truncate(movie.getSpokenLanguage(),15)
             << setw(10) << (to_string(movie.getDuration()) + " mins")
             << fixed << setprecision(2) << "RM" << movie.getPrice() << endl;
        }
    }
    
    //enter your choice
    showDashLoop();
    cout<<endl<<endl;
    cout<<"\t[1]\tRead Movie Details"<<endl;
	cout<<"\t[2]\tSort in Ascending / Descending"<<endl;
	cout<<"\t[3]\tFilter By Durations / Price"<<endl;
	cout<<"\t[4]\tSearch by Keywords"<<endl;
	cout<<"\t[5]\tGo Back to Previous Page"<<endl;
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
	cout<<flush;
	switch(choice)
	{
		case 1:
		{
			cin.ignore();
			string title;
			bool found = false;
			
			do {
			    // First prompt for movie title
			    cout << endl << "Please enter the movie title: ";
			    getline(cin, title);
			
			    // Check if the movie exists in the list
			    for (const auto& movie : movies) {
			        if (movie.getTitle() == title) {
			            found = true;  // Movie found
			            showLoadingAnimation("Reading movie details", "Successful", 2);
			            system("pause");
			            clearScreen();
			            readMovieDetails(title);
			            break;  // Exit the for loop as the movie is found
			        }
			    }
			
			    // If not found, show an error message and ask for the title again
			    if (!found) {
			        showLoadingAnimation("Reading movie details", "Fail", 2);
			        cout << "\033[31mMovie not found. Please re-enter the movie title.\033[0m" << endl;
			    }
			
			} while (!found);  // Repeat until the movie is found

		    break;
        }
		case 2:
			clearScreen();
//            sortMovie();
            break;
		case 3:
			clearScreen();
//            filterMovie();
            break;
		case 4:
			clearScreen();
//            searchMovie();
            break;
		case 5:
			clearScreen();
			displayMoviePage();
			break;
		case 6:
			clearScreen();
            cout << "Thank you for visiting! Goodbye!"<<endl;
			exit(1);
			break;
	}
}

void updateMovie()
{
	string filename = "movies.txt";
	vector<Movie> movies = Movie::loadAllFromFile(filename);
	showDashLoop();
    cout << endl;
	cout << "\033[90m ADMIN MENU >> MOVIE MANAGEMENT \033[0m>> UPDATE MOVIE "<<endl;
	showDashLoop();
	cout<<endl<<endl;
//	cout<<"\t\tUPDATE A MOVIE"<<endl;
//    cout<<endl;	
		
    string targetTitle, newTitle, newGenre, newClassification, newCast, newSynopsis, newSubtitles, newSpokenLanguage;
    int newDuration;
    double newPrice;
    
    cin.ignore();
    //check if there is no such movie
	bool found = false;
	do 
	{
		cout <<left<<setw(width)  << "Please enter the movie title to update"<<": ";
		getline(cin, targetTitle);
		
		if(targetTitle == "1")
		{
			clearScreen;
			displayMoviePage();
			break;
		}
		if(targetTitle == "2")
		{
			clearScreen();
            cout << "Thank you for visiting! Goodbye!"<<endl;
			exit(1);
			break;
		}
		
		for (const auto& movie : movies) 
		{
			if (movie.getTitle() == targetTitle) 
			{
			    found = true;  // Movie found
			    showLoadingAnimation("Searching in movie list", "Successful", 2);
			    break;  // Exit the for loop as the movie is found
			}
		}
			
		if (!found) 
		{
			showLoadingAnimation("Searching in movie list", "Fail", 2);
			cout << "\033[31mMovie not found. Please re-enter the movie title to update. \n\n\t[1]\tGo Back to Previous Page\n\t[2]\tExit\033[0m" << endl<<endl;
		}
	} while (!found);  // Repeat until the movie is found
	
    cout <<left<<setw(35)<< "Updated Title"<<": ";
    getline(cin, newTitle);
    while (newTitle.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Title cannot be empty. Please re-enter a valid movie title.\033[0m" << endl;
	    cout << left << setw(35) << "Updated Title" << ": ";
	    getline(cin, newTitle); // Re-read input only if it's empty
	}
    cout <<left<<setw(35) << "Updated Genre"<<": ";
    getline(cin, newGenre);
	while (newGenre.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Genre cannot be empty. Please re-enter a valid genre.\033[0m"<<endl;
	    cout <<left<<setw(35) << "Updated Genre"<<": ";
	    getline(cin, newGenre); // Re-read input only if it's empty
	}
    cout <<left<<setw(35) << "Updated Classification"<<": ";
    getline(cin, newClassification);
	while (newClassification.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Classification cannot be empty. Please re-enter a valid classification.\033[0m"<<endl;
	    cout <<left<<setw(35) << "Updated Classification"<<": ";
	    getline(cin, newClassification); // Re-read input only if it's empty
	}
    cout <<left<<setw(35) << "Updated Cast"<<": ";
    getline(cin, newCast);
	while (newCast.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Cast cannot be empty. Please re-enter a valid cast.\033[0m"<<endl;
	    cout <<left<<setw(35) << "Updated Cast"<<": ";
	    getline(cin, newCast); // Re-read input only if it's empty
	}
    cout <<left<<setw(35) << "Updated Synopsis"<<": ";
    getline(cin, newSynopsis);
	while (newSynopsis.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Synopsis cannot be empty. Please re-enter a valid synopsis.\033[0m"<<endl;
	    cout <<left<<setw(35) << "Updated Synopsis"<<": ";
	    getline(cin, newSynopsis); // Re-read input only if it's empty
	}
    cout <<left<<setw(35) << "Updated Subtitles"<<": ";
    getline(cin, newSubtitles);
	while (newSubtitles.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Subtitles cannot be empty. Please re-enter a valid subtitles.\033[0m"<<endl;
	    cout <<left<<setw(35) << "Updated Subtitles"<<": ";
	    getline(cin, newSubtitles); // Re-read input only if it's empty
	}
    cout <<left<<setw(35) << "Updated Spoken Language"<<": ";
    getline(cin, newSpokenLanguage);
	while (newSpokenLanguage.empty()) // Check if the title is empty
	{
	    cout << "\033[31m**Spoken language cannot be empty. Please re-enter a valid spoken language.\033[0m"<<endl;
	    cout <<left<<setw(35) << "Updated Spoken Language"<<": ";
	    getline(cin, newSpokenLanguage); // Re-read input only if it's empty
	}
    cout <<left<<setw(35) << "Updated Running Time (in minutes)"<<": ";
    cin.ignore();
    cin >> newDuration;
    //cin.fail() will returns true if the last input operation failed
	while (cin.fail() || newDuration < 30 || newDuration > 180) //not too long not too short
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\033[31m**Please re-enter a valid running time (Time Range: 30min - 180min)\033[0m"<<endl; //change to red color
		cout <<left<<setw(35)<<"Updated Running Time (in minutes)"<<": ";
		cin>>newDuration;
	}	
    cout <<left<<setw(35) << "Updated Price"<<": RM";
    cin.ignore();
    cin >> newPrice;
    //cin.fail() will returns true if the last input operation failed
	while (cin.fail() || newPrice < 5 || newPrice > 30) //only accept friendly price
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<"\033[31m**Please re-enter a valid price (Price Range: RM5 - RM30)\033[0m"<<endl;
		cout <<left<<setw(35)<< "Updated Price"<<": RM";
		cin>>newPrice;
	}	
    
    showDashLoop();
	cout<<endl<<endl;
	cout<<"\t[1]\tConfirm"<<endl;
	cout<<"\t[2]\tGo Back to Previous Page"<<endl;
	cout<<"\t[3]\tExit"<<endl<<endl;
	showDashLoop();
	cout << endl<<endl;
	int choice;
	cout<<"Please enter your choice: ";
	cin>>choice;
	//cin.fail() will returns true if the last input operation failed
	while (cin.fail() || choice < 1 || choice > 3)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<endl<<"Please re-enter a valid choice: ";
		cin>>choice;
	}
	switch(choice)
	{
		case 1:
			{
				Movie updatedMovie(newTitle, newGenre, newClassification, newCast, newSynopsis, newSubtitles, newSpokenLanguage, newDuration, newPrice);
			    if (Movie::updateMovieInFile(filename, targetTitle, updatedMovie)) 
				{
					showLoadingAnimation("Updating movie", "Successful", 2);
					system("pause");
					clearScreen();
					displayMoviePage();
			    } else {
			    	showLoadingAnimation("Updating movie", "Fail", 2);
				}
			}
			break;
		case 2: 
			clearScreen();
			displayMoviePage();
			break;
		default:
			clearScreen();
            cout << "Thank you for visiting! Goodbye!"<<endl;
			exit(1);
			break;
	}
}

void deleteMovie()
{
	string filename = "movies.txt";
	vector<Movie> movies = Movie::loadAllFromFile(filename);
	int choice;
	string targetTitle;
	cin.ignore();
	
	showDashLoop();
    cout << endl;
	cout << "\033[90m ADMIN MENU >> MOVIE MANAGEMENT \033[0m>> DELETE MOVIE "<<endl;
	showDashLoop();
	cout<<endl<<endl;
//	cout<<"\t\tDELETE A MOVIE"<<endl;
//    cout<<endl;	
		
    //check if there is no such movie
	bool found = false;
	do 
	{
		cout <<left<<setw(width)  << "Please enter the movie title to delete"<<": ";
		getline(cin, targetTitle);
		if(targetTitle == "1")
		{
			clearScreen;
			displayMoviePage();
			break;
		}
		if(targetTitle == "2")
		{
			clearScreen();
            cout << "Thank you for visiting! Goodbye!"<<endl;
			exit(1);
			break;
		}
		
		for (const auto& movie : movies) 
		{
			if (movie.getTitle() == targetTitle) 
			{
			    found = true;  // Movie found
			    showLoadingAnimation("Searching in movie list", "Successful", 2);
			    //display movie details for admin to confirm			    
				cout <<left<<setw(width)<< "Movie Title"<<": "<< movie.getTitle() << endl;
				cout <<left<<setw(width)<< "Genre"<<": "<< movie.getGenre() << endl;
				cout <<left<<setw(width)<<"Classification"<<": "<< movie.getClassification() << endl;
				cout <<left<<setw(width)<<"Cast"<<": "<< movie.getCast() << endl;
				cout <<left<<setw(width)<<"Synopsis"<<": "<< movie.getSynopsis() << endl;
				cout <<left<<setw(width)<< "Subtitles"<<": "<< movie.getSubtitles() << endl;
				cout <<left<<setw(width)<< "Spoken Language"<<": "<< movie.getSpokenLanguage() << endl;
				cout <<left<<setw(width)<<"Running Time"<<": "<< movie.getDuration() << " mins" << endl;
				cout <<left<<setw(width)<< "Price"<<": RM"<< fixed << setprecision(2) << movie.getPrice() << endl<<endl;
			    
				showDashLoop();
				cout<<endl<<endl;
				cout<<"\t[1]\tConfirm"<<endl;
				cout<<"\t[2]\tGo Back to Previous Page"<<endl;
				cout<<"\t[3]\tExit"<<endl<<endl;
				showDashLoop();
			    cout << endl<<endl;
				cout<<"Please enter your choice: ";
				cin>>choice;
				//cin.fail() will returns true if the last input operation failed
				while (cin.fail() || choice < 1 || choice > 3)
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout<<endl<<"Please re-enter a valid choice: ";
					cin>>choice;
				}
				switch(choice)
				{
					case 1:
						{
							if (Movie::deleteMovieFromFile(filename, targetTitle)) 
							{
						        showLoadingAnimation("Deleting movie", "Successful", 2);
								system("pause");
								clearScreen();
								displayMoviePage();
						    } else {
						    	showLoadingAnimation("Deleting movie", "Fail", 2);
						    }
						}
						break;
					case 2: 
						clearScreen();
						displayMoviePage();
						break;
					default:
						clearScreen();
			            cout << "Thank you for visiting! Goodbye!"<<endl;
						exit(1);
						break;
				}
				break;  // Exit the for loop as the movie is found
			}
		}
			
		if (!found) 
		{
			showLoadingAnimation("Searching in movie list", "Fail", 2);
			cout << "\033[31mMovie not found. Please re-enter the movie title to delete. \n\n\t[1]\tGo Back to Previous Page\n\t[2]\tExit\033[0m" << endl<<endl;
		}
	} while (!found);  // Repeat until the movie is found
}

void readMovieDetails(const string& title) 
{
    string filename = "movies.txt";
    vector<Movie> movies = Movie::loadAllFromFile(filename);
	int choice;
	
	showDashLoop();
    cout << endl;
	cout << "\033[90m ADMIN MENU >> MOVIE MANAGEMENT >> READ MOVIE\033[0m >> MOVIE DETAILS "<<endl;
	showDashLoop();
	cout<<endl<<endl;
	
	bool movieFound = false;
    for (const auto& movie : movies) {
    	if (movie.getTitle() == title)
    	{		
    		movieFound = true;
	        cout <<left<<setw(width)<< "Movie Title"<<": "<< movie.getTitle() << endl;
		    cout <<left<<setw(width)<< "Genre"<<": "<< movie.getGenre() << endl;
		    cout <<left<<setw(width)<<"Classification"<<": "<< movie.getClassification() << endl;
		    cout <<left<<setw(width)<<"Cast"<<": "<< movie.getCast() << endl;
		    cout <<left<<setw(width)<<"Synopsis"<<": "<< movie.getSynopsis() << endl;
			cout <<left<<setw(width)<< "Subtitles"<<": "<< movie.getSubtitles() << endl;
		    cout <<left<<setw(width)<< "Spoken Language"<<": "<< movie.getSpokenLanguage() << endl;
		    cout <<left<<setw(width)<<"Running Time"<<": "<< movie.getDuration() << " mins" << endl;
	        cout <<left<<setw(width)<< "Price"<<": RM"<< fixed << setprecision(2) << movie.getPrice() << endl;
	        break;
		}
    }    
    
    cout<<endl;
    showDashLoop();
    cout<<endl<<endl;
    cout<<"\t[1]\tGo Back to Previous Page"<<endl;
	cout<<"\t[2]\tExit"<<endl<<endl;
	showDashLoop();
    cout << endl<<endl;
	cout<<"Please enter your choice: ";
	cin>>choice;
	
	while (cin.fail() || choice < 1 || choice > 2)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout<<endl<<"Please re-enter a valid choice: ";
		cin>>choice;
	}
	switch(choice)
	{
		case 1:
			clearScreen();
			readMovie();
			break;
		case 2:
			clearScreen();
            cout << "Thank you for visiting! Goodbye!"<<endl;
			break;
	}
}
