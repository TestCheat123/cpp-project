#pragma once
class Figure
{
public:
	virtual double CalcSquare() = 0;
	virtual double CalcPerimetr() = 0;
	virtual	Figure * Clone() = 0;
};

class Triangle : public Figure
{
private:
	double a;
	double b;
	double c;

public:
	Triangle();
	virtual double CalcSquare();
	virtual double CalcPerimetr();
	virtual 
};

class Circle : public Figure {
private:
	double R;
public:
	Circle() {
		R = 3;
	};
	virtual double CalcSquare();
	virtual double CalcPerimetr();

};

class CustomFigure : public Figure {
private:
	double A;
	double B;
	double C;
	double R;
public:
	CustomFigure() {
		A = 3;
		B = 3;
		C = 3;
		R = 2;
	};
	virtual double CalcSquare();
};