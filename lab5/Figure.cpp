#include "stdafx.h"
#include "Figure.h"
#include <math.h>
const double PI = 3.14;

double Triangle::CalcPerimetr() {
	return a + b + c;
}

double Triangle::CalcSquare() {
	double p = CalcPerimetr() / 2;
	return sqrt(p*(p - a)*(p - b)*(p - c));
}

double Circle::CalcPerimetr() {
	return 2 * R * PI;
}

double Circle::CalcSquare() {
	return PI * R * R;
}

Triangle::Triangle() {
	a = 1;
	b = 1;
	c = 1;
}

/*double CustomFigure::CalcSquare() {
	return 
}*/