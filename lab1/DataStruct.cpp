#include "DataStruct.h"
#include <iostream>

void datetime::show(struct Data data, struct nData ndata, struct pData pdata, int number) {
	std::cout << "\t" << number << "\t" << data.days << "."
										<< data.month << "."
										<< data.year << "	" 
										<< data.hour << ":"
										<< data.min << ":"
										<< data.sec << /*"\t" <<  << "\t" <<  <<*/ std::endl;
}

void datetime::nextdate() {

}