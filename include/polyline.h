#ifndef POLYLINE_INCLUDE_POLYLINE_H
#define POLYLINE_INCLUDE_POLYLINE_H

#include <utility>
#include <stdexcept>


#include "point.h"
#include "rand.h"

const int growth = 5;

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

	const Point<T>& operator[](int index) const;
	Point<T>& operator[](int index);

	Polyline<T>& operator+=(const Polyline<T>& other);
	Polyline<T> operator+(const Polyline<T>& other);

	double length();

	void swap(Polyline<T>& other) noexcept;
	void push_back(const Point<T>& point);
	void push_front(const Point<T>& point);

	~Polyline();


};

template<typename T>
Polyline<T>::Polyline(int capacity) : _capacity(capacity), _size(0) {
	_data = new Point<T>*[_capacity];
}

template<typename T>
Polyline<T>::Polyline(T x, T y) : _size(0) {
	_capacity = growth;
	_data = new Point<T>*[_capacity]();
	_data[0] = new Point<T>(x, y);
	_size++;
}

template<typename T>
Polyline<T>::Polyline(int size, T x0, T y0, T x1, T y1) : _size(size) {
	_capacity = _size + growth;
	_data = new Point<T>*[_capacity]();
	for (int i = 0; i < _size; ++i) {
		_data[i] = new Point<T>(Random(x0, x1), Random(y0, y1));
	}
}

template<typename T>
Polyline<T>::Polyline(const Polyline<T>& other) : Polyline(other._capacity) {
	_size = other._size;
	for (int i = 0; i < _size; ++i) {
		_data[i] = new Point<T>(*other._data[i]);
	}
}

template<typename T>
int Polyline<T>::size() const { 
	return _size; 
}

template<typename T>
int Polyline<T>::capacity() const {
	return _capacity; 
}

template<typename T>
Polyline<T>& Polyline<T>:: operator=(Polyline<T> other) {
	swap(other);
	return *this;
}

template<typename T>
Polyline<T>& Polyline<T>::operator+=(const Point<T>& p) {
	if (_size >= _capacity) {
		_capacity += growth;
		Point<T>** tmp = new Point<T>*[_capacity]();

		for (int i = 0; i < _size; ++i) {
			tmp[i] = _data[i];
		}

		delete[] _data;
		_data = tmp;
	}
	_data[_size] = new Point<T>(p);
	_size++;
	
	return *this;

}

template<typename T>
Polyline<T> Polyline<T>::operator+(const Point<T>& p) {
	Polyline<T> add_res(*this);
	add_res += p;
	return add_res;

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

template<typename T>
Polyline<T>& Polyline<T> :: operator+=(const Polyline<T>& other) {
	if (_size + other._size > _capacity) {
		_capacity = _size + other._size + growth;
		Point<T>** tmp = new Point<T>*[_capacity]();

		for (int i = 0; i < _size; ++i) {
			tmp[i] = _data[i];
		}

		delete[] _data;
		_data = tmp;
	}

	for (int i = 0; i < other._size; ++i) {
		*this += *other._data[i];
	}

	return *this;

}

template<typename T>
Polyline<T> Polyline<T>:: operator+(const Polyline<T>& other) {
	Polyline<T> add_res(*this);
	add_res += other;
	return add_res;
}

template<typename T>
double Polyline<T>::length() {
	double len = 0;
	for (int i = 0; i < _size-1; ++i) {
		len += (*_data[i]).distance(*_data[i + 1]);
	}
	return len;

}

template<typename T>
void Polyline<T>:: swap(Polyline<T>& other) noexcept {
	std::swap(_data, other._data);
	std::swap(_size, other._size);
	std::swap(_capacity, other._capacity);
}



template<typename T>
void Polyline<T>::push_back(const Point<T>& point) {
	if (_size >= _capacity) {
		_capacity += growth;
		Point<T>** tmp = new Point<T>*[_capacity]();

		for (int i = 0; i < _size; ++i) {
			tmp[i] = _data[i];
		}

		delete[] _data;
		_data = tmp;
	}

	_data[_size] = new Point<T>(point);
	_size++;
}

template<typename T>
void Polyline<T>::push_front(const Point<T>& point) {
	if (_size >= _capacity) {
		_capacity += growth;
		Point<T>** tmp = new Point<T>*[_capacity]();

		for (int i = 0; i < _size; ++i) {
			tmp[i] = _data[i];
		}

		delete[] _data;
		_data = tmp;
	}

	Point<T>** tmp = new Point<T>*[_capacity]();


	for (int i = 0; i < _size; ++i) {
		tmp[i + 1] = _data[i];
	}
	tmp[0] = new Point<T>(point);

	delete[] _data;
	_data = tmp;
	++_size;
}

template<typename T>
Polyline<T>::~Polyline() {
	if (_data != nullptr) {
		for (int i = 0; i < _size; ++i) {
			delete _data[i];
		}
		_size = 0;
		_capacity = 0;
		delete[] _data;
		_data = nullptr;
	}
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const Polyline<T>& line) {
	stream << "[ ";
	for (int i = 0; i < line.size(); ++i) {
		if (i == (line.size() - 1)) {
			stream << line[i];
		}
		else {
			stream << line[i] << ", ";
		}
	}
	stream << " ]";
	return stream;
}

template <typename T>
bool operator==(const Polyline<T>& line1, const Polyline<T>& line2) {
	if (line1.size() != line2.size()) {
		throw std::runtime_error("Different number of vertices");
	}

	bool be_eq = true;
	for (int i = 0; i < line1.size(); ++i) {
		if (line1[i] != line2[i]) {
			be_eq = false;
		}
	}

	bool be_eq_reverse = true;
	for (int i = 0; i < line1.size(); ++i) {
		if (line1[i] != line2[line1.size() - i - 1]) {
			be_eq_reverse = false;
		}
	}

	return (be_eq|| be_eq_reverse);
}

template<typename T>
bool operator!=(const Polyline<T>& line1, const Polyline<T>& line2) {
	return (!(line1 == line2));
}

#endif