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

    map<string, map<int, Route>> routes;
    map<string, int> streets;

    xml_document doc;
    xml_parse_result result = doc.load_file("tree.xml");
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
        for(int i = 0; i < routeNumbers.size(); i++){
            int number = atoi(routeNumbers[i].c_str());
            routes[vehicleType][number].AddStation(Station(stationName, vehicleType, atof(coords[0].c_str()), atof(coords[0].c_str())));
        }

        string stationLocation = stationNode.child_value("location");
        vector<string> stationStreets = split(stationLocation, ',');
        for (int i = 0; i < stationStreets.size(); i++)
            streets[stationStreets[i]]++;
    }

    string maxstreet = "";
    for (std::map<string, int>::const_iterator it = streets.begin(); it != streets.end(); ++it)
        if (it->second > streets[maxstreet])
            maxstreet = it->first;

    out << maxstreet << " " << streets[maxstreet];

    out.close();
    return 0;
}