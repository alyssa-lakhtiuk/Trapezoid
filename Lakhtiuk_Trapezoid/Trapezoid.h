// 1. ��������� ��������� ���� �������� Trapezoid �� ������� ���������.
// 2. ���������� ��������� � ������������ ������ ��������.
// 3. ������ ������ ����� ��������.
// 4. ϳ��������� ����� � �������� ��������.���������� ��������� ��������� �������� �� �� �������.
#pragma once
#include "Point.h"
#include "Segment.h"

class Point;
class Segment;

class Trapezoid {
private :
	mutable Point _a, _b, _c, _d;
	mutable Segment* _ab, *_bc, *_cd, *_da;

public:
	class BadTrapezoid;
	//������������ 
	Trapezoid(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const double x4, const double y4);
	Trapezoid(const Point& a, const Point& b, const Point& c, const Point& d);
	Trapezoid(const Segment& ab, const Segment& dc);

	//����������
	~Trapezoid();

	//��������� ������
	const Point& apexA() const { return _a; };
	const Point& apexB() const { return _b; };
	const Point& apexC() const { return _c; };
	const Point& apexD() const { return _d; };

	//������������ ������
	void set_a(const Point& a);
	void set_b(const Point& a);
	void set_c(const Point& a);
	void set_d(const Point& a);

	//��������� �����
	const Segment& side_ab() const;
	const Segment& side_bc() const;
	const Segment& side_cd() const;
	const Segment& side_da() const;

	//�����
	double area();

	//��������
	double perimeter();

	bool operator==(Trapezoid& t);
	bool operator!=(Trapezoid& t);

	// ������
	double height();

};


//��������� �� ������
//bool operator==(Trapezoid& t1, Trapezoid& t2);


bool are_appropriate(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3,
	const double x4, const double y4);


ostream& operator<<(ostream&, const Trapezoid&);

class Trapezoid::BadTrapezoid
{
private:
	const string _reason;
public:
	BadTrapezoid(const string reason = "Error") :
		_reason(reason){}

	~BadTrapezoid() {}

	void diagnose() const
	{
		cerr << _reason << endl;
	}
};