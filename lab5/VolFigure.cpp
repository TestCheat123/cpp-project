#include "stdafx.h"
#include "VolFigure.h"

double Cylinder::CalcVolume() {
	return height * square;
}

Cylinder::Cylinder(double S, double height) {
	square = S;
	this->height = height;
}

Cylinder::Cylinder(Figure *figure, double H) {
	square = figure->CalcSquare();
	height = H;
}