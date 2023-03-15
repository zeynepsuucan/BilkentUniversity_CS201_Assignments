//written by Zeynep Su Uçan 
//22103044

#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "City.h"
#include "Flight.h"

using namespace std;

class FlightMap {
public:
    int cityNum = 0;
    int flightNum = 0;
    vector<City> cities;
    vector<Flight> flights;
    vector<stack<City>> results;
    FlightMap( const string cityFile, const string flightFile );
    FlightMap(){}
    ~FlightMap();
void displayAllCities() const;
void displayAdjacentCities( const string cityName ) const;
void displayFlightMap() const;
void findFlights( const string deptCity, const string destCity );
void markVisited(City city);
void unvisitAll();
bool isVisited(City city);
City getNextCity(City fromCity);
// bool Zeysu(string origin, string dest);

struct SortCity
{
    bool operator()(const City lhs, const City rhs) const
    {
        return lhs.name < rhs.name;
    }
};
};
#endif