#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <fstream>
using namespace std;

// Comment #1: Define a constant integer W20 with a value of 20 to be used for formatting output width.
const int W20 = 20;

// Comment #2: Define a constant integer SIZE with a value of 4 to represent the number of movies.
const int SIZE = 4;

// Comment #3: Define a class named Movie with private member variables for title, year, and screenwriter.
class Movie
{
    // Comment #4: Implement public getter and setter methods for each member variable.
    private:
        string title;
        int year;
        string screenWriter;

    // Comment #5: Implement a public method named print that outputs the movie details in a formatted manner using the W20 constant.
    public:
        string getTitle() const { return title; }
        void setTitle(const string& title) { this->title = title; }
        int getYear() const { return year; }
        void setYear(int year) { this->year = year; }
        string getScreenWriter() const { return screenWriter; }
        void setScreenWriter(const string& screenWriter) { this->screenWriter = screenWriter; }
        void print() const {
            cout << setw(W20) << "Movie: " << screenWriter << endl; 
            cout << setw(W20) << "\tYear released: " << year << endl;
            cout << setw(W20) << "\tScreenwriter:  " << title << endl << endl;
        }
};

int main()
{
    // Comment #6: In the main function, set the output format to fixed with a precision of 2 decimal places.
    cout << fixed << setprecision(2);
    array<Movie, SIZE> movies;
    string title;
    int year;
    string screenWriter;

    ifstream fin("input.txt");
    if (!fin.good()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (fin >> title)
    {
       fin.ignore();
       Movie temp;
       temp.setTitle(title);
       fin >> year;
       temp.setYear(year);
       fin.ignore();
       fin >> screenWriter;
       temp.setScreenWriter(screenWriter);
    }

    fin.close();

    for (int i =0 ; i < SIZE; i++)
    {
        movies[i].print();
    }

    return 0;
}