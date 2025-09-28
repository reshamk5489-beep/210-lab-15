#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <fstream>
using namespace std;

// Comment #1: Define a constant integer W20 with a value of 20 to be used for formatting output width.
const int W20 = 20;

// Comment #2: Define a class named Movie with private member variables for title, year, and screenwriter.
class Movie
{
    // Comment #3: Implement public getter and setter methods for each member variable.
    private:
        string title;
        int year;
        string screenWriter;

    // Comment #4: Implement a public method named print that outputs the movie details in a formatted manner using the W20 constant.
    public:
        string getTitle() const { return title; }
        void setTitle(const string& title) { this->title = title; }
        int getYear() const { return year; }
        void setYear(int year) { this->year = year; }
        string getScreenWriter() const { return screenWriter; }
        void setScreenWriter(const string& screenWriter) { this->screenWriter = screenWriter; }
        void print() const {
            cout << setw(W20) << "Movie: " << title << endl; 
            cout << setw(W20) << "\tYear released: " << year << endl;
            cout << setw(W20) << "\tScreenwriter: " << screenWriter << endl << endl;
        }
};

int main()
{





    return 0;
}