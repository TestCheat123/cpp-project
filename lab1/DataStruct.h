#pragma once

class Data {
public:
	int sec = 0;
	int min = 0;
	int hour = 0;
	int days = 0;
	int month = 0;
	int year = 0;
	Data();
};

class Datetime
{
	friend class UI;
private:		
	Data data;
	Data nData;
	Data pData;
	int number;

public:
	void nDataS();
	void pDataS();
	void getData(int** date, int num);
	Datetime();
	~Datetime();
};

