#ifndef PROJECT_1_ROTTENTOMATOES_H
#define PROJECT_1_ROTTENTOMATOES_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;
using std :: string;
using std :: ifstream;
using std :: vector;
using std :: ostream;
using std :: setw;
using std :: left;
using std :: right;

class Movie {
private:
    //Declaring class fields
    //Order: title,contentRating, genres, directors, runtime, tomatoStatus, tomatoRating, audienceRating, topCritics
    string title, contentRating, genres, directors, tomatoStatus;
    int runtime, tomatoRating, audienceRating, topCritics;

public:
    //Default constructors
    Movie() {
        title = "null";
        contentRating = "null";
        directors = "null";
        tomatoStatus = "null";
        genres = "null";
        runtime = tomatoRating = audienceRating = topCritics = 0;
    }

    //Read-in constructor
    Movie(string title, string contentRating, string genres, string directors, int runtime, string tomatoStatus, int tomatoRating, int audienceRating, int topCritics) {
        this->title = title;
        this->contentRating = contentRating;
        this->genres = genres;
        this->directors = directors;
        this->runtime = runtime;
        this->tomatoStatus = tomatoStatus;
        this->tomatoRating = tomatoRating;
        this->audienceRating = audienceRating;
        this->topCritics = topCritics;
    }

    //Getters
    string getTitle() {
        return title;
    }

    string getContentRating() {
        return contentRating;
    }

    string getGenres() {
        return genres;
    }

    string getDirectors() {
        return directors;
    }

    int getRunTime() {
        return runtime;
    }

    string getTomatoStatus() {
        return tomatoStatus;
    }

    int getTomatoRating() {
        return tomatoRating;
    }

    int getAudienceRating() {
        return audienceRating;
    }

    int getTopCritics() {
        return topCritics;
    }

    //Setters
    void setTitle(string title) {
        this->title = title;
    }

    void setContentRating(string contentRating) {
        this->contentRating = contentRating;
    }

    void setGenres(string genres) {
        this->genres = genres;
    }

    void setDirectors(string directors) {
        this->directors = directors;
    }

    void setRunTime(int runtime) {
        this->runtime = runtime;
    }

    void setTomatoStatus(string tomatoStatus) {
        this->tomatoStatus = tomatoStatus;
    }

    void setTomatoRating(int tomatoRating) {
        this->tomatoRating = tomatoRating;
    }

    void setAudienceRating(int audienceRating) {
        this->audienceRating = audienceRating;
    }

    void setTopCritics(int topCritics) {
        this->topCritics = topCritics;
    }

    //Overloading Operators
    //Order: title,contentRating, genres, directors, runtime, tomatoStatus, tomatoRating, audienceRating, topCritics
    friend ostream &operator<<(ostream &outs, const Movie movie) {
        outs << left << setw(55) << movie.title;
        outs << right << setw(3) << movie.contentRating;
        outs << "  " << left << setw(77) << movie.genres;
        outs << left << setw(65) << movie.directors;
        outs << left << setw(4) << movie.runtime;
        outs << setw(17) << movie.tomatoStatus;
        outs << right << setw(4) << movie.tomatoRating;
        outs << right << setw(4) << movie.audienceRating;
        outs << right << setw(4) << movie.topCritics;
        return outs;
    }

    //Overloading the < operator
    friend bool operator<(const Movie& base, const Movie& other){
        if(base.tomatoRating < other.tomatoRating)
            return true;
        else
            return false;
    }

    //Overloading the > operator
    friend bool operator>(Movie& base, Movie& other){
        if(base.tomatoRating > other.tomatoRating)
            return true;
        else
            return false;
    }

    //Overloading the <= operator
    friend bool operator<=(Movie& base, Movie& other){
        if(base.tomatoRating < other.tomatoRating)
            return true;
        else if(base.tomatoRating == other.tomatoRating)
            return true;
        else
            return false;
    }

    //Overloading the >= operator
    friend bool operator>=(Movie& base, Movie& other){
        if(base.tomatoRating > other.tomatoRating)
            return true;
        else if(base.tomatoRating == other.tomatoRating)
            return true;
        else
            return false;
    }

    //Overloading the == operator
    friend bool operator==(Movie& base, Movie& other){
        if(base.title == other.title)
            return true;
        else
            return false;
    }
};

void getDataFromFile(string filename, vector<Movie> &movie) {

    //Opening file to read from
    ifstream fIn;
    fIn.open(filename);

    //Setting headers
    string headers;
    if (fIn) {
        getline(fIn, headers);
    }

    //Declaring needed variables for the function
    string title, contentRating, genres, directors, tomatoStatus, junk;
    int runtime, tomatoRating, audienceRating, topCritics;
    char comma, quote;

    //Read in while stream is good and isn't out of things to read
    while (fIn && fIn.peek() != EOF) {

        //In case there are commas in the title values
        if (fIn.peek() == '"') {
            fIn >> quote;
            getline(fIn, title, '"');
            fIn >> comma;
        } else {
            //Read in name without quotation marks
            getline(fIn, title, ',');
        }

        //Reading in content rating and moving past comma
        getline(fIn, contentRating, ',');

        //Reading in genre listing which is in quotation marks
        if (fIn.peek() == '"') {
            fIn >> quote;
            getline(fIn, genres, '"');
            fIn >> comma;
        } else {
            //Read in genres without quotation marks
            getline(fIn, genres, ',');
        }

        //In case there are multiple directors
        if (fIn.peek() == '"') {
            fIn >> quote;
            getline(fIn, directors, '"');
            fIn >> comma;
        } else {
            //Read in name without quotation marks
            getline(fIn, directors, ',');
        }

        //Reading in runtime and moving past comma
        if (fIn.peek() == ',') {
            runtime = 0;
            fIn >> comma;
        } else {
            //Read in name without quotation marks
            fIn >> runtime;
            fIn >> comma;
        }

        //Checking for empty tomatoStatus
        if (fIn.peek() == ',') {
            tomatoStatus = "null";
            fIn >> comma;
        } else {
            //Read in tomatoStatus
            getline(fIn, tomatoStatus, ',');
        }

        //Checking for empty tomatoRating
        if (fIn.peek() == ',') {
            tomatoRating = 0;
            fIn >> comma;
        } else {
            //Read in tomatoRating and eliminate commas
            fIn >> tomatoRating;
            fIn >> comma;
        }

        //Reading in audienceRating and moving past comma
        if (fIn.peek() == ',') {
            audienceRating = 0;
            fIn >> comma;
        } else {
            //Read in name without quotation marks
            fIn >> audienceRating;
            fIn >> comma;
        }

        //Checking topCritics for empty value
        if (fIn.peek() == ',') {
            topCritics = 0;
            getline(fIn, junk);
        } else {
            //Read in topCritics and eliminate endline
            fIn >> topCritics;
            getline(fIn, junk);
        }

        //Create a movie object, fill it, and add it to the vector
        movie.push_back(Movie(title, contentRating, genres, directors, runtime, tomatoStatus, tomatoRating, audienceRating, topCritics));
    }
    //Close file
    fIn.close();
}

#endif //PROJECT_1_ROTTENTOMATOES_H