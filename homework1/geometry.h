#ifndef GEOMETRY_H
#define GEOMETRY_H
class Point {
public:
	Point(int positionX = 0, int positionY = 0)
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
		return Point(getX() - obj.getX(), getY() - obj.getY());
	}
private:
	int x;
	int y;
};

double distance(Point p1, Point p2);

//fixed we need destructor
class PolygonalChain {
public:
	PolygonalChain();
	//fixed operator=
	PolygonalChain(int numberOfPoints, Point* chainPoints);
	PolygonalChain(const PolygonalChain& obj);
	virtual PolygonalChain& operator= (const PolygonalChain& obj);
	virtual ~PolygonalChain();
	virtual double perimeter() const;
	int getN() const {
		return size;
	}
	Point getPoint(int index) const {
		return points[index];
	}
private:
	void Build(int numberOfPoints, Point* chainPoints);
protected:
	int size;
	Point* points;
};

class ClosedPolygonalChain : public PolygonalChain {
public:
	ClosedPolygonalChain(int numberOfPoints, Point* closedChainPoints) : PolygonalChain(numberOfPoints, closedChainPoints) {}
	virtual ClosedPolygonalChain& operator= (const ClosedPolygonalChain& obj) = default;
	double perimeter() const override;
};
class Polygon : public ClosedPolygonalChain {
public:
	Polygon(int numberOfPoints, Point* polygonPoints) : ClosedPolygonalChain(numberOfPoints, polygonPoints) {}
	virtual Polygon& operator= (const Polygon& obj) = default;
	double area() const;
};
class Triangle : public Polygon {
public:
	Triangle(int numberOfPoints, Point* trianglePoints) : Polygon(numberOfPoints, trianglePoints) {}
	virtual Triangle& operator= (const Triangle& obj) = default;
	bool hasRightAngle() const;
};
class Trapezoid : public Polygon {
public:
	Trapezoid(int numberOfPoints, Point* trapezoidPoints) : Polygon(numberOfPoints, trapezoidPoints) {}
	virtual Trapezoid& operator= (const Trapezoid& obj) = default;
	double height() const;
};
class RegularPolygon : public Polygon {
public:
	RegularPolygon(int numberOfPoints, Point* regularPolygonPoints) : Polygon(numberOfPoints, regularPolygonPoints) {}
	virtual RegularPolygon& operator= (const RegularPolygon& obj) = default;
	double perimeter() const;
	double area() const;
};

#endif