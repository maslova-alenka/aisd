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
	explicit Polyline(int capacity);

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

template<typename T>
Polyline<T>::Polyline(int capacity) : _capacity(capacity), _size(0) {
	_data = new Point<T>*[_capacity];
}

template<typename T>
Polyline<T>::Polyline(T x, T y) : _size(0) {
	_size++;
}

template<typename T>
Polyline<T>::Polyline(int size, T x0, T y0, T x1, T y1) : _size(size) {

}

template<typename T>
Polyline<T>::Polyline(const Polyline<T>& other) : Polyline(other._capacity) {

}

template<typename T>
int Polyline<T>::size() const { return _size; }

template<typename T>
int Polyline<T>::capacity() const { return _capacity; }

template<typename T>
Polyline<T>& Polyline<T>:: operator=(Polyline<T> other) {
	swap(other);
	return *this;
}

template<typename T>
Polyline<T>& Polyline<T>::operator+=(const Point<T>& p) {

}

template<typename T>
Polyline<T> Polyline<T>::operator+(const Point<T>& p) {

}

template<typename T>
const Point<T>& Polyline<T>::operator[](int index) const {
	if ((index < 0) && (index >= _size)) {
		throw std::out_of_range("Index out of range");
	}
	return *_data[index];
}

template<typename T>
Point<T>& Polyline<T>::operator[](int index) {
	if ((index < 0) && (index >= _size)) {
		throw std::out_of_range("Index out of range");
	}
	return *_data[index];
}

#endif