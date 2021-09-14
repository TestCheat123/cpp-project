#pragma once

struct datetime
{
	int sec;
	int min;
	int hour;
	int days;
	int month;
	int year;

	void show(int number);
	void nextdate();
};

