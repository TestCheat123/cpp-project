#pragma once

struct datetime
{
	struct Data {
		int sec;
		int min;
		int hour;
		int days;
		int month;
		int year;
	};
	struct nData {
		int sec;
		int min;
		int hour;
		int days;
		int month;
		int year;
	};
	struct pData {
		int sec;
		int min;
		int hour;
		int days;
		int month;
		int year;
	};
	


	void show(struct Data data, struct nData ndata, struct pData pdata, int number);
	void nextdate();
};

