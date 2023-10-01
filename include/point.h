#ifndef TESTLABC_INCLUDE_POINT_H
#define TESTLABC_INCLUDE_POINT_H


#include <iostream>
#include <cmath>
#include <complex>

template<typename T>
struct Point {
	T x, y;

	Point() : x(0), y(0) {}
	Point(T x1, T y1) : x(x1), y(y1) {}

	Point(const Point<T>& point) : x(point.x), y(point.y) {}

	float distance(const Point<T>& point) {
		return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
	}

	Point <T>& operator=(const Point<T>& other) {
		x = other.x;
		y = other.y;
		return *this;
	}
};

template<typename U>
struct Point<std::complex<U>> {
	float x, y;

	Point() : x(0), y(0) {}

	Point(std::complex<U> point) : x(point.real()), y(point.imag()) {};

	Point < std::complex<U>& operator=(const Point<std::complex<U>> other) {
		x = other.x;
		y = other.y;
		return *this;
	}

	double distance(const Point < std::complex<U>>& point) {
		return sqrt(pow(point.x - x, 2) + pow(point.y - y, 2));
	}

	double len() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

};

template<typename T>
std::ostream& operator<<(ostream& stream, const Point<T>& point) {
	stream << "(" << point.x << ";" << point.y << ")" << endl;
	return stream;
}






#endif