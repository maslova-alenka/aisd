#ifndef TESTLABC_INCLUDE_POINT_H
#define TESTLABC_INCLUDE_POINT_H

#include <utility>
#include <stdexcept>

#include "point.h"

template<typename T>
class Polyline {
	Point<T>** _data;
	int _size, _capacity;
public:
	Polyline(T x, T y);
	Polyline(int size, T x0, T y0, T x1, T y1);
	Polyline(const Polyline<T>& other);

	int size() const;
	int capacity() const;

	Polyline<T>& operator=(Polyline<T> other);
	Polyline<T>& operator+=(const Point<T>& p);
	Polyline<T> operator+(const Point<T>& p);

	const Point<T> operator[](int index) const;
	Point<T> operator[](int index);

	Polyline<T>& operator+=(const Polyline<T>& other);
	Polyline<T> operator+(const Polyline<T>& other);

	double length();

	~Polyline();


};

#endif