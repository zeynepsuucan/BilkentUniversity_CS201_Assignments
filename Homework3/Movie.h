//written by Zeynep Su Uçan
//22103044 - Section 3

#ifndef __MOVIE_H
#define __MOVIE_H

#include <string>
#include <iostream>

using namespace std;

class Movie {
public:
    Movie();
    Movie(int movieId, int movieCopy);
    const int getID();
    const int getNumOfCopies();
    const int getRentedCopy();
    void setRentedCopy(int);
private:
    int movieId;
    int movieCopy;
    int rentedCopy;
};
#endif