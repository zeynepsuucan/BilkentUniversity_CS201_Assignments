//written by Zeynep Su Uçan 
//22103044

#include "FlightMap.h"

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

FlightMap::FlightMap(const string cityFile, const string flightFile)
{
    ifstream cityInput;
    ifstream flightInput;
    string cityFileName = cityFile;
    string flightFileName = flightFile;

    cityInput.open(cityFileName.c_str(), ios_base::in);
    flightInput.open(flightFileName.c_str(), ios_base::in);

    if (cityInput && flightInput)
    {

        while (cityInput.eof() == false)
        {
            string cityName;
            getline(cityInput, cityName);
            cityNum++;
            City add = City(cityName);
            cities.push_back(add);
            sort(cities.begin(), cities.end(), SortCity());
        }

        while (flightInput.eof() == false)
        {
            string origin;
            string des;
            int id;
            int cost;
            char semi;
            string flightStr;
            getline(flightInput, flightStr, '\n');
            if (flightStr[flightStr.size() - 1] == '\r')
                flightStr.resize(flightStr.size() - 1);
            string value;
            stringstream linestream(flightStr);

            getline(linestream, value, ';');
            origin = value;

            getline(linestream, value, ';');
            des = value;

            getline(linestream, value, ';');
            id = atoi(value.c_str());

            getline(linestream, value, ';');
            cost = atoi(value.c_str());

            flightNum++;
            City originCity;
            City desCity;
            for (City &city : cities)
            {
                if (city.name == origin)
                {
                    originCity = city;
                }
                if (city.name == des)
                {
                    desCity = city;
                }
            }
            Flight add = Flight(originCity, desCity, id, cost);
            flights.push_back(add);
            for (City &city : cities)
            {
                if (city.name == origin)
                {
                    city.adjacentCities.push_back(desCity);
                }
                sort(city.adjacentCities.begin(), city.adjacentCities.end(), SortCity());
            }
        }
    }

    cityInput.close();
    flightInput.close();

    cout << cityNum << " cities and " << flightNum << " have been loaded." << endl;
}
FlightMap::~FlightMap()
{
}
void FlightMap::displayAllCities() const
{
    cout << "The list of the cities that HPAir serves is given below:" << endl;
    for (const City &city : cities)
    {
        city.print();
        cout << ", ";
    }
    cout << endl;
}

void FlightMap::displayAdjacentCities(const string cityName) const
{
    cout << "The cities adjacent to " << cityName << " are:" << endl;
    cout << cityName << "->";
    for (const City &city : cities)
    {
        if (city.name == cityName)
            for (const City &city2 : city.adjacentCities)
            {
                city2.print();
                cout << ", ";
            }
    }
    cout << endl;
}
void FlightMap::displayFlightMap() const
{
    cout << "The whole flight map is given below:" << endl;
    for (const City &city : cities)
    {
        city.print();
        cout << " -> ";
        for (const City &city2 : city.adjacentCities)
        {
            city2.print();
            cout << ", ";
        }
        cout << endl;
    }
    return;
}

void FlightMap::findFlights(const string deptCity, const string destCity)
{
    cout << "Request is to fly from " << deptCity << " to " << destCity << ": " << endl; 

    // stack<City> cityStack;
    // unvisitAll();
    // City origin = City(deptCity);
    // cityStack.push(origin);
    // markVisited(origin);
    // stack<Flight> flightst;
    // int cost = 0;
    
    // City topCity = cityStack.top();
    
    // while(!cityStack.empty()){
        
    //     if(topCity.name == destCity){
    //         results.push_back(cityStack);
    //     }
    //     else{
    //         bool found = false;
    //         for(Flight& flight : flights){
    //             bool check;
    //             for(City& city : cities){
    //                 if(city.name == flight.destination.name){
    //                     check = city.visited;
    //                 }
    //             }
    //             if(flight.origin.name == topCity.name && !check){
    //                 cityStack.push(flight.destination);
    //                 flight.destination.visited = true;
    //                 found = true;
    //                 break;

    //             }
    //         }
    //         if(!found){
    //             cityStack.pop();
    //             topCity.visited = false;
    //         }
    //     }
    // }

    //         }
    //     City nextCity = getNextCity(topCity);
    //     //cout << nextCity.name << endl;

    //     if(nextCity.name == "none"){
    //         cityStack.pop();
    //     }
    //     else{
    //         cityStack.push(nextCity);
    //         markVisited(nextCity);
    //     }
    //     if (!cityStack.empty())
    //     topCity = cityStack.top();
    // }
    // if(cityStack.top().name==destCity){
    //     results.push_back(cityStack);
    // }
    // for(int i = 0; i < cityStack.size(); i++){
    //     cout << cityStack.top().name << endl;
    //     cityStack.pop();
    // }
}

void FlightMap::markVisited(City city1)
{
    for (City &city : cities)
    {
        if (city.name == city1.name)
        {
            city.visited = true;
        }
    }
}

void FlightMap::unvisitAll()
{
    for (City &city : cities)
    {
        city.visited = false;
    }
}

bool FlightMap::isVisited(City city1)
{
    for (City &city : cities)
    {
        if (city.name == city1.name)
        {
            return city.visited;
        }
    }
}

City FlightMap::getNextCity(City fromCity)
{
    for (City &city : cities)
    {
        if (city.name == fromCity.name)
        {
            for (City &city2 : city.adjacentCities)
            {
                if (!isVisited(city2))
                {
                    return city2;
                }
            }
        }
    }
    return City("none");
}

// bool FlightMap::Zeysu(string origin, string dest)
// {
//     City originC = City(origin);
//     City destC = City(dest);
//     stack<City> cityStack;

//     unvisitAll();
//     cityStack.push(originC);
//     markVisited(originC);
//     City topCity = cityStack.top();
//     cout << cityStack.empty();
//     cout << (topCity.name != destC.name) << endl;
//     // while (!cityStack.empty() && (topCity.name != destC.name))
//     // {
//     //     City nextCity = getNextCity(topCity);
//     //     if (nextCity.name == "none")
//     //         cityStack.pop(); // No city found; backtrack
//     //     else                 // Visit city {
//     //         cityStack.push(nextCity);
//     //     markVisited(nextCity);
        
//     //     if (!cityStack.empty())
//     //         topCity = cityStack.top();
//     // } 
//     // bool res = cityStack.empty();
//     return true;
// }
