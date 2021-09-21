#include "DataStruct.h"
#include <iostream>
#pragma warning(disable : 4996)

void datetime::showSysDateTime() {
	time_t now = time(0);
	tm* ltm = localtime(&now);
	sysDateTime = new int* [6];
	for (int i = 0; i < 6; i++) {
		sysDateTime[i] = new int[1];
	}
	sysDateTime[0][0] = ltm->tm_mday;
	sysDateTime[1][0] = 1 + ltm->tm_mon;
	sysDateTime[2][0] = 1970 + ltm->tm_year;
	sysDateTime[3][0] = 1 + ltm->tm_hour;
	sysDateTime[4][0] = 1 + ltm->tm_min;
	sysDateTime[5][0] = 1 + ltm->tm_sec;

	get(sysDateTime, 1);
	std::cout << "Local date and time: " << std::endl;
	show(data);
	std::cout << std::endl << std::endl;

	for (int i = 0; i < 1; i++) {
		delete[] sysDateTime[i];
	}
	delete[] sysDateTime;
}

void datetime::showNextMon() {
	if (data.month < ndata.month) showall();
}

void datetime::get(int **date, int num) {
	number = num;
	data.days = date[0][number - 1];
	data.month = date[1][number - 1];
	data.year = date[2][number - 1];
	data.hour = date[3][number - 1];
	data.min = date[4][number - 1];
	data.sec = date[5][number - 1];

	pdata.sec = data.sec;
	pdata.min = data.min;
	pdata.hour = data.hour;
	pdata.hour = data.hour;
	pdata.days = data.days;
	pdata.month = data.month;
	pdata.year = data.year;

	ndata.sec = data.sec;
	ndata.min = data.min;
	ndata.hour = data.hour;
	ndata.hour = data.hour;
	ndata.days = data.days;
	ndata.month = data.month;
	ndata.year = data.year;

}

void datetime::show(struct Data dat) {
	std::cout << "Date: " << dat.days << "."
					  << dat.month << "."
					  << dat.year << "  Time: "
					  << dat.hour << ":"
					  << dat.min << ":"
					  << dat.sec;
}

void datetime::showall(){ 
std::cout << " " << number << ": "; show(data); std::cout <<"\tNext "; show(ndata); std::cout << "\tPrevious "; show(pdata); std::cout << " " << std::endl;
}

void datetime::nDataS() {
	
	if (data.month == 1 || data.month == 3 || data.month == 5 || data.month == 7 || data.month == 8 || data.month == 10 || data.month == 12) {
		if (data.days == 31) {
			if (data.month == 12) {
				ndata.month = 1;
				ndata.year++;
			}
			else {
				ndata.month++;
			}
			ndata.days = 1;
		}
		else {
			ndata.days++;
		}
		return;
	}
	else
	{
		if (data.days == 30) {
			ndata.month++;
			ndata.days = 1;
		}
		else {
			ndata.days++;
		}
		return;
	}

	if (data.month == 2) {
		if (data.year % 4 == 0) {
			if (data.days == 29) {
				data.month = 3;
				data.days = 1;
			}
			else {
				data.days++;
			}
			return;
		}
		else {
			if (data.days == 28) {
				data.month = 3;
				data.days = 1;
			}
			else {
				data.days++;
			}
			return;
		}
		
	}

}

void datetime::pDataS() {
	
	if (data.month == 1 || data.month == 3 || data.month == 5 || data.month == 7 || data.month == 8 || data.month == 10 || data.month == 12) {
		if (data.days == 1) {
			if (data.month == 3) {
				if (data.year % 4 == 0) {
					pdata.month--;
					pdata.days = 29;
				}
				else {
					pdata.month--;
					pdata.days = 28;
				}
			}
			else {
				if (data.month == 12) {
					pdata.month == 1;
					pdata.year--;
					pdata.days == 30;
				}
				else {
					pdata.month--;
					pdata.days = 30;
				}
			}
			
		}
		else {
			pdata.days--;
		}
	}
	else {
		if (data.days == 1) {
			pdata.month--;
			pdata.days = 30;
		}
		else {
			pdata.days--;
		}
	}
}