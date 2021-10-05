#include "UI.h"
#include <iostream>
#pragma warning(disable : 4996)

void UI::ShowDateTimeInfo(class Data dat) {
	std::cout << "Date: " << dat.days << "."
		<< dat.month << "."
		<< dat.year << "  Time: "
		<< dat.hour << ":"
		<< dat.min << ":"
		<< dat.sec;
}

void  UI::ShowAllDateInfo(class Datetime Dat) {
	std::cout << " " << Dat.number << ": "; ShowDateTimeInfo(Dat.data); std::cout << "\tNext "; ShowDateTimeInfo(Dat.nData); std::cout << "\tPrevious "; ShowDateTimeInfo(Dat.pData); std::cout << " " << std::endl;

}
void UI::ShowDateFromNextMonth(class Datetime Dat) {
	if (Dat.data.month < Dat.nData.month) ShowAllDateInfo(Dat);
}
void UI::ShowLocalDateTime() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	Data dat;
	dat.days = ltm->tm_mday;
	dat.month = 1 + ltm->tm_mon;
	dat.year = 1970 + ltm->tm_year;
	dat.hour = 1 + ltm->tm_hour;
	dat.min = 1 + ltm->tm_min;
	dat.sec = 1 + ltm->tm_sec;
	std::cout << "Local date and time: " << std::endl;
	ShowDateTimeInfo(dat);
	std::cout << std::endl << std::endl;
}