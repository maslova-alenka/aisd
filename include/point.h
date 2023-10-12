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

template<typename T>
bool operator==(const Point<T>& point1, const Point<T>& point2) {
	const double = k_epsilon = 1.0E-5;
	if ((std::abs(point1.x - point2.x) <= k_epsilon) && (std::abs(point1.y - point2.y) <= k_epsilon)) {
		return true;
	}
	return false;
}

template<>
bool operator==(const Point<T>& point1, const Point<T>& point2) {
	if ((point1.x == point2.x) && (point1.y == point2.y)) {
		return true;
	}
	return false;
}

template<typename T>
bool operator!=(const Point<T>& point1, const Point<T>& point2) {
	return(!(point1 == point2));
}

#endif