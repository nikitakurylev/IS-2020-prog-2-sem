#include "routes.hpp"
#include <algorithm>
#include <math.h>
void Route::sort() {   
    std::sort(stations.begin(), stations.end(), [](Station a, Station b) {
        return a.GetX() * a.GetX() + a.GetY() * a.GetY() < b.GetX() * b.GetX() + b.GetY() * b.GetY();
        });
}
double Route::length() const {
    double result = 0;
    for (size_t i = 0; i < stations.size() - 1; i++)
        result += sqrt(pow(stations[i + 1].GetX() - stations[i].GetX(), 2) + pow(stations[i + 1].GetY() - stations[i].GetY(), 2));
    return result;
}