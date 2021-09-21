#pragma once

class datetime
{
private:
	struct Data {
		int sec = 0;
		int min = 0;
		int hour = 0;
		int days = 0;
		int month = 0;
		int year = 0;
	};	

	Data data;
	Data ndata;
	Data pdata;
	int number;
	int **sysDateTime;

public:
	void showSysDateTime();
	void show(struct Data dat);
	void showall();
	void nDataS();
	void pDataS();
	void get(int** date, int num);
	void showNextMon();
};

