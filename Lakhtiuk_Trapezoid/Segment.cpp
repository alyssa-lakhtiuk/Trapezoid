#include <cmath>
#include <iostream>

#include "Segment.h"

int Segment::_freeID = 0;

Segment::Segment(const double x1, const double y1, const double x2, const double y2) :
	_myId(++_freeID), _a(x1, y1), _b(x2, y2) {

}

Segment::Segment(const Point& start, const Point& end) : _myId(++_freeID), _a(start), _b(end) {

}


Segment::Segment(const Segment& p) : _myId(++_freeID), _a(p.start()), _b(p.end()) {

}

Segment::~Segment() {

}

Segment& Segment :: operator=(const Segment& p) {
	_a = p.start();
	_b = p.end();
	return *this;
}

const Point& Segment::start() const {
	return _a;
}

const Point& Segment::end() const {
	return _b;
}

Point& Segment::start() {
	return _a;
}

Point& Segment::end() {
	return _b;
}

const double& Segment::startX() const {
	return _a.x();
}

const double& Segment::startY() const {
	return start().y();
}

const double& Segment::endX() const {
	return end().x();
}

const double& Segment::endY() const {
	return _b.y();
}

double& Segment::startX() {
	return _a.x();
}

double& Segment::startY() {
	return _a.y();
}

double& Segment::endX() {
	return _b.x();
}

double& Segment::endY() {
	return _b.y();
}

double Segment::length() const {
	return sqrt(pow((endX() - startX()), 2) + pow((endY() - startY()), 2));
}

double Segment::distance(const Point& o) const {
	// отримаємо рівняння прямої з (x - x1)/(x2 - x1) = (y - y1)/(y2 - y1)
	// тоді підставимо у формулу знаходження відстані |Ax3 + By3 + C| / ((A^2 + B^2) ^1/2), 
	// де x3 та y3 координати точки, відстань до якої треба знайти
	const double numerator = abs((end().y() - start().y()) * o.x() + (start().x() - end().x()) * o.y() + (start().y() * end().x() - start().x() * end().y()));
	return numerator / sqrt(pow(end().y() - start().y(), 2) + pow(start().x() - end().x(), 2));
}


const int Segment::getID() const {
	return _myId;
}

ostream& operator<<(ostream& os, const Segment& p) {
	os << "Segment " << p.getID() << ": " << "{(" << p.startX() << ", " << p.startY() << ") , (" << p.endX() << ", " << p.endY() << ")}";
	return os;
}