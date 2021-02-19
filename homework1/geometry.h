#ifndef GEOMETRY_H
#define GEOMETRY_H
class Point {
public:
	Point(int positionX = 0.0, int positionY = 0.0)
		: x(positionX)
		, y(positionY)
	{}
	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}
	Point operator - (Point const& obj) {
		return Point(getX()-obj.getX(), getY()-obj.getY());
	}
private:
	int x;
	int y;
};

double distance(Point p1, Point p2);

//we need destructor
class PolygonalChain {
public:
	PolygonalChain();
	PolygonalChain(int numberOfPoints, Point* chainPoints);
	double perimeter() const;
	int getN() const {
		return size;
	}
	Point getPoint(int index) const {
		return points[index];
	}
protected:
	int size;
	Point* points;
};
Point* addPoint(Point* points, int size, Point point);
class ClosedPolygonalChain : public PolygonalChain {
public:
	ClosedPolygonalChain(int numberOfPoints, Point* closedChainPoints) : PolygonalChain(numberOfPoints+1, addPoint(closedChainPoints,numberOfPoints, closedChainPoints[0])) {}
	int getN() const {
		return size-1;
	}
};
class Polygon : public ClosedPolygonalChain {
public:
	Polygon(int numberOfPoints, Point* polygonPoints) : ClosedPolygonalChain(numberOfPoints, polygonPoints) {}
	double area() const;
};
class Triangle : public Polygon {
public:
	Triangle (int numberOfPoints, Point* trianglePoints) : Polygon(numberOfPoints, trianglePoints){}
	bool hasRightAngle() const;
};
class Trapezoid : public Polygon {
public:
	Trapezoid(int numberOfPoints, Point* trapezoidPoints) : Polygon(numberOfPoints, trapezoidPoints) {}
	double height() const;
};
class RegularPolygon : public Polygon {
public:
	RegularPolygon(int numberOfPoints, Point* regularPolygonPoints) : Polygon(numberOfPoints, regularPolygonPoints){}
};

#endif