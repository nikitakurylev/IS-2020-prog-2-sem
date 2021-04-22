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
        for(int i = 0; i < routeNumbers.size(); i++){
            
        }
    }

    out.close();
    return 0;
}
