//written by Zeynep Su Uçan
//22103044 - Section 3

#ifndef __MOVIENODE_H
#define __MOVIENODE_H
#include <string>
#include <iostream>
#include "Movie.h"
using namespace std;

class MovieNode {
    public:
    MovieNode(){
    }

    Movie movie;
    MovieNode* nextMovieNode = nullptr;
};
#endif