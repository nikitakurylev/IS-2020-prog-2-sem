#include "routes.hpp"
#include <algorithm>
#include <math.h>
void Route::sort() {   
	//fixed const&
    std::sort(stations.begin(), stations.end(), [](const Station& a, const Station& b) {
        return a.getX() * a.getX() + a.getY() * a.getY() < b.getX() * b.getX() + b.getY() * b.getY();
        });
}
double Route::length() const {
    double result = 0;
    for (size_t i = 0; i < stations.size() - 1; i++)
        result += sqrt(pow(stations[i + 1].getX() - stations[i].getX(), 2) + pow(stations[i + 1].getY() - stations[i].getY(), 2));
    return result;
}