//written by Zeynep Su Uçan 
//22103044

#ifndef CITY_H
#define CITY_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class City{
    public:
    City(){}
    City(string name){
        this->name = name;
        adjacentCityCount = 0;
    }
    ~City(){
    }
    void print() const {
        cout << name;
    }
    void printAd() const {
        cout << "heyZey" << endl;
        for(int i = 0; i < adjacentCityCount; i++){
            cout << "girdi mi    " ;
        }
    }
    void addAdj(City city){
        adjacentCities.push_back(city);
        adjacentCityCount++;
        cout << adjacentCityCount << endl;
    }
    string name;
    int adjacentCityCount;
    bool visited;
    vector<City> adjacentCities;
};
#endif