#define _USE_MATH_DEFINES
#include<cmath>

#include "../include/polyline.h"



int main() {

	double angle = 60.0; // ”гол в градусах
	double length = 5.0; 



	Polyline<double> triangle(3);


	Point<double> point1(0, 0);
	Point<double> point2(length, 0);
	Point<double> point3(length / 2.0, length/2.0 * 1/(std::tan(angle/2.0  * M_PI / 180.0)));


	triangle += point1;
	triangle += point3;
	triangle += point2;
	triangle += point1;


	std::cout << "Size: " << triangle.size() << std::endl;
	std::cout << triangle << std::endl;

	std::cout << "Length of triangle: " << triangle.length() << std::endl;


	return 0;


}

