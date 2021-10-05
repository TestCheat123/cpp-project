#pragma once
#include "DataStruct.h"

class UI
{
private:
	void ShowDateTimeInfo(class Data dat);
public:
	void ShowAllDateInfo(class Datetime Dat);
	void ShowDateFromNextMonth(class Datetime Dat);
	void ShowLocalDateTime();
};

