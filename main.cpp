#include <iostream>
#include <string>
#include <array>
#include <fstream>
using namespace std;

// Comment #1: Define a constant integer SIZE with a value of 4 to represent the number of movies.
const int SIZE = 4;

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
            cout << "\tMovie: " << screenWriter << endl; 
            cout << "\t\tYear released: " << year << endl;
            cout << "\t\tScreenwriter: " << title << endl << endl;
        }
};

int main()
{
    // Comment #5: Create an array of Movie objects with a size defined by the SIZE constant.
    array<Movie, SIZE> movies;
    
    // Comment #6: Read movie data from a file named input.txt, where each movie's title, year, and screenwriter are stored on separate lines.
    string title;
    int year;
    string screenWriter;
    int idx = 0;

    // Comment #7: Open the input.txt file for reading and handle any potential file opening errors.
    ifstream fin("input.txt");
    if (!fin.good()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    // Comment #8: Populate the array of Movie objects with data read from the file.
    while (getline(fin, title))
    {
       Movie temp;
       temp.setTitle(title);
       fin >> year;
       temp.setYear(year);
       fin.ignore();
       getline(fin, screenWriter);
       temp.setScreenWriter(screenWriter);

       movies[idx++] = temp;
    }

    // Comment #9: Close the input file after reading all the data.
    fin.close();

    // Comment #10: Iterate through the array of Movie objects and call the print method for each movie to display its details.
    for (int i =0 ; i < SIZE; i++)
    {
        movies[i].print();
    }

    return 0;
}