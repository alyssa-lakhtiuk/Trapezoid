#include "Point.h"

int Point::_freeID = 0;

Point::Point(double x, double y) : _pointID(++_freeID), _x(x), _y(y) {

}

Point::Point(const Point& u) : _pointID(++_freeID), _x(u._x), _y(u._y) {

}

Point::~Point() {
	return;
}

Point& Point::operator=(const Point& u) {
	_x = u.x();
	_y = u.y();
	return *this;
}


double& Point::x() {
	return _x;
}

double& Point::y() {
	return _y;
}

const double& Point::x()const {
	return _x;
}

const double& Point::y()const {
	return _y;
}

const int Point::getID() const {
	return _pointID;
}

ostream& operator<<(ostream& os, const Point& u) {
	os << "Point " << "(" << u.x() << ", " << u.y() << ")";
	return os;
}

const Point operator+ (const Point& u, const Point& v) {
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& operator+=(Point& u, const Point& v) {
	u.x() += v.x();
	u.y() += v.y();
	return u;
}

bool operator==(const Point& u, const Point& v) {
	return (u.x() == v.x() && u.y() == v.y());
}

bool operator!=(const Point& u, const Point& v) {
	return !(u.x() == v.x() && u.y() == v.y());
}
