#include <iostream>
using namespace std;
#include "Trapezoid.h"

int main() {
	cout << "---Trapezoids created by coordinates---" << endl;

	Trapezoid tr(2, 5, 6, 5, 8, 1, 1, 1);
	cout << "Area of the trapezoid (area1): " << tr.area() << endl;
	cout << "Perimeter of the trapezoid: " << tr.perimeter() << endl;
	cout << "Points of this trapezoid: " << endl;
	cout << tr.apexA() << endl;
	cout << tr.apexB() << endl;
	cout << tr.apexC() << endl;
	cout << tr.apexD() << endl;
	cout << "Segments of this trapezoid: " << endl;
	cout << tr.side_ab() << endl;
	cout << tr.side_bc() << endl;
	cout << tr.side_cd() << endl;
	cout << tr.side_da() << endl;
	cout << "Heigth of this trapezoid: " << tr.height() << endl;

	Trapezoid tr1(3, 4, 4, 8, 8, 8, 10, 4);
	cout << "Area of the trapezoid (area2): " << tr1.area() << endl;
	cout << "Perimeter of the trapezoid: " << tr1.perimeter() << endl;
	cout << "Points of this trapezoid: " << endl;
	cout << tr1.apexA() << endl;
	cout << tr1.apexB() << endl;
	cout << tr1.apexC() << endl;
	cout << tr1.apexD() << endl;
	cout << "Segments of this trapezoid: " << endl;
	cout << tr1.side_ab() << endl;
	cout << tr1.side_bc() << endl;
	cout << tr1.side_cd() << endl;
	cout << tr1.side_da() << endl;
	cout << "Heigth of this trapezoid: " << tr1.height() << endl;

	cout << "Is these trapezoids same by area (area1 == area2): " << boolalpha << (tr == tr1); 
	cout << endl<< "Is these trapezoids not same by area (area1 == area2): " << boolalpha << (tr != tr1); 
	cout << endl << "Try to create wrong trapezoid by coordinates: " << endl;
	try {
		Trapezoid tr2(1, 5, 3, 4, 0, 5, 1, 9);
	}
	catch (Trapezoid::BadTrapezoid& d) {
		d.diagnose();
	}


	cout << endl << "---Trapezoids created by points---" << endl;
	Point a(1, 3);
	Point b(3, 6);
	Point c(9, 6);
	Point d(9, 3);
	Trapezoid tr2(a, b, c, d);
	cout << "Area of the trapezoid (area2): " << tr2.area() << endl;
	cout << "Perimeter of the trapezoid: " << tr2.perimeter() << endl;
	cout << "Points of this trapezoid: " << endl;
	cout << tr2.apexA() << endl;
	cout << tr2.apexB() << endl;
	cout << tr2.apexC() << endl;
	cout << tr2.apexD() << endl;
	cout << "Segments of this trapezoid: " << endl;
	cout << tr2.side_ab() << endl;
	cout << tr2.side_bc() << endl;
	cout << tr2.side_cd() << endl;
	cout << tr2.side_da() << endl;
	cout << "Heigth of this trapezoid: " << tr2.height() << endl;

	Point x(1, 9);
	Point y(5, 9);
	Point z(6, 0);
	Point w(0, 0);
	Trapezoid tr3(x, y, z, w);
	cout << "Area of the trapezoid (area2): " << tr3.area() << endl;
	cout << "Perimeter of the trapezoid: " << tr3.perimeter() << endl;
	cout << "Points of this trapezoid: " << endl;
	cout << tr3.apexA() << endl;
	cout << tr3.apexB() << endl;
	cout << tr3.apexC() << endl;
	cout << tr3.apexD() << endl;
	cout << "Segments of this trapezoid: " << endl;
	cout << tr3.side_ab() << endl;
	cout << tr3.side_bc() << endl;
	cout << tr3.side_cd() << endl;
	cout << tr3.side_da() << endl;
	cout << "Heigth of this trapezoid: " << tr3.height() << endl;

	cout << endl << "Try to crate wrong trapezoid by points: " << endl;
	Point p(3, 5);
	try {
		Trapezoid wtr(x, y, z, p);
	}
	catch (Trapezoid::BadTrapezoid& dw) {
		dw.diagnose();
	}

	cout << "Try to change one point to another: " << endl;
	try {
		tr3.set_c(p);
	}
	catch (Trapezoid::BadTrapezoid& dw) {
		dw.diagnose();
	}

	cout << endl << "---Trapezoids created by segments---" << endl;
	Segment ab(x, y);
	Segment bc(y, z);
	Segment cd(z, w);
	Segment da(w, x);
	Trapezoid tr4(ab, cd);
	cout << "Area of the trapezoid (area2): " << tr4.area() << endl;
	cout << "Perimeter of the trapezoid: " << tr4.perimeter() << endl;
	cout << "Points of this trapezoid: " << endl;
	cout << tr4.apexA() << endl;
	cout << tr4.apexB() << endl;
	cout << tr4.apexC() << endl;
	cout << tr4.apexD() << endl;
	cout << "Segments of this trapezoid: " << endl;
	cout << tr4.side_ab() << endl;
	cout << tr4.side_bc() << endl;
	cout << tr4.side_cd() << endl;
	cout << tr4.side_da() << endl;
	cout << "Heigth of this trapezoid: " << tr4.height() << endl;

	cout << "Is two last trapezoids same by area: " << boolalpha << (tr3 == tr4);
	cout << endl << "Is two last trapezoids not same by area: " << boolalpha << (tr3 != tr4);
	cout << endl << endl << "Try to create wrong trapezoid by segments: " << endl;
	Segment seg(8, 3);
	try {
		Trapezoid wTr(ab, seg);
	}
	catch (Trapezoid::BadTrapezoid& wd) {
		wd.diagnose();
	}

	return 0;
}