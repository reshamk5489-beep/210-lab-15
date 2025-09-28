#include <iostream>
#include <string>
#include <array>
#include <fstream>
using namespace std;

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
            cout << "\tMovie: " << screenWriter << endl; 
            cout << "\t\tYear released: " << year << endl;
            cout << "\t\tScreenwriter: " << title << endl << endl;
        }
};

int main()
{
    array<Movie, SIZE> movies;
    string title;
    int year;
    string screenWriter;
    int idx = 0;

    ifstream fin("input.txt");
    if (!fin.good()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    while (getline(fin, title))
    {
       fin.ignore();
       Movie temp;
       temp.setTitle(title);
       fin >> year;
       temp.setYear(year);
       fin.ignore();
       getline(fin, screenWriter);
       temp.setScreenWriter(screenWriter);

       movies[idx++] = temp;
    }

    fin.close();

    for (int i =0 ; i < SIZE; i++)
    {
        movies[i].print();
    }

    return 0;
}