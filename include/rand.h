#ifndef POLYLINE_INCLUDE_RANDOM_H
#define POLYLINE_INCLUDE_RANDOM_H

#include <random>

int Random(int a, int b) {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(a, b);
	int res = distribution(generator);
	return res;
}

float Random(float a, float b) {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_real_distribution<float> distribution(a, b);
	float res = distribution(generator);
	return res;
}

double Random(double a, double b) {
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_real_distribution<double> distribution(a, b);
	double res = static_cast<double>(distribution(generator));
	return res;
}

#endif