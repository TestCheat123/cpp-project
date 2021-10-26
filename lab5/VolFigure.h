#pragma once
#include "Figure.h"
class VolFigure
{
public:
	virtual double CalcVolume() = 0;
};

class Cylinder : public VolFigure {
private:
	double square;
	double height;
public:
	Cylinder() { square = 1; height = 1; };
	Cylinder(double S, double H);
	Cylinder(Figure *figure, double H);
	virtual double CalcVolume();
};