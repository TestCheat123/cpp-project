#include "fileloader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void file::fileread() {
	std::string line;
	std::fstream in("date.txt");
	//std::getline(in, line);
	if (in.is_open()) {
		while (std::getline(in, line))
		{
			val++;
		}
	}

	

	date = new int* [6];
	for (int i = 0; i < 6; i++) {
		date[i] = new int[val];
	}

	in.clear();
	in.seekg(0, std::ios::beg);

	std::string d;
	if (in.is_open()) {
		int i = 0;
		int j = 0;
		while (std::getline(in, d)) {
			std::istringstream ss(d);
			while (ss >> date[0][j] >> date[1][j] >> date[2][j] >> date[3][j] >> date[4][j] >> date[5][j]) {
				j++;
			}

		}
	}
	else
	{
		std::cout << "File read error" << std::endl;
	}
	in.close();
}

void file::deletedata() {
	for (int i = 0; i < val; i++) {
		delete[] date[i];
	}
	delete[] date;
}

void file::datasort() {
	int temp1[6];	
	for (int i = 0; i < val; i++)
	{
		
	}
}