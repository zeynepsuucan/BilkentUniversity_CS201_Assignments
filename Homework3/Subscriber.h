//written by Zeynep Su Uçan
//22103044 - Section 3

#ifndef __SUBSCRIBER_H
#define __SUBSCRIBER_H
#include "Movie.h"
#include "MovieNodeSub.h"

using namespace std;

class Subscriber {
public:
    Subscriber(){}
    Subscriber(const int subscriberId); //constructor
    Subscriber(const Subscriber &otherSubs); //copy constructor
    ~Subscriber(); //destructor

    const int getID() const; 
    const int getMovieNum(){
        return this->subsMovieNum;
    }
    void addMovie(const int movieID, const int movieCopy); //adds movie to subscribers list
    void deleteMovie(const int movieId); 
    //removes the movie from subscribers list
    bool hasMovie(const int movieId); //checks if subscriber already has this movie or not
    bool hasMovieReturn(const int movieId); //checks if subscriber already has this movie or not

    void showAllMovies(); //shows the movies of the subscriber
    void showMovie(const int movieId); //shows a specific movie by its id
    MovieNodeSub* head;


private:
    int subscriberId; 
    int subsMovieNum;
    MovieNodeSub* findMovie(const int movieId) const; //finds the movie by its id
};
#endif