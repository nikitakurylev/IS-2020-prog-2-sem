#include "routes.hpp"
#include <math.h>
double Route::length() const {
    double result = 0;
    for (int i = 0; i < stations.size() - 1; i++)
        result += sqrt(pow(stations[i + 1].GetX() - stations[i].GetX(), 2) + pow(stations[i + 1].GetY() - stations[i].GetY(), 2));
    return result;
}