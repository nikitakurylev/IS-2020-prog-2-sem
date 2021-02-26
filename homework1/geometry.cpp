#include "geometry.h"
#include <math.h>

// S P A C E S - done
double distance(Point p1, Point p2) {
	return sqrt(pow(double(p2.getX()) - p1.getX(), 2) + pow(double(p2.getY()) - p1.getY(), 2));
}

PolygonalChain::PolygonalChain() {
	size = 0;
	points = new Point[1];
}

PolygonalChain::PolygonalChain(int numberOfPoints, Point* chainPoints) {
	size = numberOfPoints;
	points = new Point[numberOfPoints];
	for (int i = 0; i < numberOfPoints; i++)
		points[i] = chainPoints[i];
}

PolygonalChain::PolygonalChain(const PolygonalChain& obj) {
	size = obj.size;
	points = new Point[size];
	for (int i = 0; i < size; i++)
		points[i] = obj.points[i];
}

PolygonalChain::~PolygonalChain() {
	delete[] points;
}

double PolygonalChain::perimeter() const {
	double length = 0;
	for (int i = 1; i < size; i++) {
		length += distance(points[i - 1], points[i]);
	}
	return length;
}

double ClosedPolygonalChain::perimeter() const {
	double length = 0;
	for (int i = 1; i < size; i++) {
		length += distance(points[i - 1], points[i]);
	}
	return length + distance(points[0], points[size - 1]);
}

double Polygon::area() const {
	double polygonArea = 0;
	for (int i = 0; i < getN(); i++) {
		int j = (i + 1) % getN();
		polygonArea -= double(points[i].getX()) * points[j].getY();
		polygonArea += double(points[i].getY()) * points[j].getX();
	}
	polygonArea /= 2;
	return polygonArea;
}

bool Triangle::hasRightAngle() const {
	for (int i = 0; i < 3; i++) {
		Point v1 = points[(i + 1) % 3] - points[i];
		Point v2 = points[(i + 2) % 3] - points[i];
		if (v1.getX() * v2.getX() + v1.getY() * v2.getY() == 0)
			return true;
	}
	return false;
}
double Trapezoid::height() const {
	return area() / (distance(points[1], points[2]) + distance(points[3], points[0])) * 2;
}
//Regular Polygon area perimeter - done
double RegularPolygon::perimeter() const {
	return distance(points[0], points[1]) * getN();
}
double RegularPolygon::area() const {
	return pow(distance(points[0], points[1]), 2) * getN() / 4 / tan(3.14159265359 / getN());
}