//written by Zeynep Su Uçan
//22103044 - Section 3

#ifndef __SUBSMOVIES_H
#define __SUBSMOVIES_H
#include <string>
#include <iostream>
#include "Movie.h"
using namespace std;

class MovieNodeSub {
    public:
    MovieNodeSub(){
    }
    Movie movie;
    bool status = true;
    MovieNodeSub* nextMovie = nullptr;
};

#endif