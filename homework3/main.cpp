#include "routes.hpp"
#include "pugixml.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
using namespace pugi;

std::vector<std::string> split(const std::string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main() {
    map<string, map<string, Route>> routes;
    map<string, int> streets;

    xml_document doc;
    doc.load_file("tree.xml");
    ofstream out;
    out.open("output.txt");
    xml_node dataset = doc.child("dataset");
    for(xml_node stationNode = dataset.child("transport_station"); stationNode; stationNode = stationNode.next_sibling("transport_station")){
        string vehicleType = stationNode.child_value("type_of_vehicle");
        string stationRoutes = stationNode.child_value("routes");
        replace(stationRoutes.begin(), stationRoutes.end(), '.', ',');
        vector<string> routeNumbers = split(stationRoutes,',');
        string stationName = stationNode.child_value("name_stopping");
        string stationCoords = stationNode.child_value("coordinates");
        vector<string> coords = split(stationCoords, ',');
        for(size_t i = 0; i < routeNumbers.size(); i++){
            routes[vehicleType][routeNumbers[i]].AddStation(Station(stationName, vehicleType, atof(coords[0].c_str()), atof(coords[0].c_str())));
        }

        string stationLocation = stationNode.child_value("location");
        vector<string> stationStreets = split(stationLocation, ',');
        for (size_t i = 0; i < stationStreets.size(); i++)
            streets[stationStreets[i]]++;
    }

    //fixed range-based for with unpacking
    string transport;
    map<string, Route> routesoftype;
    for (auto&& [transport, routesoftype] : routes){
        string maxRoute = "";
        int maxRouteN = -1;
        string maxLengthRoute = "";
        double maxRouteLength = -1;
        string routename;
        Route route;
        for (auto&& [routename, route] : routesoftype) {
            int curN = route.getN();
            if (curN > maxRouteN) {
                maxRoute = routename;
                maxRouteN = curN;
            }
            route.sort();
            double curLength = route.length();
            if (curLength > maxRouteLength) {
                maxLengthRoute = routename;
                maxRouteLength = curLength;
            }
        }
        out << transport << "\n Most numerous route ¹ " << maxRoute << ", count: " << maxRouteN << "\n";
        out  << " Longest route ¹ " << maxLengthRoute << ", length: " << maxRouteLength << "\n";
    }


    string maxstreet = "";
    int count;
    string streetname;
    for (auto&& [streetname, count] : streets)
        if (count > streets[maxstreet])
            maxstreet = streetname;

    out << "Most numerous street " << maxstreet << ", count " << streets[maxstreet];

    out.close();
    return 0;
}
