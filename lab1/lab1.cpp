#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "fileloader.h"
#include "DataStruct.h"



int main()
{
	file mass;
	datetime d;
	mass.fileread();
	for (int i = 1; i <= mass.val; i++) {
		d.get(mass.date, i);
		d.nDataS();
		d.pDataS();
		d.showall();
	}
	
	mass.deletedata();
}
