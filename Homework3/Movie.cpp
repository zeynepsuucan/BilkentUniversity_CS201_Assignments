//written by Zeynep Su Uçan
//22103044 - Section 3

#include <string>
#include <iostream>
#include "Movie.h"

using namespace std;

    Movie::Movie(){
        
    }
    Movie::Movie(int movieId, int movieCopy){
        this->movieId = movieId;
        this->movieCopy = movieCopy;
        this->rentedCopy = 0;
    }

    const int Movie::getID(){
        return this->movieId;
    }
    const int Movie::getNumOfCopies(){
        return this->movieCopy;
    }
    const int Movie::getRentedCopy(){
        return this->rentedCopy;
    }
    void Movie::setRentedCopy(int inc){
        this->rentedCopy = rentedCopy + inc;
    }