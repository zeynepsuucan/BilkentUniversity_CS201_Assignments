//written by Zeynep Su Uçan 
//22103044

#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include "City.h"

using namespace std;

class Flight{
    public:

    City origin;
    City destination;
    int id;
    int cost;
    Flight(){}
    Flight(City origin, City dest, int id, int cost){
        this->origin = origin;
        this->cost = cost;
        this->id = id;
        this->destination = dest;
    }
    ~Flight(){
    }

    void print() const {
        origin.print();
        cout << " " ;
        destination.print();
        cout << " " ;
        cout << id << " " << cost << endl;
    }
    
    
    
    
};
#endif