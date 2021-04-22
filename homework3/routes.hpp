#ifndef ROUTES_H
#define ROUTES_H

#include <iostream>
#include <vector>
using namespace std;

class Station{
public:
    Station(string stationName, string stationType, double stationX, double stationY) 
        : name(stationName)
        , vehicletype(stationType)
        , x(stationX)
        , y(stationY)
    {}
private:
    string name;
    string vehicletype;
    double x;
    double y;
};
class Route{
public:
    void AddStation(Station station){
        stations.push_back(station);
    }
private:
    vector<Station> stations;
};
#endif