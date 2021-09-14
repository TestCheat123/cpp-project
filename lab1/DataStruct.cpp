#include "DataStruct.h"
#include <iostream>



void datetime::show(int number) {
	std::cout << "\t" << number << "\t" << days << "."
										<< month << "."
										<< year << "	" 
										<< hour << ":"
										<< min << ":"
										<< sec << /*"\t" <<  << "\t" <<  <<*/ std::endl;
}