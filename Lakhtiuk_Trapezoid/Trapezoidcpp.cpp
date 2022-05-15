#include "Trapezoid.h"
#include <iostream>
#include <cmath>

//
// Trapezoid ABCD with parallel sides (AB || DC) OR (BC || AD)
//
Trapezoid::Trapezoid(const double x1, const double y1, 
	const double x2, const double y2, 
	const double x3, const double y3, 
	const double x4, const double y4) : 
	_ab(nullptr), _bc(nullptr), _cd(nullptr), _da(nullptr)
{
	if (are_appropriate(x1, y1, x2, y2, x3, y3, x4, y4)) {	
		_a.x() = x1;
		_a.y() = y1;
		_b.x() = x2;
		_b.y() = y2;
		_c.x() = x3;
		_c.y() = y3;
		_d.x() = x4;
		_d.y() = y4;
	}
	else if (are_appropriate(x1, y1, x4, y4, x3, y3, x2, y2)) {
		_a.x() = x1;
		_a.y() = y1;
		_b.x() = x4;
		_b.y() = y4;
		_c.x() = x3;
		_c.y() = y3;
		_d.x() = x2;
		_d.y() = y2;
	}
	else {
		throw BadTrapezoid("Points with these coordinates are not on the parallel lines");
	}
#ifndef NDEBUG
	cout << endl << "Trapezoid created " << *this << endl;
#endif
}

Trapezoid::Trapezoid(const Point& a, const Point& b, const Point& c, const Point& d) : 
	_ab(nullptr), _bc(nullptr), _cd(nullptr), _da(nullptr) {
	if (are_appropriate(a.x(), a.y(), b.x(), b.y(), c.x(), c.y(), d.x(), d.y())) {
		_a = a;
		_b = b;
		_c = c; 
		_d = d;
	}
	else if (are_appropriate(a.x(), a.y(), d.x(), d.y(), b.x(), b.y(), c.x(), c.y())) {
		_a = a;
		_b = d;
		_c = c;
		_d = b;
	}
	else {
		throw BadTrapezoid("Points with these coordinates are not on the parallel lines");
	}
#ifndef NDEBUG
	cout << endl << "Trapezoid created " << *this << endl;
#endif
}

Trapezoid::Trapezoid(const Segment& ab, const Segment& dc) : 
	_ab(nullptr), _bc(nullptr), _cd(nullptr), _da(nullptr) {
	if (are_appropriate(ab.startX(), ab.startY(), ab.endX(), ab.endY(), dc.startX(), dc.startY(), dc.endX(), dc.endY())) {
		_a = ab.start();
		_b = ab.end();
		_c = dc.start();
		_d = dc.end();
	}
	else if (are_appropriate(ab.startX(), ab.startY(), dc.startX(), dc.startY(), ab.endX(), ab.endY(), dc.endX(), dc.endY())) {
		_a = ab.start();
		_b = dc.start();
		_c = dc.end();
		_d = dc.end();
	}
	else {
		throw BadTrapezoid("Points with these coordinates are not on the parallel lines");
	}
#ifndef NDEBUG
	cout << endl << "Trapezoid created " << *this << endl;
#endif
}

// чи паралельні прямі, що прохоять через точкти з координатами (х1, у1), (х2, у2) та (х3, у3), (х4, у4) відповіно 
bool are_appropriate(const double x1, const double y1, 
	const double x2, const double y2, 
	const double x3, const double y3,
	const double x4, const double y4) {
	return fabs((y1 - y2) / (x2 - x1)) == fabs((y3 - y4) / (x4 - x3));
}

// чи паралельні прямі, що прохоять через точкти a, b та c, d відповіно 
bool are_appropriate(const Point& a, const Point& b, const Point& c, const Point& d) {
	return fabs((a.y() - b.y()) / (b.y() - a.y())) == fabs((c.y() - d.y()) / (d.y() - c.y()));
}

Trapezoid::~Trapezoid() {
	delete _ab;
	delete _bc;
	delete _cd;
	delete _da;
	_ab = nullptr;
	_bc = nullptr;
	_cd = nullptr;
	_da = nullptr;
}

const Segment& Trapezoid::side_ab() const {
	if (!_ab) {
		_ab = new Segment(_a, _b);
	}
	return *_ab;
}

const Segment& Trapezoid::side_bc() const {
	if (!_bc) {
		_bc = new Segment(_b, _c);
	}
	return *_bc;
}

const Segment& Trapezoid::side_cd() const {
	if (!_cd) {
		_cd = new Segment(_c, _d);
	}
	return *_cd;
}

const Segment& Trapezoid::side_da() const {
	if (!_da) {
		_da = new Segment(_d, _a);
	}
	return *_da;
}

double Trapezoid::perimeter() {
	return side_ab().length() + side_bc().length() + side_cd().length() + side_da().length();
}

//bool operator==(Trapezoid& t1, Trapezoid& t2) {
//	return t1.area() == t2.area();
//}

bool Trapezoid::operator==(Trapezoid& t) {
	return (*this).area() == t.area();
}

bool Trapezoid::operator!=(Trapezoid& t) {
	return !((*this).area() == t.area());
}

double Trapezoid::area() {
	double area;
	if (are_appropriate(_a.x(), _a.y(), _b.x(), _b.y(), _c.x(), _c.y(), _d.x(), _d.y())) // means ab || cd
	{
		area = (side_ab().length() + side_cd().length()) * 0.5 * height();
	}
	else {
		area = (side_bc().length() + side_da().length()) * 0.5 * height();
	}
	return area;
}


double Trapezoid::height() {
	double ab = side_ab().length();
	double bc = side_bc().length();
	double cd = side_cd().length();
	double da = side_da().length();
	if (are_appropriate(_a.x(), _a.y(), _b.x(), _b.y(), _c.x(), _c.y(), _d.x(), _d.y())) {
		// ab || cd
		if ( da > bc) return sqrt(   fabs( pow(da, 2) - pow(((pow(cd - ab, 2) + pow(da, 2) - pow(bc, 2)) / 2 / fabs(ab - cd)), 2) )  );
		return sqrt(fabs(pow(bc, 2) - pow(((pow(cd - ab, 2) + pow(bc, 2) - pow(da, 2)) / 2 / fabs(ab - cd)), 2)));
	}
	else {
		// bc || da
		if (cd > ab) return sqrt(  fabs( pow(cd, 2) - pow(((pow(bc - da, 2) + pow(cd, 2) - pow(ab, 2)) / 2 / fabs(bc - da)), 2) )  );
		return sqrt(fabs(pow(ab, 2) - pow(((pow(bc - da, 2) + pow(ab, 2) - pow(cd, 2)) / 2 / fabs(bc - da)), 2)));
	}
}



ostream& operator<<(ostream& os, const Trapezoid& tr) {
	os << "ABCD: A(" << tr.apexA().x() << ", " << tr.apexA().y() << 
		") B(" << tr.apexB().x() << ", " << tr.apexB().y() << 
		") C(" << tr.apexC().x() << ", " << tr.apexC().y() << 
		") D(" << tr.apexD().x() << ", " << tr.apexD().y() << endl;
	return os;
}



void Trapezoid::set_a(const Point& a) {
	if (are_appropriate(a, _b, _c, _d)) {
		throw BadTrapezoid("Wrong point");
	}
	_a = a;
}


void Trapezoid::set_b(const Point& b) {
	if (are_appropriate(_a, b, _c, _d)) {
		throw BadTrapezoid("Wrong point");
	}
	_b = b;
}


void Trapezoid::set_c(const Point& c) {
	if (!are_appropriate(_a, _b, c, _d)) {
		throw BadTrapezoid("Wrong point");
	}
	_c = c;
}


void Trapezoid::set_d(const Point& d) {
	if (!are_appropriate(_a, _b, _c, d)) {
		throw BadTrapezoid("Wrong point");
	} 
	_d = d;
}