//written by Zeynep Su Uçan
//22103044 - Section 3

#ifndef __SYSTEM_H

#define __SYSTEM_H
#include <string>
#include <iostream>
#include <string>
#include "Movie.h"
#include "Subscriber.h"
#include "SubscriberNode.h"
#include "MovieNode.h"

using namespace std;

class MovieRentalSystem {
public:
MovieRentalSystem( const string movieInfoFileName,
                      const string subscriberInfoFileName );
~MovieRentalSystem();
void removeMovie( const int movieId );
void addMovie( const int movieId, const int numCopies );
void removeSubscriber( const int subscriberId );
void rentMovie( const int subscriberId, const int movieId );
void returnMovie( const int subscriberId, const int movieId );
void showMoviesRentedBy( const int subscriberId ) const;
void showSubscribersWhoRentedMovie( const int movieId ) const;
void showAllMovies() const;
void showAllSubscribers() const;

private: 
    MovieNode* MovieHead;
    SubscriberNode* SubscriberHead;
    int numOfSubs = 0;
    int numOfMovies = 0;

    /*MovieNode* movieFinder(const int movieId) const;
    SubscriberNode* subscriberFinder(const int subscriberId) const;
    SubscriberNode* findStudent(const int movieId) const;
    bool ifReturned(SubscriberNode* subscriberNode, const int movieId);
    bool deleteMovie(const int movieId);*/
};
#endif