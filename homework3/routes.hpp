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
    double GetX() const {
        return x;
    }
    double GetY() const {
        return y;
    }
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
    int GetN() const {
        return stations.size();
    }
    void sort();
    double length() const;
private:
    vector<Station> stations;
};
#endif