#include "DataStruct.h"


Data::Data() {
	days = 1;
	month = 1;
	year = 1970;
	min = 0;
	hour = 0;
	sec = 0;
}
Datetime::Datetime() {
	number = 0;
}
Datetime::~Datetime() {
}


void Datetime::getData(int **date, int num) {
	number = num;
	data.days = date[0][number - 1];
	data.month = date[1][number - 1];
	data.year = date[2][number - 1];
	data.hour = date[3][number - 1];
	data.min = date[4][number - 1];
	data.sec = date[5][number - 1];

	pData.sec = data.sec;
	pData.min = data.min;
	pData.hour = data.hour;
	pData.hour = data.hour;
	pData.days = data.days;
	pData.month = data.month;
	pData.year = data.year;

	nData.sec = data.sec;
	nData.min = data.min;
	nData.hour = data.hour;
	nData.hour = data.hour;
	nData.days = data.days;
	nData.month = data.month;
	nData.year = data.year;

}





void Datetime::nDataS() {
	
	if (data.month == 1 || data.month == 3 || data.month == 5 || data.month == 7 || data.month == 8 || data.month == 10 || data.month == 12) {
		if (data.days == 31) {
			if (data.month == 12) {
				nData.month = 1;
				nData.year++;
			}
			else {
				nData.month++;
			}
			nData.days = 1;
		}
		else {
			nData.days++;
		}
		return;
	}
	else
	{
		if (data.days == 30) {
			nData.month++;
			nData.days = 1;
		}
		else {
			nData.days++;
		}
		return;
	}

	if (data.month == 2) {
		if (data.year % 4 == 0) {
			if (data.days == 29) {
				nData.month = 3;
				nData.days = 1;
			}
			else {
				nData.days++;
			}
			return;
		}
		else {
			if (data.days == 28) {
				nData.month = 3;
				nData.days = 1;
			}
			else {
				nData.days++;
			}
			return;
		}
		
	}

}

void Datetime::pDataS() {
	
	if (data.month == 1 || data.month == 3 || data.month == 5 || data.month == 7 || data.month == 8 || data.month == 10 || data.month == 12) {
		if (data.days == 1) {
			if (data.month == 3) {
				if (data.year % 4 == 0) {
					pData.month--;
					pData.days = 29;
				}
				else {
					pData.month--;
					pData.days = 28;
				}
			}
			else {
				if (data.month == 12) {
					pData.month = 1;
					pData.year--;
					pData.days = 30;
				}
				else {
					pData.month--;
					pData.days = 30;
				}
			}
			
		}
		else {
			pData.days--;
		}
	}
	else {
		if (data.days == 1) {
			pData.month--;
			pData.days = 30;
		}
		else {
			pData.days--;
		}
	}
}