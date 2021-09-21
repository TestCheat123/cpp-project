#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "fileloader.h"
#include "DataStruct.h"
#pragma warning(disable : 4996)


int main()
{
	file mass;
	datetime d;
	mass.fileread();
	d.showSysDateTime();
	for (int i = 1; i <= mass.val; i++) {
		d.get(mass.date, i);
		d.nDataS();
		d.pDataS();
		d.showall();
	}
	std::cout << std::endl << "Next date next month" << std::endl;
	for (int i = 1; i <= mass.val; i++) {
		d.get(mass.date, i);
		d.nDataS();
		d.pDataS();
		d.showNextMon();
	}
	
	mass.deletedata();
}
